img = imread('input.jpg');

flippedImg = img(end:-1:1, :, :);

mergedImg = [img; flippedImg];

imshow(mergedImg);

imwrite(mergedImg, 'output.jpg');
