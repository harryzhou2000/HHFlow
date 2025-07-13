


method = 1;
c2 = 0.5;
Theta = 1;
beta = 1.4;

% plotOneMap(1, 1, 0.5, 1, 0);
% plotOneMap(2, 1, 0.5, 1, 0.5);
% plotOneMap(3, 1, 0.5, 1, 1);
plotOneMap(1, 1, 0.5, 1, 0, true,1);
plotOneMap(2, 1, 0.5, 1, 0.5, true,1);
plotOneMap(3, 1, 0.5, 1, 1, true,1);
%%
figure(777772); clf; cla;
[rSampM,iSampM, MuReMax, GGAbs] = plotOneMap(77777, 1, 0.5, 1, 0.6, false, 1);
figure(777772); hold on;
c = contour(rSampM,iSampM, GGAbs, [-inf, 1, inf], "-x", "LineWidth", 1, "LineColor", '#0072BD',...
    "DisplayName","U2R2 $c_2=0.5\ \beta = 0.6$");
[rSampM,iSampM, MuReMax, GGAbs] = plotOneMap(77777, 1, 0.5, 1, 0.8, false, 1);
figure(777772); hold on;
c = contour(rSampM,iSampM, GGAbs, [-inf, 1, inf], ":", "LineWidth", 1, "LineColor", '#D95319',...
    "DisplayName","U2R2 $c_2=0.5\ \beta = 0.8$");
[rSampM,iSampM, MuReMax, GGAbs] = plotOneMap(77777, 1, 0.5, 1, 1, false, 1);
figure(777772); hold on;
c = contour(rSampM,iSampM, GGAbs, [-inf, 1, inf], "--", "LineWidth", 1, "LineColor", '#EDB120',...
    "DisplayName","U2R2 $c_2=0.5\ \beta = 1$");
[rSampM,iSampM, MuReMax, GGAbs] = plotOneMap(77777, 1, 0.5, 1, 1.2, false, 1);
figure(777772); hold on;
c = contour(rSampM,iSampM, GGAbs, [-inf, 1, inf], "-.", "LineWidth", 1, "LineColor", '#7E2F8E',...
    "DisplayName","U2R2 $c_2=0.5\ \beta = 1.2$");
L = leg;
setAx(700)

axis equal;
xlim([-5,10]);
ylim([0,10])
xlabel("$\mathrm{Re}(z)$","Interpreter","latex");
ylabel("$\mathrm{Im}(z)$","Interpreter","latex");
% plotOneMap(3, 1, 0.5, 1, 0.99, false)
exportgraphics(gcf, ...
            sprintf("HM3_U2R205_GGSRegions.pdf") ...
            ,'ContentType','vector','BackgroundColor','none')
%%
figure(777771); clf; cla;
[rSampM,iSampM, MuReMax, GGAbs] = plotOneMap(77777, 2, 0.25, 1, 0.75, false, 1);
figure(777771); hold on;
c = contour(rSampM,iSampM, GGAbs, [-inf, 1, inf], "-x", "LineWidth", 1, "LineColor", '#0072BD',...
    "DisplayName","U2R1 $c_2=0.25\ \beta = 0.75$");
[rSampM,iSampM, MuReMax, GGAbs] = plotOneMap(77777, 2, 0.5, 1, 0.75, false, 1);
figure(777771); hold on;
c = contour(rSampM,iSampM, GGAbs, [-inf, 1, inf], ":", "LineWidth", 1, "LineColor", '#D95319',...
    "DisplayName","U2R1 $c_2=0.5\ \beta = 0.75$");
[rSampM,iSampM, MuReMax, GGAbs] = plotOneMap(77777, 2, 0.25, 1, 1, false, 1);
figure(777771); hold on;
c = contour(rSampM,iSampM, GGAbs, [-inf, 1, inf], "--", "LineWidth", 1, "LineColor", '#EDB120',...
    "DisplayName","U2R1 $c_2=0.25\ \beta = 1$");
[rSampM,iSampM, MuReMax, GGAbs] = plotOneMap(77777, 2, 0.5, 1, 1, false, 1);
figure(777771); hold on;
c = contour(rSampM,iSampM, GGAbs, [-inf, 1, inf], "-.", "LineWidth", 1, "LineColor", '#7E2F8E',...
    "DisplayName","U2R1 $c_2=0.5\ \beta = 1$");
L = leg;
setAx(500)

axis equal;
xlim([-5,10]);
ylim([0,10])
xlabel("$\mathrm{Re}(z)$","Interpreter","latex");
ylabel("$\mathrm{Im}(z)$","Interpreter","latex");
% plotOneMap(3, 1, 0.5, 1, 0.99, false)
exportgraphics(gcf, ...
            sprintf("HM3_U2R1_GGSRegions.pdf") ...
            ,'ContentType','vector','BackgroundColor','none')

