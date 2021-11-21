% NE 451 Assignment 8 Problem 1
% 2021-11-20
% Kaylie Choi - 20692499

% values of t = 0,1,...63
t = [ 0 : 63 ];
% signal 
y = sin( 30 * pi * t / 64 ) + sin( 4 * pi * t / 64 );

% eliminate high frequency components of signal

% 1. fast fourier transform of signal
fftY = fft(y);
subplot( 2, 2, 1 );
plot (real(fftY));
title('Real Part of FFT of Input Signal')  
subplot( 2, 2, 2 );
plot (imag(fftY));
title('Imaginary Part of FFT of Input Signal')  


% 2. apply filter in fourier domain
% order frequency and apply Hamming window function raised to 5th power
hammingFilter = fftshift( hamming( 64 ).' ).^ 5;
subplot( 2, 2, 3 );
plot (hammingFilter);
title('Shifted Filter Function')  

fftYFilter = fftY .* hammingFilter;
subplot( 2, 2, 4 );
plot (abs(fftYFilter));
title('Magnitude of Filtered FFT Input Signal')  


% 3. inverse fast fourier transform
filteredY = ifft(fftYFilter); 

figure();
plot( real(filteredY) );
title('Filtered and Original Input Signal');
hold on; 
plot(y, 'r');
legend('Filtered signal', 'Input signal');

