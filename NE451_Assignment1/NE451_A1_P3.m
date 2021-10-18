% Sept 27 2021
% Kaylie Choi
% NE 451 Assignment 1 Problem 3

vR = [];
for i = 1:100
% random 100x100 matrix
x = randi(1000, 100);
abs_eigen_vals = abs(eig(x));
% vectorize expression, saving all values in a single 10000 row vector
abs_eigen_vals = abs_eigen_vals(:)';
vR = [vR abs_eigen_vals];
end
subplot(2, 1, 1), hist(vR, 200), title('Uniform Distribution')

vR = [];
for i = 1:100
x = randn(100);
abs_eig_vals = abs(eig(x));
abs_eig_vals = abs_eig_vals(:)';
vR = [vR abs_eig_vals];
end
subplot(2, 1, 2), hist(vR, 200), title('Gaussian Distribution')