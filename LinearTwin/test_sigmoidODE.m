
AMorder = 2;

%% sigmoid problem
a = 10;

xana = @(t) 1./(1+exp(-a * t));
x0 = xana(-2);

frhs = @(t,x) (x - x.^2)*a;
frhs_jacobi = @(t,x) (1-2*x) * a;
tspan = [-2,2];

%% bench
figure(110);
options = odeset('Jacobian', frhs_jacobi,'InitialStep',1e-8,'MaxStep',1e-2,...
    'RelTol',1e-8,'AbsTol',1e-8);
[ts,xs] = ode15s(frhs, tspan, x0, options);
plot(ts,xs,'-o',ts,xana(ts));

%% AM
figure(111);
dt0 = 5e-1;


t = tspan(1);
x = x0;
rhsprev = cell(1,3);
dtprev = nan(1,3);
rhsprev{1} = frhs(0,x);
dtprev(1) = dt0;
niter = round((tspan(2) - tspan(1) )/ dt0);
ts = nan(1,niter);
xs = nan(1,niter);
for iter = 1:niter
    [xnew,dtprev, rhsprev] = ...
        odeAdamsMoultonFixed_CFLDamped(...
        x,@(xc) frhs(0,xc), @(xc) 1e15, @(xc) frhs_jacobi(0,xc),...
        dt0,...
        rhsprev,dtprev ,min(iter,AMorder-1));
    
    x = xnew;
    t = t + dt0;
    
    ts(iter) = t;
    xs(:,iter) = x;
end
plot(ts,xs,ts,xana(ts),'-.');

%% BDF

figure(112);


t = tspan(1);
x = x0;
rhsprev = cell(1,4);
dtprev = nan(1,4);
rhsprev{1} = x;
dtprev(1) = dt0;
niter = round((tspan(2) - tspan(1) )/ dt0);
ts = nan(1,niter);
xs = nan(1,niter);
for iter = 1:niter
    [xnew,dtprev, rhsprev] = ...
        odeBDFFixed_CFLDamped(...
        x,@(xc) frhs(0,xc), @(xc) 1e15, @(xc) frhs_jacobi(0,xc),...
        dt0,...
        rhsprev,dtprev ,min(iter,AMorder));
    
    x = xnew;
    t = t + dt0;
    
    ts(iter) = t;
    xs(:,iter) = x;
end
plot(ts,xs,ts,xana(ts),'-.');
