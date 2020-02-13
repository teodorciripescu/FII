e=exp(1);
syms x(t) y(t) z(t) e;

eq0=diff(x,t)==z(t);
eq1=diff(y,t)==6*x(t)-5*z(t);
eq2=diff(z,t)==-6*x(t)+2*y(t)+5*z(t)+e.^(2*t);

eqs=[eq0, eq1, eq2];
disp("Sist de ecuatii:");
disp(eq0);
disp(eq1);
disp(eq2);

syssol=dsolve(eqs);
ySol(t) = syssol.y;
xSol(t) = syssol.x;

disp("x(t a,b,c)");
disp(xSol(t));
disp("y(t a,b,c)");
disp(ySol(t));