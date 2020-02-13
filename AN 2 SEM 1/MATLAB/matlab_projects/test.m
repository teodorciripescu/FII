a = 10;
b = 23;
cos(pi*a/b);
x = [1,2,3,4,5,6];
y = [pi/4,pi/3,pi/2,pi,2*pi/3,2*pi];
z = 1:20;
sin(x);
%plot(x,sin(y))
%plot(z.^4)
fplot(@(g) g^2)
print("matlab")