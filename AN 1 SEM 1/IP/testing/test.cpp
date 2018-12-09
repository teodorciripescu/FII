#include<iostream>
#include<cstring>
using namespace std;

void f1(){
int k,j=11,z=0;
for(k=j+1,k<=15;;k++)z++;
cout<<z;
}void f1a(){
int k,j=11,z=0;
for(k=j+1;k<=15,1+1;k++)z++;
for(k=j+1;k<=15,0;k++)z++;
cout<<z;
}
void f2(){
    int v[5]={0,1,2,3,4};int val=4;
    int (*var)[5];
    cout<<&val<<endl;

    for(int i=0;i<5;i++)cout<<var[i]<<" ";
   // *var=v;
    for(int i=0;i<5;i++)cout<<var[i]<<" ";
    int *varr[5];
    for(int i=0;i<5;i++)cout<<varr[i]<<" ";
}

void f4(){

const int tablou[2][3][3] = { 0, 1, 2, 3, 4, 5, 6, 7, 8,
9, 10, 11, 12, 13, 14 };
int const (*p)[2][3][3] = &tablou;
cout << *(*(*p)[1] + 2) << endl;
}
void f5(){
char sport[] = "cricket";
int x = 1, y;
y = x++ + ++x;
cout << sport[++y]<<endl;
}
void f6(){
char sport[] = "cricket";
int x = 1, y;
y = x++ + ++x;
cout << sport[++y]<<endl;
}
void f7(){
int i=1,x;
x=i++;
cout<<x<<" "<<i;
}
void f8(){
int *p,a=5;
p=&a;
*p++;
cout<<*p;
}
void f3(){
int i=1,j=1,k=1,l=1,m=1,n=1,i1=1,j1=1;
int a,b,c,d,e,f,g,h;
//a=++i + i++;
a=++i + i++;
b=j++ + ++j;
c=k++ + 1;
d=1 + l++;
e=n++ + m++;
f=++i1 + j1++;
cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<f<<endl;
cout<<sizeof(int*)<<" "<<sizeof(int)<<endl;
cout<<sizeof(double*)<<" "<<sizeof(double)<<endl;
cout<<sizeof(long long*)<<" "<<sizeof(long long)<<endl;
cout<<sizeof(short int*)<<" "<<sizeof(short int)<<endl;
}
int main(){
//f1();
//f2();
f3();
//f4();
//f5();
//f6();
//f7();
//f8();
//f1a();
return 0;}
