tEnd = 10;

gForce = @(t,w) [0;sin(w * t)];
gForceI = @(t,w) [0;-1/w*cos(w * t)];

gForce = @(t,w) [cos(w * t);0];
gForceI = @(t,w) [1/w*sin(w * t);0]; % second form


j = @(w) [0, 1; -w^2, 0];

r = @(u,w) j(w) * u;

wL = 2 * pi;
wH = 3.121e1 * pi;
aF = 8000;
aF = aF / wH;
K = aF / (-wH^2 + wL^2);
K = -aF / (-wH^2 + wL^2)*wH;% second form
u0 = [0; wL + K * wH];
u0 = [0; wL + K * wH - aF];% second form
fAna = @(t) [sin(wL*t) + K * sin(wH*t); wL * cos(wL*t) + K * wH * cos(wH*t)];
fAna = @(t) [sin(wL*t) + K * sin(wH*t); wL * cos(wL*t) + K * wH * cos(wH*t) - aF*cos(wH*t)];
tSamp = linspace(0,tEnd, 10001);
fAnaSamp = fAna(tSamp);
%%
options = odeset("Jacobian", @(t,y) j(wL));
[tsm, usm] = ode15s(@(t,y) r(y,wL) + aF * gForce(t, wH), [0,tEnd], u0, options);
plot(tsm,usm(:,1), tSamp, fAnaSamp(1,:))
%%
method = 1; % 1=HM3-forced 2=ESDIRK4-forced 3=HM3+Strang 4=ESDIRK4+Strang

Nt = 40 * 1;
dt = tEnd / Nt;
ts = nan(Nt,1);
us = nan(2,Nt);
t = 0;
u = u0;
for is = 1:Nt
    switch method
        case 1
            u = odeHermite3_CFLDamped_Forced(u, @(u,ct) r(u,wL), @(u) [1;1]/wL * 100, @(u) j(wL), ...
                @(ct) aF * gForceI(t + ct * dt, wH) - aF * gForceI(t, wH), dt, 0.5, 0, 6);
        
        case 2
             u = odeSDIRK4_CFLDamped_Forced(u, @(u,ct) r(u,wL), @(u) [1;1]/wL * 100, @(u) j(wL), ...
                @(ct) aF * gForceI(t + ct * dt, wH) - aF * gForceI(t, wH), dt, 2);
        
        case 3
            u = u + aF * gForceI(t + dt/2, wH) - aF * gForceI(t, wH);
            u = odeHermite3_CFLDamped_Forced(u, @(u,ct) r(u,wL), @(u) [1;1]/wL * 100, @(u) j(wL), ...
                @(ct) 0, dt, 0.5, 0, 6);
            u = u + aF * gForceI(t + dt, wH) - aF * gForceI(t+dt/2, wH);
        
        case 4
            u = u + aF * gForceI(t + dt/2, wH) - aF * gForceI(t, wH);
            u = odeSDIRK4_CFLDamped_Forced(u, @(u,ct) r(u,wL), @(u) [1;1]/wL * 100, @(u) j(wL), ...
                @(ct) 0, dt, 2);
            u = u + aF * gForceI(t + dt, wH) - aF * gForceI(t+dt/2, wH);
        otherwise
            error("no such method")
    end

   


    t = dt + t;
    ts(is) = t;
    us(:,is) = u;
end
fAnaSampC = fAna(ts');
plot(ts, us(1,:), '-o', tSamp, fAnaSamp(1,:));
legend("Numerical", "Analytical", "Location","best");
err = norm(fAnaSampC(1,:) - us(1,:),1) / Nt;

fprintf("err= %.2e\n",err);