%% U2R2
lineSpecs = ["-x","-+","-o","-d",".-","-s",":"];
methods = [1,  1,   2,   2,  3,  3,  3];
c2s =     [0.5,0.55,0.25,0.5,0.5,0.5,0.5];
Thetas =  [1,  1,   1,   1,  0.25,1, 4];
names = ["U2R2 $c_2=0.5$", "U2R2 $c_2=0.55$",...
    "U2R1 $c_2=0.25$", "U2R1 $c_2=0.5$", ...
    "U3R1 $\Theta=0.25$", "U3R1 $\Theta=1$", "U3R1 $\Theta=4$"];
search_results = {};

% for i = 1:numel(methods)
for i = [1]
[betas, mm, gg, ggArg] = getNumSearch(methods(i), c2s(i), Thetas(i));
mm = min(mm, 1);
gg = min(gg, 2);

[mm_min, i_mm_min] = min(mm, [], "all");
[gg_min, i_gg_min] = min(gg, [], "all");

beta1 = betas{1};
beta2 = betas{2};

search_results{end+1} = [mm_min, beta1(i_mm_min), beta2(i_mm_min); gg_min, beta1(i_gg_min), beta2(i_gg_min) ];


figure(1114 + i); clf; cla; hold on;
p = surf(betas{1},betas{2}, mm, "LineStyle","none");
setAx(100 + i * 100);
figure(2114 + i); clf; cla; hold on;
p = surf(betas{1},betas{2}, gg, "LineStyle","none");
setAx(120 + i * 100)

% figure(3114 + i); clf; cla; hold on;
% plot(betas{1},betas{2}, ggArg, "LineStyle","none");
% setAx(140 + i * 100)
end

% figure(1114);
% L = leg;
% setAx(100)
% grid on;
% ylim([-0.5,0.5]);
% xlim([0,2]);
% xlabel("$\beta$","Interpreter","latex");
% ylabel("$\mu^*_M$","Interpreter","latex");
% exportgraphics(gcf, ...
%             sprintf("HM3_Methods_SearchMu_Extended.pdf") ...
%             ,'ContentType','vector','BackgroundColor','none')
% 
% 
% figure(2114);
% L = leg;
% setAx(200)
% grid on;
% ylim([0,2]);
% xlim([0,2]);
% xlabel("$\beta$","Interpreter","latex");
% ylabel("$G_{GS,M}$","Interpreter","latex");
% exportgraphics(gcf, ...
%             sprintf("HM3_Methods_SearchGGS_Extended.pdf") ...
%             ,'ContentType','vector','BackgroundColor','none')
% 
% 
% figure(3114);
% L = leg;
% setAx(300)
% grid on;
% ylim([0,pi]);
% xlim([0,2]);
% xlabel("$\beta$","Interpreter","latex");
% ylabel("Arg $G_{GS,M}$","Interpreter","latex");
% exportgraphics(gcf, ...
%             sprintf("HM3_Methods_SearchGGSArg_Extended.pdf") ...
%             ,'ContentType','vector','BackgroundColor','none')

%%
function [rSampM,iSampM, MuReMax, GGAbs] = plotOneMap(fig, method, c2, Theta, beta, draw, type)

if (~exist("draw", "var"))
    draw  = true;
end
if (~exist("type", "var"))
    type  = 0;
end

if numel(beta) == 1
    beta = [beta, 0, 1];

else
    assert(numel(beta) == 3, "need 1 or 3 dim beta!");
end

[a0, a1, a2, b1,b2,b3, d1,d2] = f_getDITR(method, c2, Theta);
P = [1,                beta(1);...
    beta(2) * beta(3), 1 * beta(3)];

A = P * [-1, a2; 0, -1];
B = P * [0, d2; b2, b3];

test_range = 10;
rSamp = linspace(-test_range,test_range,201);
iSamp = linspace(-test_range,test_range,201);
[rSampM,iSampM] = meshgrid(rSamp,iSamp);
zSampM = rSampM + 1i * iSampM;
MuReMax = fMuAbs(zSampM, A, B);
GGAbs = fGGSAbs(zSampM, A, B);


figure(fig); clf; cla; hold on;

if(type == 0)
    p = surf(rSampM,iSampM, MuReMax, "LineStyle","none");
else
    p = surf(rSampM,iSampM, GGAbs, "LineStyle","none");
