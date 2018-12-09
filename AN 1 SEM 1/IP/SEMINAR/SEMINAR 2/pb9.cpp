//e^x
#include<iostream>
#include<cmath>
using namespace std;
double p=1,f=1,n,f0,f1,s0,s1,s2,x,i;
int main(){
    //e^x
    cin>>x;
    s0=1;s1=1+(p*x)/(f*f);
    i=2;
    while(abs(s1-s0)>0.001){
        s0=s1;s1=s0+(p*x)/(f*f);
        p*=x;
        f*=i;
        i++;

    }
    cout<<s1;
    return 0;
}
