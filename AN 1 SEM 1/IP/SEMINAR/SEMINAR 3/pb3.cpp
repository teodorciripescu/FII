#include<iostream>
using namespace std;

unsigned long long nTermenFibRec(unsigned int n,unsigned int f1,unsigned int f2){
    if(n==1)return f1 + f2;
    nTermenFibRec(n-1,f2,f1+f2);
}
unsigned long long nTermenFibRec2(unsigned int n){
    if(n==0)return 0;
    if(n==1)return 1;
    return nTermenFibRec2(n-1) + nTermenFibRec2(n-2);
}

int main(){
    unsigned long long nr;
    int n;
    cin>>n;
    n-=2;
    nr = nTermenFibRec(n,1,1);
    cout<<nr;
    return 0;
}

