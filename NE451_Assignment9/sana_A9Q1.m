numberOfRealizations = 100000;
numberOfSteps = 40; 
kTInitial = 5; 
kTFinal = 0.5; 

histogramR = zeros( 1, numberOfSteps + 1 );
stepSequenceR = round( rand( 1, numberOfSteps ) ); 
histogramIndex = sum( stepSequenceR ) + 1; 
centralPoint = numberOfSteps / 2; 

for loop = 1 : numberOfRealizations
    flipPosition = fix( rand * numberOfSteps ) + 1; 
    stepSequenceR(flipPosition) = 1 - stepSequenceR(flipPosition); 
    histogramIndexNew = sum( stepSequenceR ) + 1; 
    KT = kTInitial + (kTFinal - kTInitial)/ numberOfRealizations * loop; %letting kT vary linearly  
    
    %replacing B with 1/KT
    if rand < exp( ( abs( histogramIndexNew - centralPoint ) - abs( histogramIndex - centralPoint ) ) /KT ) 
        histogramIndex = histogramIndexNew; 
    else 
        stepSequenceR(flipPosition) = 1 - stepSequenceR(flipPosition);
    end
    histogramR(histogramIndex) = histogramR(histogramIndex) + 1; 
end  

disp (stepSequenceR)  %this is the final configuration of steps 
disp (sum(stepSequenceR)) %this is the number of 1's 
histogramR = histogramR .* exp( - 1/kT * ...
    abs( (1 : numberOfSteps + 1) - centralPoint ) );
xScaleR = 2 * ( 0 : numberOfSteps ) - numberOfSteps; 
semilogy( xScaleR, histogramR / sum( histogramR ) );