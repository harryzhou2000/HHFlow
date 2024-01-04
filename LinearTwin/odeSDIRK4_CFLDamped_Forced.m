function unew = odeSDIRK4_CFLDamped_Forced(u, frhs, fdTau, fjacobian, fForce, dt, type)
u = u(:);
N = numel(u);
usize = size(u);
maxiter= 100;
innerTh = 1e-7;

block_size = usize(1);

% types:
% 1: sdirk 3s4o
% 2: esdirk 6s4o
if(nargin < 6)
   type = 1; 
end



sqr = @(x) x^2;

% SDIRK 3s4o
switch type
    case 1
        zeta  = 0.128886400515;
        butcherA = [zeta, 0, 0;0.5 - zeta, zeta, 0;2 * zeta, 1 - 4 * zeta, zeta];
        butcherB = [1. / (6 * sqr(2 * zeta - 1)), (4 * sqr(zeta) - 4 * zeta + 2. / 3.) / sqr(2 * zeta - 1),1. / (6 * sqr(2 * zeta - 1))];
        butcherC = [zeta, 0.5, 1 - zeta];
    case 2
%         butcherA = [...
%             0     0        0    0      0    0;
%             1/4   1/4      0    0      0    0;
%             1/16  -1/16    1/4  0      0    0;
%             -7/36 -4/9     8/9  1/4    0    0;
%             -5/48 -257/768 5/6  27/256 1/4  0;
%             1/4   2/3      -1/3 1/2    -1/3 1/4;
%             ];
%         butcherB = butcherA(end,:);
%         butcherC = sum(butcherA,2)';
        butcherA = [...
            0                         0                   0                    0               0          0;
            1/4                       1/4                 0                    0               0          0;
            8611/62500                -1743/31250         1/4                  0               0          0;
            5012029/34652500          -654441/2922500     174375/388108        1/4             0          0;
            15267082809/155376265600  -71443401/120774400 730878845/902184768  2285395/8070912 1/4        0;
            82889/524892              0                   15625/83664          69875/102672    -2260/8211 1/4;
            ];
        butcherB = butcherA(end,:);
        butcherC = sum(butcherA,2)';
    otherwise
        error('DIRK: no such method')
end
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
        if type == 2 && iB == 1
            break;
        end
        
        rhs = (u - uc) / dt;
        for jB = 1:iB
            rhs = rhs + rhss{jB} * butcherA(iB,jB);
        end
        rhs = rhs + fForce(butcherC(iB)) * 1/dt;
        
        J = fjacobian(reshape(uc,usize));
        [A_L,A_U,A_D] = bLUD(J,block_size);
        dtauIFix = full(sum(abs(A_L+A_U+2*(A_D-0*spdiags(spdiags(A_D,0),0,N,N))),2))* butcherA(iB,iB) * 0;
    
        mat = -J* butcherA(iB,iB) + spdiags(1./dtau(:) + dtauIFix*1, 0,N,N) + speye(N,N)*(1/dt);
        %%LUSGS solve
%         du = bLUSGS_naive_mex(mat,rhs,block_size);
        %%solve
                du = mat\rhs;
        %%lusolve
        %         [matL,matU,matP,matQ] = lu(mat);
        %         duS = matL\(matP*rhs);
        %         du = matQ*(matU\duS);
        %%gmressovle + ilu0
%         setup.type = 'nofill';
%         [matL,matU] = ilu(mat,setup);
%         [du,gmresOut.flag,gmresOut.relres,gmresOut.iternum] = gmres(mat,rhs,10,1e-15,2,matL,matU);
        
        
        
        uc = uc + du;
        res = sum(abs(du(:)));
        
        if(iter == 1)
            res0 = res;
        end
        resr = res/res0;
        resrc = res/(sum(abs(rhss{iB}))*dt);
        
        fprintf("   === odeSDIRK4 %d resrInner %d: %.3e, %.3e\n", iB, iter, resr, resrc);
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

if type == 2
    unew = uc;
else
    unew = u;
    for jB = 1:numel(butcherC)
        unew = unew + rhss{jB} * dt *  butcherB(jB);
    end
end
unew = reshape(unew,usize);





