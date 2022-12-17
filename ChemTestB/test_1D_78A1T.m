% clear;

% runMode = 0; % 0 for matlab, 1 for mex, 2 for mex + gpu
%%
N = 2000;
see = 100;
uEst = 1000;
CFLest = 0.05;
tmax = 0.2;

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
niter = round(tmax/uEst/dt);

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
TA = 300;
YA = Ms.*([2 1 0 0 0 0 7]');
YA = YA/sum(YA);
[uA,aA] = f_ruty2cons(rhoA, vxA, TA, YA, M);
[uB,aB] = f_ruty2cons(rhoA, vxA, TA * 7, YA, M);

%%
ns = numel(names);
u0 = uA*ones(1,N);
T0 = TA*ones(1,N);


rg1 = G.ithis( G.xc > 0.4 & G.xc < 0.6);
u0(:,rg1) = uB * ones(1,numel(rg1));


dudt0 = frhs(u0,T0,G,M);
u = u0;
T = T0;


%%
t = 0;
figure(1);
clf;f1 = gca;
figure(2);
clf;f2 = gca;

for iter = 1:niter
    
    % Method: inserted Crank-Nicolson
    duS1 = fsimple_implicit_sourcedt(u,T,G,M,dt);
    duS2 = fsimple_implicit_sourcedt(u+duS1,T,G,M,dt);
    S1  = frhs_source(u + duS1,T,G,M);
    S2  = frhs_source(u + duS1 + duS2,T,G,M);
    u_m0 = u + duS1 + duS2;
    [T,p, stat] = f_solveT_fit(T,f_getYs(u_m0),u_m0,M.Ms,M.asA, M.asB);
    dudt =  frhs(u_m0,T,G,M);
    u_m1 = u_m0 + dudt * dt;
    [T,p, stat] = f_solveT_fit(T,f_getYs(u_m1),u_m1,M.Ms,M.asA, M.asB);
    dudt1 = frhs(u_m1,T,G,M)  + (- S2 + frhs_source(u_m1,T,G,M)) * 0;
    unew = 0.5 * u_m0 + 0.5 * u_m1 + 0.5 * dudt1 * dt;
    
    if(~isreal(unew))
        error('complex!');
    end
    
    
    u = unew;
    t = t+dt;
    
    
    if mod(iter,see) == 0
        plot1DMain(u,T, G, M,f1, f2,t);
        fprintf("TS %d\n", iter);
    end
    
end


function dudt = frhs(u,T,G,M)
dudxLe = (u - u(:,G.iLeft))./G.hLeft;
dudxRi = -(u - u(:,G.iRight))./G.hRight;
dudxC = F_TVD_Slope(dudxLe,dudxRi);

Ys = f_getYs(u);



dTdxLe = (T - T(:,G.iLeft))./G.hLeft;
dTdxRi = -(T - T(:,G.iRight))./G.hRight;
dTdxC = F_TVD_Slope(dTdxLe,dTdxRi);

ifrec = 1;
TLe = T - dTdxC .* G.hc * 0.5 * ifrec;
TRi = T + dTdxC .* G.hc * 0.5 * ifrec;
uLe = u - dudxC .* G.hc * 0.5 * ifrec;
uRi = u + dudxC .* G.hc * 0.5 * ifrec;

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

fLe_mu = 1e-20; %total vis
fLe_eta = 1e-20; %total cond
Sc = 0.5;
Xs = f_getXs(Ys, M.Ms);
fLe_rhoDs = ((1-fLe_YsM) .* fLe_mu) ./ ((1 - Xs) * Sc);

fLe_dudx = 0.5 * (dudxC + dudxC(:,G.iLeft)) + (fLe_uRi - fLe_uLe)./(2 * G.hLeft);
fLe_dTdx = 0.5 * (dTdxC + dTdxC(:,G.iLeft)) + (fLe_TRi - fLe_TLe)./(2 * G.hLeft);

fLe_hs = f_fitAbsoluteHeat(fLe_TM,M.asA,M.asB);


fLe_fluxVis = F_VisFlux_G(fLe_uLe, fLe_dudx, zeros(size(u)),...
    fLe_dTdx, fLe_YsM, M.Ms, fLe_hs, fLe_mu, fLe_eta,fLe_rhoDs);

fLe_flux = fLe_fluxVis - fLe_fluxInv;




dudt =  ...
    (-fLe_flux + fLe_flux(:, G.iRight))./G.hc;


end


function dudt_source = frhs_source(u,T,G,M)
% chem
kf = f_kArrhenius(M.ABCABC(:, 1:3),T);
kb = f_kArrhenius(M.ABCABC(:, 4:6),T);
Ys = f_getYs(u);
rhoYs = u(1,:) .* Ys;
ns = rhoYs./M.Ms;
omega_chem = f_oNChem(ns, kf, kb, M.nuf, M.nub, M.Ctri, M.Ntri) .* M.Ms;

source = zeros(size(u));
source(5:end,:) = omega_chem(1:end-1,:);

dudt_source = source;

end

function dudt_source_jacobian = fjacobians_source(u,T,G,M)
nv = size(u,1);
nG = size(u,2);
dudt_source_jacobian = zeros(nv,nv,nG);

kf = f_kArrhenius(M.ABCABC(:, 1:3),T);
kb = f_kArrhenius(M.ABCABC(:, 4:6),T);
Ys = f_getYs(u);

rhoYs = u(1,:) .* Ys;
ns = rhoYs./M.Ms;
% d_omega_chem = f_doNChem(ns, kf, kb, M.nuf, M.nub, M.Ctri, M.Ntri) .* ...
%     reshape(M.Ms,[],1,1) ./ reshape(M.Ms,1,[],1);
d_omega_chem = f_doNChem(ns, kf, kb, M.nuf, M.nub, M.Ctri, M.Ntri) .* ...
    reshape(M.Ms,[],1,1) ./ reshape(M.Ms,1,[],1);

% for i = 1:nG
%     dudt_source_jacobian(5:end,5:end,i) = d_omega_chem(1:end-1,1:end-1, i);
%     %     dudt_source_jacobian(:,:,i) = dudt_source_jacobian(:,:,i) + eye(nv,nv) * 1e-200;
% end
dudt_source_jacobian(5:end,5:end,:) = d_omega_chem(1:end-1,1:end-1,:);

end

function dus = fsimple_implicit_sourcedt(u,T,G,M,dt)
nG = size(u,2);

uc = u;
N = 5; Nin = 1;
[T,~, ~] = f_solveT_fit(T,f_getYs(uc),uc,M.Ms,M.asA, M.asB);
dus = zeros(size(u));
for istep = 1:N
    
%     [T,~, ~] = f_solveT_fit(T,f_getYs(uc),uc,M.Ms,M.asA, M.asB);
    dudt_source_jacobian = fjacobians_source(uc,T,G,M);
    dusincMat = repmat(eye(size(dus,1)) / dt,1,1,nG) - dudt_source_jacobian;
    for iterIn = 1:Nin
        dudt_source = frhs_source(uc,T,G,M);
        if(~(isreal(dudt_source) && isreal(dudt_source_jacobian)))
            error('complex');
        end
        dusincRhs = dudt_source - dus/dt;
%         for i = 1:nG
%             dus(:,i) = dus(:,i) + dusincMat(:,:,i)\...
%                 dusincRhs(:,i);
%         end
        
        dus = dus + m_solveDiags_mex(dusincMat,dusincRhs);
%         dus = dus + m_solveDiags(dusincMat,dusincRhs);
        uc = u + dus;
    end
    
end

unew = dus + u;
unewb = unew(5:end,:);
minus = unewb < 0;
if(sum(minus,'all'))
    %    error('minus out');
end


% unewbfix = u(5:end,:).^exp(dudt_source(5:end,:)*dt./u(5:end,:));
% unewb(minus) = unewbfix(minus);
% unew(5:end,:) = unewb;
% dus = unew - u;

% end







end

