% Spiegler et.al
% 

%"H2+M1=H+H+M1  "   5.50E+15 -1 51987 1.80E+12 -1 0
%"H2O+M2=OH+H+M2"   7.20E+15 -1 59340 4.00E+11 -1 0
%"OH+M3=O+H+M3  "   5.20E+18 -1.5 59386 4.40E+14 -1.5 0
%"O2+M4=O+O+M4  "   8.50E+15 -1 50830 7.10E+12 -1 0
%"O2+H=OH+O     "   5.80E+10 0 9059 5.30E+09 0 503
%"O+H2=OH+H     "   8.40E+10 0 10116 2.00E+10 0 2600
%"OH+H2=H2O+H   "   2.20E+11 0 8455 1.50E+10 0 0
%"OH+OH=H2O+O   "   7.50E+10 0 5586 3.00E+10 0 4429

% ABCABC(r,i): 
% front/back reaction ABCABC Arrhenius coefficients: [Af,Bf,Cf,Ab,Bb,Cb]
% Af(r): mol/s * mol^(-sum(nuf(r,:))-Ntri(r)), B: 1, C: 1/T

ABCABC = [
    5.50E+15 -1 51987 1.80E+12 -1 0
7.20E+15 -1 59340 4.00E+11 -1 0
5.20E+18 -1.5 59386 4.40E+14 -1.5 0
8.50E+15 -1 50830 7.10E+12 -1 0
5.80E+10 0 9059 5.30E+09 0 503
8.40E+10 0 10116 2.00E+10 0 2600
2.20E+11 0 8455 1.50E+10 0 0
7.50E+10 0 5586 3.00E+10 0 4429
];

% Ms(s):
% s_th species molecular weight:
% kg/mol
Ms = transpose([2,32,18,1,16,17,40])*1e-3;
names = {"H2", "O2", "H2O", "H", "O", "OH", "Ar"};

% viscosity derivation here
% k_sehs = 

% nuf/b(r,s): 
% front/back reaction stoichiometric number for r_th reaction
% and s_th  species
% 1
nuf = [...
         1      0      0     0     0   0      0
         0      0      1     0     0   0      0
         0      0      0     0     0   1      0
         0      1      0     0     0   0      0
         0      1      0     1     0   0      0
         1      0      0     0     1   0      0
         1      0      0     0     0   1      0
         0      0      0     0     0   2      0
];


nub = [...
         0      0      0     2     0   0      0
         0      0      0     1     0   1      0
         0      0      0     1     1   0      0
         0      0      0     0     2   0      0
         0      0      0     0     1   1      0
         0      0      0     1     0   1      0
         0      0      1     1     0   0      0
         0      0      1     0     1   0      0
];

% Ntri(r): r_th reaction's three-body switch
Ntri = transpose([1 1 1 1 0 0 0 0]);

% Ctri(r,s): r_th reaction's three-body coefficient for s_th species
Ctri = [...
 2.5 1 16 1 1 1 1
 2.5 1 16 1 1 1 1
 2.5 1 16 1 1 1 1
 2.5 1 16 1 1 1 1
 0 0 0 0 0 0 0
 0 0 0 0 0 0 0
 0 0 0 0 0 0 0
 0 0 0 0 0 0 0
];


asA = [...
    3.298E+00 8.249E-04 -8.143E-07 -9.475E-11 4.135E-13 -1.013E+03;...
    3.213E+00 1.127E-03 -5.756E-07 1.314E-09 -8.769E-13 -1.005E+03;...
    3.387E+00 3.475E-03 -6.355E-06 6.969E-09 -2.507E-12 -3.021E+04;...
    2.500E+00 0.000E+00 0.000E+00 0.000E+00 0.000E+00 2.547E+04;...
    2.946E+00 -1.638E-03 2.421E-06 -1.603E-09 3.891E-13 2.915E+04;...
    3.637E+00 1.851E-04 -1.676E-06 2.387E-09 -8.431E-13 3.607E+03;...
    2.5 0 0 0 0 0];

asB = [...
    2.991E+00 7.001E-04 -5.634E-08 -9.232E-12 1.583E-15 -8.350E+02
    3.698E+00 6.135E-04 -1.259E-07 1.775E-11 -1.136E-15 -1.234E+03
    2.672E+00 3.056E-03 -8.730E-07 1.201E-10 -6.392E-15 -2.990E+04
    2.500E+00 0.000E+00 0.000E+00 0.000E+00 0.000E+00 2.547E+04
    2.542E+00 -2.755E-05 -3.103E-09 4.551E-12 -4.368E-16 2.923E+04
    2.883E+00 1.014E-03 -2.277E-07 2.175E-11 -5.126E-16 3.887E+03
    2.5 0 0 0 0 0];

asA = [asA(:,end),asA(:,1:end-1)];
asB = [asB(:,end),asB(:,1:end-1)];

% asB(:,1) = asB(:,1) - asA(:,1);
% asA(:,1) = 0; %zero zero - start fit !bad!

% asA(:,1) = 0;
% asB(:,1) = 0;
% asB = asA;
% asA(:,3:end) = 0;
% asB(:,3:end) = 0;

%warning! i don't know why original bad here: large and necgative

chem_setting.chem = "chem";




