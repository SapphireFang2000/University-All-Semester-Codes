prompt = 'Enter the sigma value: ';
sigma = input(prompt);

S = rgb2gray(imread('bean.jpg'));

% Define the 5x5 kernel
X = zeros(5,5);
Y = zeros(5,5);

for i = 1:5
    counter=-2;
    for j = 1:5
        X(i,j) = counter;
        Y(j,i) = counter;
        counter = counter+1;
    end
end

temp1 = 1/(2*pi*(sigma^2));
temp2 = (-((X.^2)+(Y.^2))/(2*(sigma^2)));
gauss = temp1*exp(temp2);

% Pad the image with zeros on the borders
[row, col] = size(S);
R = uint8(zeros(row+4,col+4));

row = row+4;
col = col+4;

R(3:row-2,3:col-2) = S;

T = R;

R = double(R);

% Apply the Gaussian filter using the 5x5 kernel
for i = 1:row-4
   for j = 1:col-4 
      N = R(i:i+4, j:j+4);
      t = sum(sum(N.*gauss)); 
      T(i+2,j+2) = t;
   end
end

figure; 
imshow(S);

F=uint8(T(3:row-2,3:col-2)); 

figure;
imshow(F, [min(F(:)), max(F(:))]);
