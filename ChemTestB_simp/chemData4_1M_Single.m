% Spiegler et.al
% 

%"2H2+O2=2H20  "   

% ABCABC(r,i): 
% front/back reaction ABCABC Arrhenius coefficients: [Af,Bf,Cf,Ab,Bb,Cb]
% Af(r): mol/s * mol^(-sum(nuf(r,:))-Ntri(r)), B: 1, C: 1/T

ABCABC = [
    5.50E+15 -1 51987 1.80E+12 -1 0
];

% Ms(s):
% s_th species molecular weight:
% kg/mol
Ms = transpose([2,32,18,40])*1e-3;
names = {"H2", "O2", "H2O", "Ar"};

% viscosity derivation here
% k_sehs = 

% nuf/b(r,s): 
% front/back reaction stoichiometric number for r_th reaction
% and s_th  species
% 1
nuf = [...
         2      1      0     0
];


nub = [...
         0      0      2     0
];

% Ntri(r): r_th reaction's three-body switch
Ntri = transpose([0]);

% Ctri(r,s): r_th reaction's three-body coefficient for s_th species
Ctri = [...
 0 0 0 0 0 0 0
];


asA = [...
    3.6084 0 0 0 0 0;...
    3.6084 0 0 0 0 0;...
    3.6084 0 0 0 0 -241826.0;...
    3.6084 0 0 0 0 0;];

asB = [...
    3.6084 0 0 0 0 0;...
    3.6084 0 0 0 0 0;...
    3.6084 0 0 0 0 -241826.0;...
    3.6084 0 0 0 0 0;];

asA = [asA(:,end),asA(:,1:end-1)];
asB = [asB(:,end),asB(:,1:end-1)];

% asB(:,1) = asB(:,1) - asA(:,1);
% asA(:,1) = 0; %zero zero - start fit !bad!

% asA(:,1) = 0;
% asB(:,1) = 0;
% asB = asA;
% asA(:,3:end) = 0;
% asB(:,3:end) = 0;




chem_setting.chem = "chem_exp";
M.pK = 1e4;


