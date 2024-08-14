I=imread('cameraman.png');

if size(I,3)>1
    I=rgb2gray(I);
end

J = I;
mx = max(I(:));

[row,col] = size(I);

L = 2^(floor(log2(double(mx)))+1);

hist1 = zeros(1,L);
CDF = zeros(1,L);

for i = 1:row
    for j = 1:col
        hist1(I(i,j)+1) = hist1(I(i,j)+1)+1;
    end
end

PDF = hist1/sum(hist1);
CDF(1) = PDF(1);

for i = 2:L
    CDF(i) = PDF(i)+CDF(i-1);
end

CDF = round(CDF*(L-1));

for i = 1:row
    for j = 1:col
        J(i,j) = CDF(I(i,j)+1);
    end
end

hist2 = zeros(1,L);

for i = 1:row
    for j = 1:col
        hist2(J(i,j)+1) = hist2(J(i,j)+1)+1;
    end
end

figure
subplot(2,2,1);
imshow(I);
title('Original Image');

subplot(2,2,2);
imshow(J);
title('Equalized Image');

subplot(2,2,3);
bar(hist1);
title('Original Image Histogram');

subplot(2,2,4);
bar(hist2);
title('Equalized Image Histogram');

