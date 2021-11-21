% A8 solution

% both these t's do the same thing 
% t = [ 0 : 63 ];
t = linspace(0, 63, 64);
y = sin( 30 * pi * t / 64 ) + sin( 4 * pi * t / 64 );

fy = fft( y );
myFilter = fftshift( hamming( 64 )' .^5 );

fyFilter = fy .* myFilter;
result = ifft( fyFilter );

plot(t, real(result), t, y, 'r');


