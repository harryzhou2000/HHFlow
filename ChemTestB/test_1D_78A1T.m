clear;
%%
N = 100;
see = 10;
uEst = 600;
CFLest = 0.01;


G.xs = linspace(0,1,N+1);
G.hc = G.xs(2:end) - G.xs(1:end-1);
G.xc = 0.5 * (G.xs(2:end) + G.xs(1:end-1));
G.ithis = 1:N;
G.iLeft = circshift(G.ithis,1);
G.iRight = circshift(G.ithis,-1);
G.hLeft = G.xc - G.xc(G.iLeft);
G.hRight = G.xc(G.iRight) - G.xc;
G.hmax = max(G.hc);
dt = CFLest * G.hmax / uEst;
niter = round(1/uEst/dt);

chemData7_8M;
M.names = names;
M.asA = asA; M.asB = asB;
M.Ctri = Ctri; M.Ntri = Ntri;
M.nub = nub; M.nuf = nuf;
M.Ms = Ms;
M.ABCABC = ABCABC;
%%
rhoA = 1;
vxA = 0;
TA = 1000;
YA = Ms.*([2 1 0 0 0 0 7]');
YA = YA/sum(YA);

rhoYA = rhoA * YA;
EA = rhoA .* (f_ustatic_fit(rhoA,TA,YA,M.Ms,M.asA,M.asB) + vxA.^2 * 0.5);

uA = [rhoA;rhoA.*vxA; rhoA*0;EA;rhoYA(1:end-1,:)];
gM1A = f_gammM1_fit(rhoA,TA,YA,M.Ms,M.asA,M.asB);
pA = f_DaltonPressureSum(rhoA,YA,M.Ms,TA);
aA = sqrt((gM1A+1) .* pA./rhoA);

%%
ns = numel(names);
u0 = uA*ones(1,N);
T0 = TA*ones(1,N);
dudt0 = frhs(u0,T0,G,M);

u = u0;
T = T0;

%%
t = 0;
for iter = 1:niter
    
    
    [dudt,T] =  frhs(u,T,G,M);
    u1 = u + dudt * dt;
    [dudt1,T] = frhs(u1,T,G,M);
    unew = 0.5 * u + 0.5 * u1 + 0.5 * dudt * dt;
    
    u = unew;
    t = t+dt;
    if mod(iter,see) == 0
        Ys = f_getYs(u);
        plot(G.xc, Ys);
        title(sprintf("t=%f",t));
        drawnow;
        
    end
    
end


function [dudt,T] = frhs(u,T,G,M)
dudxLe = (u - u(:,G.iLeft))./G.hLeft;
dudxRi = -(u - u(:,G.iRight))./G.hRight;
dudxC = F_TVD_Slope(dudxLe,dudxRi);

Ys = f_getYs(u);

[T,p, stat] = f_solveT_fit(T,Ys,u,M.Ms,M.asA, M.asB);

dTdxLe = (T - T(:,G.iLeft))./G.hLeft;
dTdxRi = -(T - T(:,G.iRight))./G.hRight;
dTdxC = F_TVD_Slope(dTdxLe,dTdxRi);

TLe = T - dTdxC .* G.hc * 0.5;
TRi = T + dTdxC .* G.hc * 0.5;
uLe = u - dudxC .* G.hc * 0.5;
uRi = u + dudxC .* G.hc * 0.5;

fLe_TRi = TLe;
fLe_uRi = uLe;
fLe_TLe = TRi(:,G.iLeft);
fLe_uLe = uRi(:,G.iLeft);

fLe_YsLe = f_getYs(fLe_uLe);
fLe_YsRi = f_getYs(fLe_uRi);

fLe_pLe = f_DaltonPressureSum(fLe_uLe(1,:),fLe_YsLe,M.Ms,fLe_TLe);
fLe_pRi = f_DaltonPressureSum(fLe_uRi(1,:),fLe_YsRi,M.Ms,fLe_TRi);
fLe_uM = (fLe_uLe + fLe_uRi) * 0.5;
fLe_TM = (fLe_TLe + fLe_TRi) * 0.5;
fLe_YsM = f_getYs(fLe_uM);
fLe_gammaM = f_gammM1_fit(fLe_uM(1,:), fLe_TM, fLe_YsM, M.Ms, M.asA, M.asB);

fLe_fluxInv = F_RoeSolver2_G(fLe_uLe,fLe_uRi,fLe_pLe,fLe_pRi, fLe_gammaM);

% viscous part:
% !! using constant dissipation coefficients now!

fLe_mu = 1e-3; %total vis
fLe_eta = 1e-3; %total cond
Sc = 0.5;
Xs = f_getXs(Ys, M.Ms);
fLe_rhoDs = ((1-fLe_YsM) .* fLe_mu) ./ ((1 - Xs) * Sc);

fLe_dudx = 0.5 * (dudxC + dudxC(:,G.iLeft));
fLe_dTdx = 0.5 * (dTdxC + dTdxC(:,G.iLeft));

fLe_hs = f_fitAbsoluteHeat(fLe_TM,M.asA,M.asB);


fLe_fluxVis = F_VisFlux_G(fLe_uLe, fLe_dudx, zeros(size(u)),...
    fLe_dTdx, fLe_YsM, M.Ms, fLe_hs, fLe_mu, fLe_eta,fLe_rhoDs);

fLe_flux = fLe_fluxVis - fLe_fluxInv;

% chem
kf = f_kArrhenius(M.ABCABC(:, 1:3),T);
kb = f_kArrhenius(M.ABCABC(:, 4:6),T);
rhoYs = u(1,:) .* Ys;
ns = rhoYs./M.Ms;
omega_chem = f_oNChem(ns, kf, kb, M.nuf, M.nub, M.Ctri, M.Ntri) .* M.Ms;

source = zeros(size(u));
source(5:end,:) = omega_chem(1:end-1,:);


dudt = source + ...
    -fLe_flux + fLe_flux(:, G.iRight);


end


