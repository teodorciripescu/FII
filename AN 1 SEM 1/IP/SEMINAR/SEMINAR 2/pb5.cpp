#include<iostream>
#include<cmath>
using namespace std;
int a,b;
double f(double x){
    return x+1;
}

int main(){
    double m,a,b;
    double v;
    cin>>a>>b;
    m=(a+b)/2;
    while(abs(f(m))>0.001){
        m=(a+b)/2;
        v=f(m);
        if(f(a)*v<0)b=m;
                else a=m;
    }
    //tre sa dea aprox -1
    cout<<m;
    return 0;
}
