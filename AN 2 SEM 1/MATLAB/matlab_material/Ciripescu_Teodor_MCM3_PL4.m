subplot(4,4,[1 2 3]);
x=-5:0.2:5;
f=cos(x.^(2)-3) .* exp(-x+1);
g=-sin(x-2).*log(x.^4+5);
plot(x,f,'g',x,g,'m');

subplot(4,4,[4 8 12]);%tr de con
r = linspace(1.4,2*pi) ;
th = linspace(0,2*pi) ;
[R,T] = meshgrid(r,th) ;
X = R.*cos(T);
Y = R.*sin(T);
Z = R ;
surf(X,Y,Z);

subplot(4,4,[5 9 13]);

subplot(4,4,6);%sfera
[x3,y3,z3]=sphere;
surf(x3,y3,z3);

subplot(4,4,7);%prisma pentagonala

subplot(4,4,10);
subplot(4,4,11);
subplot(4,4,[14 15 16]);
[x8,y8] = meshgrid(-5:0.5:5);
Z = x8.^4 + y8.^5;
meshz(X,Y,Z);
