function F = F_VisFlux_G(u,dudx, dudy, dTdx, Ys, Ms, hs, mu,eta,rDs)

drhodx = dudx(1,:);
drhody = dudy(1,:);
rho = u(1,:);
v = u(2:3,:);
drhoYsdx = [dudx(5:end,:);dudx(1,:) - sum(dudx(5:end,:),1)];
dYsdx = drhoYsdx./rho - (drhodx .* Ys)./rho;

dvdx = dudx(2:3,:)./rho - (drhodx .* v)./rho;
dvdy = dudy(2:3,:)./rho - (drhody .* v)./rho;



S11 = dvdx(1,:); S22 = dvdy(2,:);
S12 = 0.5 * (dvdx(2,:) + dvdy(1,:));
Strace = S11 + S22;

taumu11 = S11 * 2 .* mu - Strace * (2./3.) .* mu;
taumu12 = S12 * 2 .* mu;

F = 0 * u;
F(2:3,:) = [taumu11;taumu12];
F(4,:) = taumu11.*v(1,:) + taumu12.*v(2,:) + sum(rDs.*hs./Ms.*dYsdx,1) + ...
    eta.*dTdx;
FvisRhoYs = rDs.*dYsdx;
F(5:end,:) = FvisRhoYs(1:end-1,:);


