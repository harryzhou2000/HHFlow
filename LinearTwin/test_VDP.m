tend = 400;

% omega =  2 * pi * 1.05;mu = 1;
% omega =  2 * pi * 1.63681;mu = 4;
omega =  2 * pi * 1;mu = 4;
h = 1;

u0 = 2;
v0  = 1;


    


vdp = @(t, y) [y(2);  mu*omega*(1- (y(1)/h)^2)*y(2) - omega^2* (y(1))];
y0 = [u0 v0];


N = 100;
tmaxS = 0;
for iter = 1:N

    
tspan = [0 tend];

options = odeset('RelTol',1e-8,'AbsTol',1e-7,'InitialStep',1e-4,...
    'Events',@(t,y)endVDP(t,y,y0(1),y0(2)));
sol = ode15s(vdp,tspan,y0, options);
y0 = sol.y(:,end)
tmax = sol.x(end)
if iter == N || iter == N-1
   tmaxS = tmaxS + tmax; 
end
cla;
plot(sol.x,sol.y(1,:),'o-');
drawnow;

end

omega = omega * tmaxS;
%%



vdp = @(t, y) [y(2);  mu*omega*(1- (y(1)/h)^2)*y(2) - omega^2* (y(1))];
options = odeset('RelTol',1e-8,'AbsTol',1e-7,'InitialStep',1e-4);
sol = ode15s(vdp,[0,1],y0, options);
cla;
plot(sol.x,sol.y(1,:),'o-');
fprintf('y0 = [%d, %d];\nomega=%g; mu=%g\nye=[%d,%d]\n\n',...
    y0(1),y0(2),omega,mu,sol.y(1,end),sol.y(2,end));
% x = linspace(0,tend,2500);
% y = deval(sol,x,1);


%%


function [v,ter,dir] = endVDP(t,y,u0,v0)
 v = y(1)-u0;
 ter=1;
 dir = -sign(v0);
end