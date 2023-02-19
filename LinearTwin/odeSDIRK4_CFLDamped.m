function unew = odeSDIRK4_CFLDamped(u, frhs, fdTau, fjacobian, dt)
usize = size(u);
u = u(:);
N = numel(u);
maxiter= 100;
innerTh = 1e-3;





sqr = @(x) x^2;

% SDIRK 3s4o
zeta  = 0.128886400515;
butcherA = [zeta, 0, 0;0.5 - zeta, zeta, 0;2 * zeta, 1 - 4 * zeta, zeta];
butcherB = [1. / (6 * sqr(2 * zeta - 1)), (4 * sqr(zeta) - 4 * zeta + 2. / 3.) / sqr(2 * zeta - 1),1. / (6 * sqr(2 * zeta - 1))];
butcherC = [zeta, 0.5, 1 - zeta];
%%%%%%

% % SDIRK 6s4o
% NS = 6;
% butcher = [...
%     0.067410767219 0.194216850802 0.067410767219 0.194216850802 0.199861501713 0.067410767219 0.162188551749 0.166902343330 0.145120313717 0.067410767219 0.165176818500 0.169977460026 0.150227711763 0.181214258555 0.067410767219 0.165176818500 0.169977460026 0.150227711763 0.181214258555 0.199861501713 0.067410767219 0.168954170460 0.173864595628 0.156683775305 0.157643002581 0.173864725004 0.16898973102];
% butcherA = zeros(6);
% istart = 1;
% for i = 1:NS
%     butcherA(i,1:i) = butcher(istart:istart+i-1);
%     istart = istart+i;
% end
% butcherB = butcher(end-NS+1:end);
% butcherC = sum(butcherA,2)';
% %%%%%%

rhss = cell(1,numel(butcherC));

for iB = 1:numel(butcherC)
    uc = u;
    for iter = 1:maxiter
        dtau = reshape(fdTau(reshape(uc,usize)),[],1);
        rhss{iB} = reshape(frhs(reshape(uc,usize), butcherC(iB)),[],1);
        rhs = (u - uc) / dt;
        for jB = 1:iB
            rhs = rhs + rhss{jB} * butcherA(iB,jB);
        end
        
        J = fjacobian(reshape(uc,usize));
        mat = J* butcherA(iB,iB) + spdiags(1./dtau(:), 0,N,N) + speye(N,N)*(1/dt);
        %%solve
        %         du = mat\rhs;
        %%lusolve
        %         [matL,matU,matP,matQ] = lu(mat);
        %         duS = matL\(matP*rhs);
        %         du = matQ*(matU\duS);
        %%gmressovle + ilu0
        setup.type = 'nofill';
        [matL,matU] = ilu(mat,setup);
        [du,gmresOut.flag,gmresOut.relres,gmresOut.iternum] = gmres(mat,rhs,10,1e-15,2,matL,matU);
        
        
        
        uc = uc + du;
        res = sum(abs(du(:)));
        
        if(iter == 1)
            res0 = res;
        end
        resr = res/res0;
        resrc = res/(sum(abs(rhss{iB}))*dt);
        
        fprintf("   === odeSDIRK4 resrInner %d: %.3e, %.3e\n", iter, resr, resrc);
        %         if(resr < innerTh || resrc < innerTh)
        if(resr < innerTh )
            break;
        end
    end
    if iter == maxiter
        if resr >=1
            error("divergence in odeSDIRK4_CFLDamped!");
        end
    end
    
    
    
end

unew = u;
for jB = 1:numel(butcherC)
    unew = unew + rhss{jB} * dt *  butcherB(jB);
end
unew = reshape(unew,usize);





