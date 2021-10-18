% Sept 27 2021
% Kaylie Choi
% NE 451 Assignment 1 Problem 2

xC = [1; 0; 0];
yC = [0; 1; 0];
LRC = -1i * [ 0 1 0; -1 0 0; 0 0 0 ];
sigma = pi / 2;

rotationxC = expm(-1i * sigma * LRC) * xC
rotationyC = expm(-1i * sigma * LRC) * yC
rotationLRC = expm(-1i * sigma * LRC)