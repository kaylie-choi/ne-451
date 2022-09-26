% NE451 Assignment 9 Problem 1
% 2021-11-27
% Kaylie Choi - 20692499

numberOfRealizations = 100000;
numberOfSteps = 40;
kTInit = 5; 
kTFinal = 0.5; 
centralPoint = numberOfSteps + 1;

for loop = 1:numberOfSteps + 1
    oldRandom(loop) = 2 * round(rand) - 1;
end

oldPosition  = centralPoint;
for loop = 1:numberOfSteps
    oldPosition = oldPosition + oldRandom(loop);
end

for outerLoop = 1:numberOfRealizations
    kT = kTInit + (kTFinal - kTInit) / numberOfRealizations * outerLoop;
    
    for innerLoop = 1:numberOfSteps
        newRandom(innerLoop) = oldRandom(innerLoop);
    end
    
    flipPosition = fix(rand * numberOfSteps) + 1;
    newRandom(flipPosition) = newRandom(flipPosition) * -1;
    newPosition = centralPoint;
    
    for innerLoop = 1:numberOfSteps
        newPosition = newPosition + newRandom(innerLoop);
    end

    if (rand < (exp(abs(newPosition - centralPoint) - abs(oldPosition - centralPoint)) / kT))
        oldPosition = newPosition;
        oldRandom(flipPosition) = oldRandom(flipPosition) * -1; 
    end
end

disp("Final config of steps")
disp(newRandom)
disp("Final endpoint (number of ones) ")
disp(newPosition)
