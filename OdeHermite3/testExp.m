clf;

tEnd = 10;
alpha = 0.5;
dt = 2;
% %%% For Exp:
% u = 1;
% lam = -0.2;
% fRHS = @(u) u * lam;
% fJacobian = @(u) lam;
% fdTau = @(u) 1e300/abs(lam);
% uAna = u * exp(lam * tEnd);

% %%% For Sine:
% u = [1;0];
% K = 1;
% fRHS = @(u) [u(2); -K * u(1)];
% fJacobian = @(u) [0,1;-K,0];
% fdTau = @(u) ones(2,1) * 1e-1 / sqrt(K);
% uAna = [cos(tEnd * sqrt(K)); -sqrt(K) * sin(tEnd * sqrt(K))]
% tEndM = tEnd - dt * (1-alpha);
% uAnaM = [cos(tEndM * sqrt(K)); -sqrt(K) * sin(tEndM * sqrt(K))];

%%% For vdp
% u = [2;0];
% K = 10;
% fRHS = @(y) [y(2); K * (1-y(1)^2)*y(2)-y(1)];
% fJacobian = @(y) [0, 1; K*(-y(1)*2)*y(2)-1, K*(1-y(1)^2) ];
% fdTau = @(u) ones(2,1) * 1000;
% uAna = u;
% uAnaM = u;

%%% For Landau
u = [0.1];
K = 1;
fRHS = @(y) [K * (y - y.^2)];
fJacobian = @(y) [K * (1 - 2 * y)];
fdTau = @(u) ones(1,1) * 1000;
uAna = u;
uAnaM = u;


ts = 0:dt:tEnd;
assert(ts(end) == tEnd)
us = nan(numel(u), numel(ts));
us(:,1) = u;

for i = 1:numel(ts) -1
    dtC = ts(i+1) - ts(i);
    [u, um] = ODE_HM3_InterSolve(u, fRHS, fJacobian, fdTau, dtC, alpha, 1);
    us(:, i + 1) = u;

end
plot(ts, us(1,:))
%%
err = norm(u - uAna)
errM = norm(um - uAnaM)