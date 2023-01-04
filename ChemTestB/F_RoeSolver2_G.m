function F = F_RoeSolver2_G(uL, uR, pL, pR, gammaM1Mean)

rhoL = uL(1,:);
rhoR = uR(1,:);
UxL = uL(2,:) ./ rhoL;
UxR = uR(2,:) ./ rhoR;
UyL = uL(3,:) ./ rhoL;
UyR = uR(3,:) ./ rhoR;
eL = uL(4,:) ./ rhoL;
eR = uR(4,:) ./ rhoR;
HL = eL + pL ./ rhoL;
HR = eR + pR ./ rhoR;

rhoLsqrt = sqrt(rhoL);
rhoRsqrt = sqrt(rhoR);
rhoLRsqrtSum = rhoLsqrt + rhoRsqrt;

UxRoe = (rhoLsqrt .* UxL + rhoRsqrt.* UxR)./rhoLRsqrtSum;
UyRoe = (rhoLsqrt .* UyL + rhoRsqrt.* UyR)./rhoLRsqrtSum;
HRoe  = (rhoLsqrt .* HL + rhoRsqrt.* HR)./rhoLRsqrtSum;
UsqrRoe = UxRoe.^2 + UyRoe.^2;
asqrRoe = gammaM1Mean .* (HRoe - 0.5 * UsqrRoe);
if(sum(asqrRoe>0)~=numel(asqrRoe))
   error('imag a');
end
aRoe = sqrt(asqrRoe);
% ! aRoe is not precise?

lam1Roe = UxRoe - aRoe;
lam2Roe = UxRoe;
lam5Roe = UxRoe + aRoe;

lam1Roe = abs(lam1Roe);
lam2Roe = abs(lam2Roe);
lam5Roe = abs(lam5Roe);

%HY
deltaEF = 0.05 * (sqrt(UsqrRoe) + aRoe);
lam1Fix = lam1Roe < deltaEF;
lam5Fix = lam5Roe < deltaEF;
lam1Roe(lam1Fix) = (lam1Roe(lam1Fix).^2+deltaEF(lam1Fix).^2)./deltaEF(lam1Fix)/2;
lam5Roe(lam5Fix) = (lam5Roe(lam5Fix).^2+deltaEF(lam5Fix).^2)./deltaEF(lam5Fix)/2;
%HY
ng = size(lam1Roe);
rev1 = [ones(ng) ; UxRoe - aRoe             ; UyRoe               ; HRoe - UxRoe.*aRoe];
rev2 = [ones(ng) ; UxRoe               ; UyRoe               ; 0.5 * UsqrRoe     ];
rev3 = [zeros(ng); zeros(size(lam1Roe)); ones(size(lam1Roe)) ; UyRoe             ];
rev5 = [ones(ng) ; UxRoe + aRoe             ; UyRoe               ; HRoe + UxRoe.*aRoe];

uinc = uR - uL;

alpha3 = uinc(3,:) - UyRoe .* uinc(1,:);
incU5c = uinc(4,:) - ( uinc(3,:) - UyRoe .* uinc(1,:) ) .* UyRoe;
alpha2 = gammaM1Mean./(asqrRoe) .* (uinc(1,:) .* (HRoe - UxRoe.^2) + UxRoe .* uinc(2,:) - incU5c);
alpha1 = 0.5./aRoe .* ( uinc(1,:).*lam5Roe - uinc(2,:) - aRoe.*alpha2 );
alpha5 = uinc(1,:) - (alpha1 + alpha2);


% Pike
% incP = pR - pL;
% rhoRoe = sqrt(rhoR.*rhoL);
% incUx = UxR - UxL;
% incUy = UyR - UyL;
% 
% alpha1 = 0.5./aRoe .* (incP - rhoRoe.*aRoe.*incUx);
% alpha2 = uinc(1,:) - incP./aRoe.^2;
% alpha3 = rhoRoe .* incUy;
% alpha5 = 0.5./aRoe .* (incP + rhoRoe.*aRoe.*incUx);
% Pike


FL = uL.*UxL;
FL(2,:) = FL(2,:) + pL;
FL(4,:) = FL(4,:) + pL .* UxL;

FR = uR.*UxR;
FR(2,:) = FR(2,:) + pR;
FR(4,:) = FR(4,:) + pR .* UxR;


F_Front = 0.5 * (FL(1:4,:) + FR(1:4,:))  - 0.5 * (...
    alpha1 .* (lam1Roe) .* rev1 + ...
    alpha2 .* (lam2Roe) .* rev2 + ...
    alpha3 .* (lam2Roe) .* rev3 + ...
    alpha5 .* (lam5Roe) .* rev5);

% % method 1: full lax
lamMax = abs(UxRoe) + aRoe;
F_Front = 0.5 * (...
    FL(1:4,:) + FR(1:4,:) - ...
    lamMax.*(uR(1:4,:) - uL(1:4,:))...
    );
F_Back = 0.5 * (...
    FL(5:end,:) + FR(5:end,:) - ...
    lamMax.*(uR(5:end,:) - uL(5:end,:))...
    );

% lamMax = abs(UxRoe) + aRoe;
% F_Front = 0.5 * (...
%     FL(1:4,:) + FR(1:4,:) - ...
%     lamMax.*(uR(1:4,:) - uL(1:4,:))...
%     );
% F_Back = 0.5 * (...
%     FL(5:end,:) + FR(5:end,:) - ...
%     lam2Roe.*(uR(5:end,:) - uL(5:end,:))...
%     );
% F_Front(1,:) = 0.5 * (...
%     FL(1,:) + FR(1,:) - ...
%     lam2Roe.*(uR(1,:) - uL(1,:))...
%     );

% % method 2
% F_Back = 0.5 * (...
%     FL(5:end,:) + FR(5:end,:) - ...
%     abs(lam2Roe).*(uR(5:end,:) - uL(5:end,:))...
%     );
% F_Front(1,:) = 0.5 * (...
%     FL(1,:) + FR(1,:) - ...
%     abs(lam2Roe).*(uR(1,:) - uL(1,:))...
%     );



% FL_Add = FL(1,:) - sum(FL(5:end,:),1);
% FR_Add = FR(1,:) - sum(FR(5:end,:),1);
% uL_Add = uL(1,:) - sum(uL(5:end,:),1);
% uR_Add = uR(1,:) - sum(uR(5:end,:),1);
% F_Add = 0.5 * (FL_Add + FR_Add - abs(lam2Roe).*(uR_Add - uL_Add));
% 
% F_Front(1,:) = sum(F_Back,1) + F_Add;




F = [F_Front;F_Back];








