T = 2000;

chemData7_8M;

kf = f_kArrhenius(ABCABC(:, 1:3),T);
kb = f_kArrhenius(ABCABC(:, 4:6),T);
K = kf./kb;
n0 = [0.6, 0.3,0,0,0,0,0.7]' * 4.4000;

oN0 = f_oNChem(n0,kf,kb,nuf,nub,Ctri,Ntri);

% fEqui = @(n) [f_oNChem(n,kf,kb,nuf,nub,Ctri,Ntri); (nuf-nub)*(n-n0)];
% neq = fsolve(fEqui, n0)
%% bench
options1 = odeset('NonNegative',1,'InitialStep', 1e-10, 'Jacobian', @(t,n) f_doNChem(n,kf,kb,nuf,nub,Ctri,Ntri),...
    'MaxStep', 1e2);
[t,ns] = ode15s(@(t, n) f_oNChem(max(n,0),kf,kb,nuf,nub,Ctri,Ntri), [0,1e-5],n0, options1);
plot(t,ns);
legend(names);
set(gca,'XScale','log');
xlim([1e-10, 1e-5]);
ylim([0,1e-1]);
%% Explicit
n = n0;
dt = 1e-10;
for i = 1:500000
    nprev = n;
    n = n + dt * f_oNChem(max(n,0),kf,kb,nuf,nub,Ctri,Ntri);
end
res = norm(f_oNChem(n,kf,kb,nuf,nub,Ctri,Ntri));
fprintf("rres - explicit %e\n", res/norm(oN0));
n


%% Implicit 
% n2- n1 = dt R(n2) approx n2 - n1 = dt (dR(n1) (n2 - n1) + R(n1) )
% (I - dt dR(n1)) dn = dt R(n1)
n = n0;
dt = 1e-6;
ns = n0';
ts = 0;
for i = 1:10
    nprev = n;
    f0 = f_oNChem(n,kf,kb,nuf,nub,Ctri,Ntri);
    dn = n * 0;
    for j = 1:1
        f = f_oNChem(n + dn,kf,kb,nuf,nub,Ctri,Ntri);
        L_RHS = dn - dt * f;
        if j == 1
           resin = norm(L_RHS); 
        end
        L_JACOBIAN = eye(numel(n)) - dt * f_doNChem(n + dn,kf,kb,nuf,nub,Ctri,Ntri);
        l = tril(L_JACOBIAN,-1);
        u = triu(L_JACOBIAN,1);
        d = diag(diag(L_JACOBIAN));
        dn = dn - L_JACOBIAN\L_RHS;
%         dn = ((d + l)\(-u*dn + L_RHS)) ;
    end
    
    n = n + dn;
    res = norm(f_oNChem(n,kf,kb,nuf,nub,Ctri,Ntri));
    fprintf("step %d rresin - implicit %e\n", i,norm(L_RHS)/resin);
    
    ns(end+1,:) = n';
    ts(end + 1) = i * dt;
end
fprintf("rres - implicit %e\n", res/norm(oN0));
n
plot(ts,ns);
legend(names);
%% Expoential
% n2- n1 = dt R(n2) approx n2 - n1 = dt (dR(n1) (n2 - n1) + R(n1) )
% (I - dt dR(n1)) dn = dt R(n1)
n = n0;
dt = 0.5e-8   ;
for i = 1:2000
    nprev = n;
    A =  f_doNChem(n,kf,kb,nuf,nub,Ctri,Ntri);
    f = f_oNChem(n,kf,kb,nuf,nub,Ctri,Ntri);
%     nnew = expm(A*dt) * n + lsqminnorm(A,((expm(A*dt) - eye(size(A))) * f));
    
% %     expm(A*dt) * n + A\(expm(A*dt) - eye(size(A))) * f + A\(expm(A*dt) - eye(size(A)))*A*dn = n + dn
    
%     rhs = expm(A*dt) * n + lsqminnorm(A,(expm(A*dt) - eye(size(A))) * f) - n;
%     jacobian = eye(size(A)) - lsqminnorm(A,(expm(A*dt) - eye(size(A)))*A);
%     nnew = n + lsqminnorm(jacobian,rhs);

% %     dn = (expm(A*dt) - eye(size(A))) * lsqminnorm(A,f) + dt * (f(dt) - f(0) - A*dn);
    jacobian = eye(size(A));
    rhs =  (expm(A*dt) - eye(size(A))) * lsqminnorm(A,f);
    nnew = n + jacobian\rhs;
    n = nnew;
    res = norm(f_oNChem(n,kf,kb,nuf,nub,Ctri,Ntri));
end
fprintf("rres - explicit %e\n", res/norm(oN0));
n

