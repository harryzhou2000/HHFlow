% clear;

% runMode = 0; % 0 for matlab, 1 for mex, 2 for mex + gpu
%%
% t = 7340e-9, K = 1e6, sw at 0.025, 23700 at 0.1
Nscale = 1;
invertGodunov = 0;
method = 3;
odemethod = 1; % 0 for RK2, 1 for trapz
N = 500 * Nscale;
see = 1;
uEst = 1500;
CFLest = 0.5;
tmax = 0.3e-4;
Lmax = 0.05;
CFLin = 100;
%%

G.ifrec = 0;
G.xs = linspace(0,Lmax,N+1);
G.hc = G.xs(2:end) - G.xs(1:end-1);
G.xc = 0.5 * (G.xs(2:end) + G.xs(1:end-1));
G.ithis = 1:N;
G.iLeft = circshift(G.ithis,1);
G.iRight = circshift(G.ithis,-1);
G.hLeft = G.xc - G.xc(G.iLeft);
G.hRight = G.xc(G.iRight) - G.xc;
G.hmax = max(G.hc);
G.ibLeft = 1;
G.ibRight = N;
G.bndLeft = 1;
G.bndRight = 2; % 1 for wall, 2 for frozen
% warning, right bnd support unfinished!!


% dt = CFLest * G.hmax / uEst;
dt = 1e-8 / Nscale;
% niter = round(tmax/uEst/dt);
niter = round(tmax/dt);

% chemData7_8M;
% chemData7_8M_Argon;
chemData4_1M_Single;

