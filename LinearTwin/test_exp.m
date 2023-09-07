
clear;
u = 1;
dt = 1e-1/2;
n = round(1/dt);
LAM = 1;
u0 = u;

for iter = 1:n

 u = odeHermite3_CFLDamped(u, @(u) u * LAM, @(u) 1e100, @(u) LAM, dt, 0.6, 0, 1);
 
 
end

err = abs(u - u0 * exp(LAM * n * dt))