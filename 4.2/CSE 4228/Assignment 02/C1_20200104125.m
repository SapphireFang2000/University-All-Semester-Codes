I = imread('pollen.jpg');

input = I;
I = im2double(I);

A = min(I(:));
B = max(I(:));
D = B - A;
M = 255;

R = I - A;
R = R ./ D;
R = R .* M;
R = R + A;

R = uint8(R);

figure;

subplot(2, 2, 1);
imshow(input);
title('Input Image');

subplot(2, 2, 2);
imshow(R);
title('Output Image');
