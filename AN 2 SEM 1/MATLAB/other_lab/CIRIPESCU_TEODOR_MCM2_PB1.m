n = 4;
A = [8 -1 3 -1; 
     -1 6 2 0;
     3 2 9 1;
     -1 0 1 7];
 n = 3;
A = [2 -1 1; 
     -1 2 1;
     1 -1 2];
getCoefficients(A, n);

 function [coefficients, invA] = getCoefficients(A, n)
    coefficients=zeros(1,n);
    Bk = A;
    pk = trace(Bk);
    coefficients(1) = pk;
    I = eye(n);
    
    for i = 2:n
        Bnm1 = Bk;
        Bk = A * (Bk - pk * I);
        pk=(1/i)*trace(Bk);
        coefficients(i)=pk;
    end
    disp(coefficients);
    if(det(A) ~= 0)
        invA = (1/pk) * (Bnm1 - (coefficients(n-1)) * I);
        format rat;
        disp(invA);
    end
    
    coefficients = [1,-coefficients];
    disp(coefficients);
 end
