

tEnd = 10;

% %%% For Exp:
% u = 1;
% lam = -0.2;
% fRHS = @(u) u * lam;
% fJacobian = @(u) lam;
% fdTau = @(u) 1e300/abs(lam);
% uAna = u * exp(lam * tEnd);

% %%% For Sine:
u = [1;0];
K = 1;
fRHS = @(u) [u(2); -K * u(1)];
fJacobian = @(u) [0,1;-K,0];
fdTau = @(u) ones(2,1) * 1e10 / sqrt(K);
uAna = [cos(tEnd * sqrt(K)); -sqrt(K) * sin(tEnd * sqrt(K))];


dt = 1/1;
ts = 0:dt:tEnd;
assert(ts(end) == tEnd)
us = nan(numel(u), numel(ts));
us(:,1) = u;

for i = 1:numel(ts) -1
    dtC = ts(i+1) - ts(i);
    u = ODE_HM3_InterSolve(u, fRHS, fJacobian, fdTau, dtC, 0.5);
    us(:, i + 1) = u;

end
plot(ts, us(1,:))
%%
err = norm(u - uAna)