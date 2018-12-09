#include<iostream>
using namespace std;
int nCifra(int n){
    int i=1,ii=1,gata=0,nrCifrei;//ii - copia lui i
    long long nrCifre;
    while(!gata){
        ii = i;
        nrCifrei=0;
        while(ii){
            ii/=10;
            nrCifrei++;
        }
        nrCifre+=nrCifrei;
        if(n<nrCifre)gata=1;
        else i++;
    }
    cout<<i;
    //if()
    gata=0;
    int cifra;
    while(!gata){
        cifra = i%10;
        i/=10;
        nrCifre--;
        if(n==nrCifre)gata=0;
    }
    return cifra;
    //for(int contor=;i<)
}
int main(){
    int n;
    cin>>n;
    cout<<nCifra(n);
    return 0;
}
