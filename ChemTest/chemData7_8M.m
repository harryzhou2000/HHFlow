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
% g/mol
Ms = transpose([2,32,18,1,16,17,28]);
names = {"H2", "O2", "H2O", "H", "O", "OH", "N2"};

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
