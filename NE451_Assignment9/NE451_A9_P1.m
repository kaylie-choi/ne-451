% NE451 Assignment 9 Problem 1
% 2021-11-27
% Kaylie Choi - 20692499

numberOfRealizations = 100000;
numberOfSteps = 40; 
kTInitial = 5; 
kTFinal = 0.5; 

% matlab from slides 
coinThrowsR = randi( 2, [ 1, numberOfThrows ] ) - 1; 
histogramIndex = sum( coinThrowsR ) + 1; 
centralPoint = numberOfThrows / 2 + 1;
histogramR = histogramR .* exp( - beta * abs([1 : numberOfThrows] - centralPoint ) );

for loop = 1 : numberOfRealizations
  flipPosition = randi( numberOfThrows, 1 ); 
  coinThrowsR(flipPosition) = 1 - coinThrowsR(flipPosition); 
  histogramIndexNew = sum( coinThrowsR ) + 1;
  
  if rand < exp( beta * ( abs( histogramIndexNew - centralPoint ) - abs( histogramIndex - centralPoint ) ) ) 
    histogramIndex = histogramIndexNew;
  else
    coinThrowsR(flipPosition) = 1 - coinThrowsR(flipPosition);
  end
  histogramR(histogramIndex) = histogramR(histogramIndex) + 1; 
end


