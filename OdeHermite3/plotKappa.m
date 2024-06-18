clear;
%%
syms A
syms b1 b2 b3 a1 a2 d1 d2 c2

syms x t i n hc

syms u(i) um(i)
syms u0 u1 r0 r1
syms kappa

b1c = 1/2 - 1/6/c2;
b3c = 1/2 - 1/6/(1-c2);
b2c = 1/6/c2/(1-c2);
% DITR U2R2
ditrMethod = 1;

if ditrMethod == 1
a1c = 1 - (3*c2^2-2*c2^3);
a2c = 1 - a1c;
d1c = c2 - 2 * c2^2 + c2^3;
d2c = - 1 * c2^2 + c2^3;
elseif ditrMethod == 2
a1c = 1 - (2 * c2 - c2^2);
a2c = 1 - a1c;
d1c = 0;
d2c = c2^2 - c2;
end

%% third order upwind

uLD(i) = u(i-1) - u(i);
uRD(i) = u(i+1) - u(i);
aR(i) = -(uLD + uRD)/24;
bR(i) = (uRD - uLD)/2./hc;
cR(i) = (uRD + uLD)./(2*hc.^2);

uright(i) = u(i) + aR(i) + bR(i) .* (hc/2) + cR.*(hc/2).^2;
uright(i) = u(i); % 1st order
RHSA(i) = -uright(i) + uright(i-1) ;



%%
RHS1 = A * subs(RHSA, u, u);
RHSM = A * subs(RHSA, u, um);

UM = a1 * u0 + a2 * u + r0 * d1 + RHS1 * d2;

RHSMM = simplify(expand(subs(RHSM, um, UM)));
RHSMM = collect(RHSMM,u(i + (-4:2)) )

RHSMM_M4 = diff(RHSMM(i), u(i-4))
RHSMM_M3 = diff(RHSMM(i), u(i-3))
RHSMM_M2 = diff(RHSMM(i), u(i-2))
RHSMM_M1 = diff(RHSMM(i), u(i-1))
RHSMM_00 = diff(RHSMM(i), u(i-0))
RHSMM_P1 = diff(RHSMM(i), u(i+1))
RHSMM_P2 = diff(RHSMM(i), u(i+2))



opTau = RHS1 * b3 + RHSMM * b2;
opTau = collect(opTau,u(i + (-4:2)) );
opTauCoefs = jacobian(opTau(i), u(i + (-4:2)));

opTauCoefsMajor = opTauCoefs;
opTauCoefsMajor((-4:2) == 0) = opTauCoefsMajor((-4:2) == 0) - 1;
opTauCoefsMajor((-4:2) == -1) = opTauCoefsMajor((-4:2) == -1);
opTauG = opTauCoefsMajor * exp(1i * (-4:2)' * kappa);
opTauGU2R2c2 = subs(opTauG, [a1,a2,d1,d2,b1,b2,b3], [a1c,a2c,d1c,d2c,b1c,b2c,b3c]);

c2test = 1/2;
opTauGU2R2TestC0d5 = subs(opTauGU2R2c2, c2, c2test)


figure(1); clf; hold on;

testingAs = [2,4,8,16];
markers= {"+","x","d","*","o"}
for i = 1:numel(testingAs)
testingA= testingAs(i);
opTauGU2R2Test = subs(opTauGU2R2TestC0d5/A, [c2,A], [c2test,testingA])
fplot(symfun(imag(-opTauGU2R2Test/1i), kappa), [0,pi], "DisplayName", ...
    sprintf("$\\mathrm{CFL}_t=%g$", testingA), "Marker", markers{i})
end

xlabel("\kappa")
ylabel("Im(\kappa^*)")
xlim([0,pi]);
ylim([-1.5,0.5])
setAx(0)
L = leg;
grid on;
exportgraphics(gcf,"HM3_U2R2050_KappaS.pdf",'ContentType','vector','BackgroundColor','none')


function setAx(toff)
posOrig = [0.1100 0.1400];
set(gca,'FontName','Times New Roman', "FontSize", 12, ...
    "Position", [posOrig, 1- posOrig * 2] ,"PositionConstraint", "innerposition")
set(gcf,"PaperOrientation", "landscape", "PaperUnits", "inches", "PaperSize", [6,4.5])
set(gcf,"Position", [[100,100]+toff*[1,0.2],[560, 420]])
end
function L = leg
L = legend("Interpreter","latex");
legend("boxoff")
end



