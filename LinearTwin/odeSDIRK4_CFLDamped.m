function unew = odeSDIRK4_CFLDamped(u, frhs, fdTau, fjacobian, dt)
usize = size(u);
u = u(:);
N = numel(u);
maxiter= 100;
innerTh = 1e-3;


rhss = cell(1,3);

zeta  = 0.128886400515;
sqr = @(x) x^2;
butcherA = [zeta, 0, 0;0.5 - zeta, zeta, 0;2 * zeta, 1 - 4 * zeta, zeta];
butcherB = [1. / (6 * sqr(2 * zeta - 1)), (4 * sqr(zeta) - 4 * zeta + 2. / 3.) / sqr(2 * zeta - 1),1. / (6 * sqr(2 * zeta - 1))];
butcherC = [zeta, 0.5, 1 - zeta];

for iB = 1:3
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
for jB = 1:3
    unew = unew + rhss{jB} * dt *  butcherB(jB);
end
unew = reshape(unew,usize);





