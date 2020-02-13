m = input("dati m");
n = input("dati n");
a = [1 2 3 4 5; 
     1 1 1 1 1;
     -1 2 3 -4 5;
     1 2 3 4 5;
     5 4 3 2 1];
suma1=0;
suma2=0;
for i1 = 1:m
    for i2 = i1+1:m
       for j =1:n
           if (a(i2,j) >= 0)
                suma1 = suma1 + a(i1, j);
           else
               suma1 = suma1 - a(i1, j);
           end
           if (a(i1,j) >= 0)
                suma2 = suma2 + a(i2, j);
           else
               suma2 = suma2 - a(i2, j);
           end
       end
       if (suma1 == suma2)
           d = ["linii gemene:",i1,i2];
           disp(d);
           sume = [suma1, suma2];
           disp(sume);
       end
       suma1=0;
       suma2=0;
    end
end