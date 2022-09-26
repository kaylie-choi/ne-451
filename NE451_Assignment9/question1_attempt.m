clc, clear, close all

% define algorithm parameters
numSteps = 40;
numRealizations = 100000;
kTInitial = 5;
kTFinal = 0.5;
centralPoint = numSteps+1;



% first steps in Markov chain
for loop = 1:numSteps+1
    randOld(loop) = 2 * round(rand) - 1;
end


% final position of walk
posOld  = centralPoint;
for loop = 1:numSteps
    posOld = posOld + randOld(loop);
end


% perform random walk
for outerLoop = 1:numRealizations
    
    % decrease temperature linearly
    kT = kTInitial + (kTFinal - kTInitial) / numRealizations * outerLoop;
    
    
    % reverse the value at a random position
    for innerLoop = 1:numSteps
        randNew(innerLoop) = randOld(innerLoop);
    end
    
    flipPosition = fix(rand * numSteps) + 1;
    randNew(flipPosition) = randNew(flipPosition) * -1;
    
    
    % calculate new random walk
    posNew = centralPoint;
    for innerLoop = 1:numSteps
        posNew = posNew + randNew(innerLoop);
    end
    
    
    % accept or reject transition using the Metropolis condition
    if (rand < (exp(abs(posNew - centralPoint) - abs(posOld - centralPoint)) / kT))
        posOld = posNew;
        randOld(flipPosition) = randOld(flipPosition) * -1; 
    end
    
    

end

disp("Final configuration of steps: ")
disp(randNew)
disp("Final endpoint: ")
disp(posNew)