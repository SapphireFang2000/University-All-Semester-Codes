%Step 1
A = imread('input.jpg');

[row,col,ch] = size(A);

if ch > 1
    A = rgb2gray(A);
end

%Step 2
LFilter = [0, 1, 0;
           1,  -4, 1;
           0, 1, 0];
       
T = zeros(row + 2, col + 2);

for i = 1:row
    for j = 1:col
        T(i+1,j+1) = A(i,j);
    end
end

B = zeros(row, col);

for i = 1:row
   for j = 1:col 
      N = T(i:i+2, j:j+2);
      t = LFilter .* N;  
      B(i,j) = sum(t(:));    
    end
end

%Step 3
C = double(A) - B;

%Step 4
Dx = zeros(row, col);
Dy = zeros(row, col);

SFilter_X = [ 1,  2,  1;
              0,  0,  0;
             -1, -2, -1];
SFilter_Y = [-1,  0,  1;
             -2,  0,  2;
             -1,  0,  1];

for i = 1:row
   for j = 1:col 
      N = T(i:i+2, j:j+2);
      t1 = SFilter_X .* N;
      t2 = SFilter_Y .* N;
      Dx(i,j) = sum(t1(:));
      Dy(i,j) = sum(t2(:));
    end
end

D = (Dx.^2 + Dy.^2).^0.5;

%Step 5
AvgFilter = ones(5);
AvgFilter = AvgFilter ./ sum(AvgFilter(:));
T = zeros(row + 4, col + 4);

for i = 1:row
    for j = 1:col
        T(i+2,j+2) = D(i,j);
    end
end

E = zeros(row, col);

for i = 1:row
   for j = 1:col 
      N = T(i:i+4, j:j+4);
      t = AvgFilter .* N;  
      E(i,j) = sum(t(:));    
    end
end

%Step 6
F = C .* E;

%Step 7
G = double(A) + F;

%Step 8
c = 1;
Ga = 0.5;
H = c .* (double(A) .^ Ga);

figure;
subplot(2, 4, 1);
imshow(A);
title('figure(a)');

subplot(2, 4, 2);
imshow(B,[]);
title('figure(b)');

subplot(2, 4, 3);
imshow(C,[]);
title('figure(c)');

subplot(2, 4, 4);
imshow(uint8(D));
title('figure(d)');

subplot(2, 4, 5);
imshow(uint8(E));
title('figure(e)');

subplot(2, 4, 6);
imshow(F,[]);
title('figure(f)');

subplot(2, 4, 7);
imshow(G,[]);
title('figure(g)');

subplot(2, 4, 8);
imshow(H,[]);
title('figure(h)');
