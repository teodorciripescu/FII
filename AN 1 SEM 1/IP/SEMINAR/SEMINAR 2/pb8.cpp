#include<iostream>
using namespace std;
int T,T2,n,nr;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>nr;
        T+=nr;
        T2+=nr*nr;
    }
    cout<<T<<" "<<T2;
    for(i=1;i<=n;i++){
        S+=i;
        SP+=i*i;
    }
    d1=S-T;
    d2=SP-T2;
    b=(d1*d2-d2)/(-2*d1);
    a=d1+b;
    cout<<a<<b;
    return 0;
}