M.names = names;
M.asA = asA; M.asB = asB;
M.Ctri = Ctri; M.Ntri = Ntri;
M.nub = nub; M.nuf = nuf;
M.Ms = Ms;
M.ABCABC = ABCABC;
M.chem = chem_setting.chem;
%%
% rhoA = 1;
% vxA = 0;
% vxB = 500;
% TA = 300;
% YA = Ms.*([2 1 0 0 0 0 7]');
% YA = YA/sum(YA);
% [uA,aA] = f_ruty2cons(rhoA, vxA, TA, YA, M);
% [uB,aB] = f_ruty2cons(rhoA, vxB, TA * 7, YA, M);


% Y = Ms.*([2 1 0 0 0 0 7]');
% Y = Y/sum(Y);

Y = Ms.*([2 1 0 7]');
Y = Y/sum(Y);

[uUp,aUp,rUp] = f_puty2cons(2e5, 0, 700, Y, M);
[uDown,aDown,pDown] = f_puty2cons(2e5, 0, 800, Y, M);

%%
ns = numel(names);


% u0 = uA*ones(1,N);
% T0 = TA*ones(1,N);
%
% rg1 = G.ithis( G.xc > 0.4 & G.xc < 0.6);
% u0(:,rg1) = uB * ones(1,numel(rg1));

u0 = uUp*ones(1,N);
T0 = 700*ones(1,N);

rg1 = G.ithis( G.xc < 1e-4 );
u0(:,rg1) = uDown * ones(1,numel(rg1));
T0(:,rg1) = 800;

dudt0 = frhs(u0,T0,G,M);
u = u0;
T = T0;


%%
t = 0;
figure(1);
clf;f1 = gca;
figure(2);
clf;f2 = gca;
figure(2);

for iter = 1:niter
    
    if method == 1
        % Method: inserted Crank-Nicolson
        %%%%%%%%%%%%%%%%%%%%%%%%%
        %         % use simple
        %         duS1 = fsimple_implicit_sourcedt(u,T,G,M,dt/2);
        %         duS2 = fsimple_implicit_sourcedt(u+duS1,T,G,M,dt/2);
        %         S1  = frhs_source(u + duS1,T,G,M);
        %         S2  = frhs_source(u + duS1 + duS2,T,G,M);
        %         u_m0 = u + duS1 * 0 + duS2 * 1;
        %             % use ode
        if invertGodunov == 1
            u_m0 = u + fode_implicit_sourcedt(u,T,G,M,dt);
        else
            u_m0 = u;
        end
        
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%
        %         duSource = u_m0 - u;%testaloha
        %         u_m0 = u;%testaloha
        if odemethod == 0
            [T,p, stat] = f_solveT_fit(T,f_getYs(u_m0),u_m0,M.Ms,M.asA, M.asB);
            dudt =  frhs(u_m0,T,G,M);
            u_m1 = u_m0 + dudt * dt;
            [T,p, stat] = f_solveT_fit(T,f_getYs(u_m1),u_m1,M.Ms,M.asA, M.asB);
            dudt1 = frhs(u_m1,T,G,M)  + (- S2 + frhs_source(u_m1,T,G,M)) * 0;
            unew = 0.5 * u_m0 + 0.5 * u_m1 + 0.5 * dudt1 * dt;
        elseif odemethod == 1
            [T, p, stat] = f_solveT_fit(T,f_getYs(u_m0),u_m0,M.Ms,M.asA, M.asB);
            unew = f_step_Trapz_F(u_m0, T, G, M, dt, CFLin);
        else
            error("");
        end
        
        if invertGodunov == 0
            unew = unew + fode_implicit_sourcedt(unew,T,G,M,dt);
        else
            
        end
        
        
        %         unew = unew + duSource;%testaloha
        
        %     unew = u_m1;
        
        % Method: inserted Crank-Nicolson: split order revert
        
        %     [T,p, stat] = f_solveT_fit(T,f_getYs(u),u,M.Ms,M.asA, M.asB);
        %     dudt =  frhs(u,T,G,M);
        %     u_m1 = u + dudt * dt;
        %     [T,p, stat] = f_solveT_fit(T,f_getYs(u_m1),u_m1,M.Ms,M.asA, M.asB);
        %     dudt1 = frhs(u_m1,T,G,M)  + (- S2 + frhs_source(u_m1,T,G,M)) * 0;
        %     unew_t = 0.5 * u + 0.5 * u_m1 + 0.5 * dudt1 * dt;
        %
        %     duS1 = fsimple_implicit_sourcedt(unew_t,T,G,M,dt/2);
        %     duS2 = fsimple_implicit_sourcedt(unew_t+duS1,T,G,M,dt/2);
        %     unew = unew_t + duS1 + duS2;
    elseif method == 2
        % Method: explicit
        if odemethod == 0
            [T,p, stat] = f_solveT_fit(T,f_getYs(u),u, M.Ms,M.asA, M.asB);
            S1 = frhs_source(u,T,G,M) * 0;
            F1 = frhs(u,T,G,M);
            u1 = u + (S1+F1) * dt;
            [T,p, stat] = f_solveT_fit(T,f_getYs(u1),u1, M.Ms,M.asA, M.asB);
            S2 = frhs_source(u1,T,G,M) * 0;
            F2 = frhs(u1,T,G,M);
            u2 = 0.5 * u + 0.5 * u1 + 0.5 * dt * (S2 + F2);
            unew = u2;
        elseif odemethod == 1
            [T,p, stat] = f_solveT_fit(T,f_getYs(u),u, M.Ms,M.asA, M.asB);
            unew = f_step_Trapz_F(u, T, G, M, dt, CFLin, true);
        else
            error("")
        end
    elseif method == 3
        T0 = T;
        if odemethod == 0
            [T,p, stat] = f_solveT_fit(T,f_getYs(u),u, M.Ms,M.asA, M.asB);
            F1 = frhs(u,T,G,M);
            u1 = u + (F1) * dt;
            [T,p, stat] = f_solveT_fit(T,f_getYs(u1),u1, M.Ms,M.asA, M.asB);
            F2 = frhs(u1,T,G,M);
            u2 = 0.5 * u + 0.5 * u1 + 0.5 * dt * (F2);
            [T,p, stat] = f_solveT_fit(T,f_getYs(u2),u2, M.Ms,M.asA, M.asB);
        elseif odemethod == 1
            u2 = f_step_Trapz_F(u, T, G, M, dt, CFLin);
            [T,p, stat] = f_solveT_fit(T,f_getYs(u2),u2, M.Ms,M.asA, M.asB);
            F1 = frhs(u,T0,G,M);
        else
            error("")
        end
        F3 = frhs(u2,T,G,M);
        
        fgetFluxRHS = @(t,iCell) F3(:,iCell) * t/dt + F1(:,iCell) * (dt-t)/dt;
        
        unew = u + fode_implicit_sourcedt(u,T0,G,M,dt,fgetFluxRHS);
    elseif method == 4
        T0 = T;
        u2 = f_step_Trapz_F(u, T, G, M, dt, CFLin);
        [T,p, stat] = f_solveT_fit(T,f_getYs(u2),u2, M.Ms,M.asA, M.asB);
        F1 = frhs(u,T0,G,M);
        F3 = frhs(u2,T,G,M);
        
        fgetFluxRHS = @(t,iCell) F3(:,iCell) * t/dt + F1(:,iCell) * (dt-t)/dt;
        
        unew = u + fode_implicit_sourcedt(u,T0,G,M,dt,fgetFluxRHS);
        %     unew = u2;
        
    end
    
    
    
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
%%
frhs(u,T,G,M);


function dudt = frhs(u,T,G,M)
dudxLe = (u - u(:,G.iLeft))./G.hLeft;
dudxRi = -(u - u(:,G.iRight))./G.hRight;
dudxC = F_TVD_Slope(dudxLe,dudxRi) * 1;

Ys = f_getYs(u);

dTdxLe = (T - T(:,G.iLeft))./G.hLeft;
dTdxRi = -(T - T(:,G.iRight))./G.hRight;
dTdxC = F_TVD_Slope(dTdxLe,dTdxRi) * 1;

switch G.bndLeft
    case 0
        %nothing
    case {1,2}
        dudxC(:,G.ibLeft) = 0;
        dTdxC(:,G.ibLeft) = 0;
    otherwise
        error('no bnd type');
        
end

switch G.bndRight
    case 0
        %nothing
    case {1,2}
        dudxC(:,G.ibRight) = 0;
        dTdxC(:,G.ibRight) = 0;
    otherwise
        error('no bnd type');
        
end

ifrec = G.ifrec;
TLe = T - dTdxC .* G.hc * 0.5 * ifrec;
TRi = T + dTdxC .* G.hc * 0.5 * ifrec;
uLe = u - dudxC .* G.hc * 0.5 * ifrec;
uRi = u + dudxC .* G.hc * 0.5 * ifrec;

fLe_TRi = TLe;
fLe_uRi = uLe;
fLe_TLe = TRi(:,G.iLeft);
fLe_uLe = uRi(:,G.iLeft);

switch G.bndLeft
    case {0,2}
        %nothing
    case {1}
        fLe_TLe(:,G.ibLeft) = fLe_TRi(:,G.ibLeft);
        fLe_uLe(:,G.ibLeft) = fLe_uRi(:,G.ibLeft);
        fLe_uLe(2,G.ibLeft) = -fLe_uRi(2,G.ibLeft);
    otherwise
        error('no bnd type');
        
end

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
switch G.bndLeft
    case 0
        %nothing
    case 1
        %nothing
    case 2
        dudt(:,G.ibLeft) = 0;
    otherwise
        error('no bnd type');
        
end

switch G.bndRight
    case 0
        %nothing
    case 1
        %nothing
    case 2
        dudt(:,G.ibRight) = 0;
    otherwise
        error('no bnd type');
        
end

end




function dudt_source = frhs_source(u,T,G,M, ilocation)

if nargin == 4
    ilocation = -1;
end

if(M.chem == "chem_exp")
    nReaction = size(M.ABCABC,1);
    assert(nReaction == 1); %only supports 1 reaction
    Ys = f_getYs(u);
    rhoYs = u(1,:) .* Ys;
    ns = rhoYs./M.Ms;
    R = M.pK * ns(1,:) .* (T>710);
    source = zeros(size(u));
    omega_chem = (((M.nub - M.nuf)') * R ).* M.Ms;
    source(5:end,:) =  omega_chem(1:end-1,:);
    dudt_source = source;
elseif(M.chem == "chem")
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
    
else
    error("no such chem option");
end

switch G.bndLeft
    case 0
        %nothing
    case 1
        %nothing
    case 2
        if(ilocation < 0)
            dudt_source(:,G.ibLeft) = 0;
        else
            if ilocation == G.ibLeft
                dudt_source(:,1) = 0;
            end
        end
    otherwise
        error('no bnd type');
        
end

switch G.bndRight
    case 05
        %nothing
    case 1
        %nothing
    case 2
        if(ilocation < 0)
            dudt_source(:,G.ibRight) = 0;
        else
            if ilocation == G.ibRight
                dudt_source(:,1) = 0;
            end
        end
    otherwise
        error('no bnd type');
        
end

end

function dudt_source_jacobian = fjacobians_source(u,T,G,M, ilocation)

if nargin == 4
    ilocation = -1;
end

nv = size(u,1);
nG = size(u,2);
dudt_source_jacobian = zeros(nv,nv,nG);

if(M.chem == "chem_exp")
    nReaction = size(M.ABCABC,1);
    assert(nReaction == 1); %only supports 1 reaction
    Ys = f_getYs(u);
    rhoYs = u(1,:) .* Ys;
    ns = rhoYs./M.Ms;
    dR1 = M.pK * ones(size(ns(1,:))) .* (T>710);
    nS = size(ns,1);
    dR = zeros(nReaction, nS, nG);
    dR(1, 1, :) = dR1(:);
    d_omega_chem = ((M.nub - M.nuf)') * reshape(dR, nReaction, []);
    d_omega_chem = reshape(d_omega_chem, nS, nS, nG);
elseif(M.chem == "chem")
    
    kf = f_kArrhenius(M.ABCABC(:, 1:3),T);
    kb = f_kArrhenius(M.ABCABC(:, 4:6),T);
    Ys = f_getYs(u);
    
    rhoYs = u(1,:) .* Ys;
    ns = rhoYs./M.Ms;
    % d_omega_chem = f_doNChem(ns, kf, kb, M.nuf, M.nub, M.Ctri, M.Ntri) .* ...
    %     reshape(M.Ms,[],1,1) ./ reshape(M.Ms,1,[],1);
    d_omega_chem = f_doNChem(ns, kf, kb, M.nuf, M.nub, M.Ctri, M.Ntri) .* ...
        reshape(M.Ms,[],1,1) ./ reshape(M.Ms,1,[],1);
else
    error("no such chem option");
end

% for i = 1:nG
%     dudt_source_jacobian(5:end,5:end,i) = d_omega_chem(1:end-1,1:end-1, i);
%     %     dudt_source_jacobian(:,:,i) = dudt_source_jacobian(:,:,i) + eye(nv,nv) * 1e-200;
% end
dudt_source_jacobian(5:end,5:end,:) = d_omega_chem(1:end-1,1:end-1,:) - repmat(d_omega_chem(1:end-1,end,:),1,nv-4,1);
dudt_source_jacobian(5:end,1,:) = d_omega_chem(1:end-1,end,:); % for that rho_end = rho - rho_1 - rho_2


end

function dus = fsimple_implicit_sourcedt(u,T,G,M,dt)
nG = size(u,2);

uc = u;
N = 5; Nin = 1;
[T,~, ~] = f_solveT_fit(T,f_getYs(uc),uc,M.Ms,M.asA, M.asB);
dus = zeros(size(u));
for istep = 1:N
    
    [T,~, ~] = f_solveT_fit(T,f_getYs(uc),uc,M.Ms,M.asA, M.asB);
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
if(any(minus))
    %    error('minus out');
end


% unewbfix = u(5:end,:).^exp(dudt_source(5:end,:)*dt./u(5:end,:));
% unewb(minus) = unewbfix(minus);
% unew(5:end,:) = unewb;
% dus = unew - u;

% end







end

function [lambdas,dTau] = fget_lambdas(u,T,G,M, CFL)
nv = size(u,1);
nG = size(u,2);
lambdas = nan(1,nG+1);

Ys = f_getYs(u);
p = f_DaltonPressureSum(u(1,:),Ys,M.Ms,T);
gammaM1 = f_gammM1_fit(u(1,:), T, Ys, M.Ms, M.asA, M.asB);
%     a = sqrt(gammaM1.*p./u(1,:));
velos = u(2:3,:)./u(1,:);


for iFace = 1:nG+1
    iCellL = max(iFace - 1,1);
    iCellR = min(iFace, nG);
    pFace = (p(iCellL) + p(iCellR))/2;
    gammaM1Face = (gammaM1(iCellL) + gammaM1(iCellR))/2;
    rhoFace = (u(1,iCellL) + u(1,iCellR))/2;
    aFace = sqrt((gammaM1Face+1) * pFace / rhoFace);
    veloFace = (velos(:,iCellL) + velos(:,iCellR))/2;
    lambdaConvFace = abs(veloFace(1)) + aFace;
    lambdas(iFace) = lambdaConvFace;
end
lambdaCell = lambdas(1:end-1) + lambdas(2:end);
dTau = CFL * G.hc ./ lambdaCell;

end

function dF = fget_dFluxX_prim(rho,velo,T,Ys,drho,dvelo,dT,dYs,G,M)


dustatic = f_ustatic_fit_D(rho,T,Ys,M.Ms,M.asA,M.asB,drho,dT,dYs);
ustatic = f_ustatic_fit(rho,T,Ys,M.Ms,M.asA,M.asB);
dp = f_DaltonPressureSum_D(rho,Ys,M.Ms,T,drho,dYs,dT);
p = f_DaltonPressureSum(rho,Ys,M.Ms,T);

nV = 4 + size(Ys,1) - 1;
nG = size(Ys,2);
dF = nan(nV, nG);
dF(1,:) = rho .* dvelo(1,:) + drho .* velo(1,:);
dF(2,:) = drho .* velo(1,:) .* velo(1,:) + 2 * rho .* velo(1,:) .* dvelo(1,:);
dF(3,:) = drho .* velo(1,:) .* velo(2,:) + rho .* dvelo(1,:) .* velo(2,:) + rho .* velo(1,:) .* dvelo(2,:);
dF(4,:) = (rho.*(ustatic  + 0.5 .* (velo(1,:).^2 + velo(2,:).^2)) + p) .* dvelo(1,:) + ...
    (drho.*(ustatic  + 0.5 .* (velo(1,:).^2 + velo(2,:).^2))+...
    rho.*(dustatic  + (velo(1,:).*dvelo(1,:) + velo(2,:).*dvelo(2,:)) + dp)) .* velo(1,:);
drhoYs = drho.*Ys + dYs.*rho;
drhoYsU = rho.*Ys.*dvelo(1,:) + drhoYs.*velo(1,:);
dF(5:end,:) = drhoYsU(1:end-1,:);

end

function u = f_prim2cons(rho,velo,T,Ys,M)
nV = 4 + size(Ys,1) - 1;
nG = size(Ys,2);
u = nan(nV,nG);
u(1,:) = rho;
u(2:3,:) = velo .* rho;
ustatic = f_ustatic_fit(rho,T,Ys,M.Ms,M.asA,M.asB);
u(4,:) = rho.*(ustatic + 0.5 * sum(velo.^2,1));
u(5:end,:) = Ys(1:end-1,:) .* rho;
end

function A = fget_dCons_dPrim(rho,velo,T,Ys, M)
nV = 4 + size(Ys,1) - 1;
nG = size(Ys,2);
nS = size(Ys,1);

A = zeros(nV,nV,nG);
ustatic = f_ustatic_fit(rho,T,Ys,M.Ms,M.asA,M.asB);
% dustatic_drho = f_ustatic_fit_D(rho,T,Ys,M.Ms,M.asA,M.asB,ones(size(rho)),zeros(size(T)),zeros(size(Ys)));
dustatic_drho = 0; %really?
dustatic_dT = f_ustatic_fit_D(rho,T,Ys,M.Ms,M.asA,M.asB,zeros(size(rho)),ones(size(T)),zeros(size(Ys)));
dustatic_dY = nan(nS,nG);
for is = 1:nS
    dys = zeros(nS,1);
    dys(is) = 1;
    dustatic_dY(is,:) = f_ustatic_fit_D(rho,T,Ys,M.Ms,M.asA,M.asB,zeros(size(rho)),zeros(size(T)),repmat(dys,1,nG));
end
A(1,1,:) = 1;
A(2,1,:) = velo(1,:);
A(2,2,:) = rho;
A(3,1,:) = velo(2,:);
A(3,3,:) = rho;
A(4,1,:) = (ustatic + 0.5 * sum(velo.^2,1)) + dustatic_drho;
A(4,2:3,:) = rho.*velo;
A(4,4,:) = dustatic_dT.*rho;
A(4,5:end,:) = dustatic_dY(1:end-1,:) .* rho;
for is = 1:nS-1
    A(is + 4,1,:) = Ys(is,:);
    A(is + 4,is + 4,:) = rho;
end
end

function [drho,dvelo,dT,dYs] = fLUSGS_prim(rho,velo,T,Ys, G, M, rhs, dTau, dt, alphaDiag, lambdas,...
    ifSource, jSource)
if nargin <= 11
    ifSource = false;
end

nV = 4 + size(Ys,1) - 1;
nG = size(Ys,2);
diags = 0.5 * alphaDiag * (lambdas(1:end-1) + lambdas(2:end))./G.hc + 1./dTau + 1/dt;

drho = zeros(1,nG);
dvelo = zeros(2,nG);
dT = zeros(1,nG);
dYs = zeros(size(Ys));
dCons_dPrim = fget_dCons_dPrim(rho,velo,T,Ys, M);

for iCell = 1:nG
    iCellL = iCell-1;
    iCellR = iCell+1;
    
    
    dubuf = rhs(:,iCell);
    
    iCellOther = iCellL;
    if iCellL >= 1
        dubuf = dubuf - 0.5 * alphaDiag / G.hc(iCell) * ...
            fget_dFluxX_prim(...
            rho(:,iCellOther),velo(:,iCellOther),T(:,iCellOther),Ys(:,iCellOther),...
            drho(:,iCellOther),dvelo(:,iCellOther),dT(:,iCellOther),dYs(:,iCellOther),G,M);
    end
    if ifSource
        jccell = jSource(:,:,iCell);
        ducell = (eye(size(jccell)) *diags(iCell) + jccell) \  dubuf;
    else
        ducell = dubuf / diags(iCell);
    end
    dprimcell = dCons_dPrim(:,:,iCell) \ ducell;
    drho(:,iCell) = dprimcell(1,1);
    dvelo(:,iCell) = dprimcell(2:3,1);
    dT(:,iCell) = dprimcell(4,1);
    dYs(1:end-1,iCell) = dprimcell(5:end,1);
    dYs(end,iCell) =  - sum(dYs(1:end-1,iCell)); %!!
    
end

for iCell = nG:-1:1
    iCellL = iCell-1;
    iCellR = iCell+1;
    
    
    dubuf = 0*rhs(:,iCell);
    
    iCellOther = iCellR;
    if iCellR <= nG
        dubuf = dubuf - 0.5 * alphaDiag / G.hc(iCell) * ...
            fget_dFluxX_prim(...
            rho(:,iCellOther),velo(:,iCellOther),T(:,iCellOther),Ys(:,iCellOther),...
            drho(:,iCellOther),dvelo(:,iCellOther),dT(:,iCellOther),dYs(:,iCellOther),G,M);
    end
    
    if ifSource
        jccell = jSource(:,:,iCell);
        ducell = (eye(size(jccell)) *diags(iCell) + jccell) \  dubuf;
    else
        ducell = dubuf / diags(iCell);
    end
    dprimcell = dCons_dPrim(:,:,iCell) \ ducell;
    drho(:,iCell) = drho(:,iCell) + dprimcell(1,1);
    dvelo(:,iCell) = dvelo(:,iCell) + dprimcell(2:3,1);
    dT(:,iCell) = dT(:,iCell) + dprimcell(4,1);
    dYs(1:end-1,iCell) = dYs(1:end-1,iCell) + dprimcell(5:end,1);
    dYs(end,iCell) =  - sum(dYs(1:end-1,iCell)); %!!
    
end


end

function unew = f_step_Trapz_F(u,T,G,M,dt,CFL, ifsource)

if nargin <= 6
    ifsource = false;
end

Ys = f_getYs(u);
rho = u(1,:);
velo = u(2:3,:) ./rho;


rhs0 = frhs(u,T,G,M);
if ifsource
    rhs0 = rhs0 + frhs_source(u,T,G,M);
end


unew = u;
u0  = u;

for iiter = 1:100
    
    [lambdas,dTau] = fget_lambdas(unew,T,G,M, CFL);
    rhsc = frhs(unew,T,G,M);
    Jsource = [];
    if ifsource
        rhsc = rhsc + frhs_source(unew,T,G,M);
        Jsource = fjacobians_source(unew, T,G,M);
    end
    
    
    [drho,dvelo,dT,dYs] = fLUSGS_prim(rho,velo,T,Ys, G, M,...
        (rhsc + rhs0) * 0.5 + (u0 - unew)/dt, dTau, dt, 0.5, lambdas, ifsource, Jsource);
    
    
    
    
    incrho = sum(abs(drho));
    incvelo = sum(abs(dvelo),'all');
    incT = sum(abs(dT),'all');
    incYs = sum(abs(dYs),2);
    
    rho = rho + drho;
    velo = velo + dvelo;
    T = T + dT;
    Ys = Ys + dYs;
    unew = f_prim2cons(rho,velo,T,Ys, M);
    
    fprintf('LUSGS inc: [%.4e %.4e %.4e %.4e]\n',incrho,incvelo,incT,sum(incYs));
    if(iiter ==1)
        incrho0 = incrho;
    end
    if incrho < incrho0 * 1e-3
        break;
    end
    
end



end


function dus = fode_implicit_sourcedt(u,T,G,M,dt,fadd)

nV = size(u,1);
nG = size(u,2);

if(nargin < 6)
    fadd = @(t, iCell) 0;
end

uc = u;
[T,~, ~] = f_solveT_fit(T,f_getYs(uc),uc,M.Ms,M.asA, M.asB);
dus = zeros(size(u));

parfor icell = 1:nG
    foderhs = @(t,ucc) oderhsSource(ucc, T(icell), G, M, icell) + fadd(t, icell);
    fjcbrhs = @(t,ucc) odejcbSource(ucc, T(icell), G, M, icell);
    
    options = odeset('Jacobian', fjcbrhs, 'RelTol', 1e-3, 'InitialStep', dt/2);
    sol = ode15s(foderhs, [0,dt], u(:,icell), options);
    dus(:,icell) = sol.y(:,end) - u(:,icell);
end
fprintf("done one fode_implicit_sourcedt\n");

unew = dus + u;
unewb = unew(5:end,:);
minus = unewb < 0;
if(any(minus))
    %    error('minus out');
end

end

function rhs = oderhsSource(uc, T, G, M, i)
T = f_solveT_fit(T,f_getYs(uc),uc,M.Ms,M.asA, M.asB);
rhs = frhs_source(uc, T, G, M, i);
end


function jcb = odejcbSource(uc, T, G, M, i)
T = f_solveT_fit(T,f_getYs(uc),uc,M.Ms,M.asA, M.asB);
jcb = fjacobians_source(uc, T, G, M, i);


end


