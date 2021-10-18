% Sept 27 2021
% Kaylie Choi
% NE 451 Assignment 1 Problem 1

% global variables
global K M;
K = 1;
M = 1;

% conditions
tspanR = [0 10];
x0R = [1, 0];

[tR_0, xRC_0] = ode23(@odefn_0, tspanR, x0R);
[tR_1, xRC_1] = ode23(@odefn_1, tspanR, x0R);
[tR_2, xRC_2] = ode23(@odefn_2, tspanR, x0R);
[tR_4, xRC_4] = ode23(@odefn_4, tspanR, x0R);

% plot each damped motion for corresponding values of gamma
figure(1)
plot(tR_0, xRC_0(:,1));
hold on;
plot(tR_1, xRC_1(:,1));
hold on;
plot(tR_2, xRC_2(:,1));
legend();
hold on;
plot(tR_4, xRC_4(:,1));
hold off;

legend('gamma = 0','gamma = 1', 'gamma = 2', 'gamma = 4');
xlabel('Time')
ylabel('Solution of function x')
title('Solution of Harmonic Oscillator for 4 values of gamma');


% set of coupled first order ODEs
% repeated for each gamma value
function du = odefn_0(t, x)
global K M;
gamma = 0;

du = zeros(2,1);
du(1) = x(2);
du(2) = -gamma * x(2) - (K/M) * x(1);
end

function du = odefn_1(t, x)
global K M;
gamma = 1;

du = zeros(2,1);
du(1) = x(2);
du(2) = -gamma * x(2) - (K/M) * x(1);
end

function du = odefn_2(t, x)
global K M;
gamma = 2;

du = zeros(2,1);
du(1) = x(2);
du(2) = -gamma * x(2) - (K/M) * x(1);
end

function du = odefn_4(t, x)
global K M;
gamma = 4;

du = zeros(2,1);
du(1) = x(2);
du(2) = -gamma * x(2) - (K/M) * x(1);
end
