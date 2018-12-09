#include<iostream>
using namespace std;
//problema 6 subpunctul a
int nrCifre(int n){
    int i=0;
    while(n){
        n/=10;
        i++;
    }
    return i;
}
int numarMaxim(int n){
    int nrC,i,ii,p=1,rest,nn,maxx;
    nrC = nrCifre(n);
    maxx = n/10;
    for(i=1;i<nrC;i++){
        p*=10;
        nn=n;
        rest = n % p;
        nn/=p*10;
        nn*=p;
        nn+=rest;
        if(nn>maxx)maxx=nn;
    }
    return maxx;
}

int main(){
    int n;
    cin>>n;
    cout<<numarMaxim(n);
    return 0;
}
