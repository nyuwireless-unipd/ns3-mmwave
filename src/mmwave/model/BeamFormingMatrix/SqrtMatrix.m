%For LOS, LSP is following the order of [SF,K,DS,ASD,ASA,ZSD,ZSA].
%For NLOS, LSP is following the order of [SF,DS,ASD,ASA,ZSD,ZSA].

%LSP = [ASDvsDS, ASAvsDS, ASAvsSF, ASDvsSF, DSvsSF, ASDvsASA, ASDvsK, ASAvsK, DSvsK, SFvsK, 
%       ZSDvsSF, ZSAvsSF, ZSDvsK, ZSAvsK, ZSDvsDs, ZSAvsDs, ZSDvsASD, ZSAvsASD, ZSDvsASA, ZSAvsASA ZSDvsASA]
%LSP = [0 0 0 0 -0.5 0 0 0 0 0 0 -0.8 0 0 0 0 0.5 0 0 0 0]; %RMA LOS
%LSP = [-0.4 0 0 0.6 -0.5 0 NaN NaN NaN NaN 0 -0.4 NaN NaN -0.5 0 0.5 -0.1 0 0 0]; %RMA NLOS

%LSP = [0.4 0.8 -0.5 -0.5 -0.4 0 0 -0.2 -0.4 0 0 -0.8 0 0 -0.2 0 0.5 0 -0.3 0.4 0]; %UMa LOS
%LSP = [0.4 0.6 0 -0.6 -0.4 0.4 NaN NaN NaN NaN 0 -0.4 NaN NaN -0.5 0 0.5 -0.1 0 0 0];%UMa NLOS
%LSP = [0.4 0 0.53 0 -0.5 0 NaN NaN NaN NaN 0 0.4 NaN NaN 0 -0.53 0 0.42 0 0 0];%UMa O2I

%LSP = [0.5 0.8 -0.4 -0.5 -0.4 0.4 -0.2 -0.3 -0.7 0.5 0 0 0 0 0 0.2 0.5 0.3 0 0 0]; % UMi LOS
%LSP = [0 0.4 -0.4 0 -0.7 0 NaN NaN NaN NaN 0 0 NaN NaN -0.5 0 0.5 0.5 0 0.2 0]; %UMi NLOS
%LSP = [0.4 0 0.53 0 -0.5 0 NaN NaN NaN NaN 0 0.4 NaN NaN 0 -0.53 0 0.42 0 0 0]; % UMi O2I

%LSP = [0.6 0.8 -0.5 -0.4 -0.8 0.4 0 0 -0.5 0.5 0.2 -0.1 0 0.1 0.1 0.2 0.2 0.2 0.1 0.3 0.2]; %Office LOS
%LSP = [0.4 0 -0.4 0 -0.5 0 NaN NaN NaN NaN 0 -0.1 NaN NaN -0.1 -0.1 0.3 0.2 0.1 0 0.4]; %Office NLOS

disp(length(LSP));

C = eye(7);
%C matrix should be symetric, only assign value to top-right half entries.
C(1,2) = LSP(10);
C(1,3) = LSP(5);
C(1,4) = LSP(4);
C(1,5) = LSP(3);
C(1,6) = LSP(11);
C(1,7) = LSP(12);

C(2,3) = LSP(9);
C(2,4) = LSP(7);
C(2,5) = LSP(8);
C(2,6) = LSP(13);
C(2,7) = LSP(14);

C(3,4) = LSP(1);
C(3,5) = LSP(2);
C(3,6) = LSP(15);
C(3,7) = LSP(16);

C(4,5) = LSP(6);
C(4,6) = LSP(17);
C(4,7) = LSP(18);

C(5,6) = LSP(19);
C(5,7) = LSP(20);

C(6,7) = LSP(21);
%C copy the value to bottom-left.
C = C+C'-eye(size(C));

%Check whether the correlations between k and other parameters are NaN. NaN
%means NLOS, and we only need a 6x6 matrix.
if isnan(C(2,1))
C = C([1,3:end],[1,3:end]);
end
%compute the sqrtC with cholesky decomposition.

sqrtC = chol(C,'lower');
disp(sqrtC);
%same the matrix into a txt file. You may directly copy the matrix into the
%channel class file.
fileID = fopen('matrix.txt','w');
[r c] = size(sqrtC);
for i = 1:r
    fprintf(fileID,'{');
    for j = 1:c
        if j==c
           fprintf(fileID,'%g',sqrtC(i,j));
        else
           fprintf(fileID,'%g, ',sqrtC(i,j));
        end
    end
    fprintf(fileID,'},\n');
end
fclose(fileID);
