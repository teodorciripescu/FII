a = input("dati a ");
b = input("dati b ");
c = input("dati c ");

delta1 = b^2 -4*a*c; % a b c
delta2 = a^2 - 4*c*b; %c a b
delta3 = c^2 - 4*b*a; %b c a
if(delta1>=0 && delta2>=0 && delta2>=0)
    disp("au toate radacinile reale simultan");
else
    disp("nu au toate radacinile reale simultan");
end