end
view([0,90])
if(type == 0)
    c = contour(rSampM,iSampM, MuReMax, [-inf, 0, inf], "LineWidth", 1, "LineColor", "black");
    axis equal;
    axis tight;
    xlabel("$\mathrm{Re}(\mu')$","Interpreter","latex");
    ylabel("$\mathrm{Im}(\mu')$","Interpreter","latex");
    clim([-1,1]);
else
    c = contour3(rSampM,iSampM, GGAbs, [-inf, 1, inf], "LineWidth", 1, "LineColor", "black");
    axis equal;
    axis tight;
    xlabel("$\mathrm{Re}(z)$","Interpreter","latex");
    ylabel("$\mathrm{Im}(z)$","Interpreter","latex");
    clim([0,4]);
end

grid on;

colorbar;
setAx(fig * 100 + 500);
% L = leg;
if draw
    if(type == 0)
        exportgraphics(gcf, ...
            sprintf("HM3_Method%d_C%g_Theta%g_Beta%g_%g_%g_TauMu.pdf", method, c2, Theta, beta) ...
            ,'ContentType','vector','BackgroundColor','none')
    else
        exportgraphics(gcf, ...
            sprintf("HM3_Method%d_C%g_Theta%g_Beta%g_%g_%g_GGS.pdf", method, c2, Theta, beta) ...
            ,'ContentType','vector','BackgroundColor','none')
    end
end
end




% title(sprintf("c_2 = %.1g", alphatest))
function [betaOut, mm, gg, ggArg] = getNumSearch(method, c2, Theta, beta3)

useGPU = true;

if nargin < 4
    beta3 = 1.0;
end

% SAMPLING ZETA (MU)
test_range = 10;
rSamp = linspace(-test_range,0,101);
rSamp1 = linspace(-test_range,test_range,201);
iSamp = linspace(-test_range,test_range,201);
[rSampM,iSampM] = meshgrid(rSamp,iSamp);
[rSampM1,iSampM1] = meshgrid(rSamp1,iSamp);
zSampM = rSampM + 1i * iSampM;
zSampM1 = rSampM1 + 1i * iSampM1;

thetas = linspace(pi/2, 3*pi/2, 201);
Rs = 10.^(1:10);
farSamps = Rs(:) * exp(1i * thetas);

zSamps = [0;zSampM(:); farSamps(:)];
zSamps1 = [zSampM1(:)];
% plot(zSamps,".")

% SAMPLING BETA
betaTests = linspace(0,2,101);
beta1Tests = linspace(-1,1,101);

[betaM, beta1M] = meshgrid(betaTests, beta1Tests);

betaOut = {betaM, beta1M};


mm = nan(size(betaM));
gg = nan(size(betaM));
ggArg = nan(size(betaM));

[a0, a1, a2, b1,b2,b3, d1,d2] = f_getDITR(method, c2, Theta);

if useGPU
    betaM = gpuArray(betaM);
    beta1M = gpuArray(beta1M);
    zSamps = gpuArray(zSamps);
    zSamps1 = gpuArray(zSamps1);
end

for i = 1:numel(betaM)

    beta = betaM(i);
    beta1 = beta1M(i);

    P = [1, beta; beta1 * beta3, 1 * beta3];
    A = P * [-1, a2; 0, -1];
    B = P * [0, d2; b2, b3];
    MuReMax = fMuAbs(zSamps, A, B);
    GGSAbs = fGGSAbs(zSamps, A, B);
    GGSAbs1 = fGGSAbs(zSamps1, A, B);
    argsZnStab = [0; abs(angle(zSamps1(GGSAbs1 >= 1)))];

    mm(i) = max(MuReMax);
    gg(i) = max(GGSAbs);
    ggArg(i) = max(argsZnStab);
    if mod(i, 200) == 0
        fprintf("Search %d / %d\n", i, numel(betaM));
    end
end





end


function MuReMax = fMuAbs(muIn, A, B)
shape = size(muIn);

M = A(:) + B(:) * transpose(muIn(:));
Delta = (M(1,:) - M(4,:)).^2 + 4 * M(2,:) .* M(3,:);

lam1 = 0.5 * (M(1,:) + M(4,:)) + 0.5 * sqrt(Delta);
lam2 = 0.5 * (M(1,:) + M(4,:)) - 0.5 * sqrt(Delta);
MuReMax = max(real(lam1), real(lam2));
MuReMax = reshape(MuReMax, shape);


end

function GGAbs = fGGSAbs(muIn, A, B)
shape = size(muIn);

M = A(:) + B(:) * transpose(muIn(:));
GGAbs = abs(M(3,:) .* M(2,:)./M(1,:) ./ M(4,:));
GGAbs = reshape(GGAbs, shape);

end

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
