#include<iostream>
using namespace std;

unsigned short numarDivizoriPrimi(unsigned int nr){
int div,nrdiv=0;
if(nr%2==0) {
    nrdiv++;
    while(nr%2==0)nr/=2;
}
for(div=3;div<=nr;div+=2){
    if(nr%div==0){
        nrdiv++;
        while(nr%div==0)nr/=div;
    }
}
return nrdiv;
}
unsigned short primeDivisors(unsigned int left, unsigned int right){
unsigned short nrMaxDiv=0,numere=0,aux;
for(int i=left;i<=right;i++){
    aux = numarDivizoriPrimi(i);
    if(nrMaxDiv<aux){
        nrMaxDiv=aux;
        numere=1;
    }
    else if(nrMaxDiv==aux)numere++;
}
return numere;
}

int main(){
    unsigned int left, right;
    cin>>left>>right;
    cout<<primeDivisors(left,right);
    return 0;
}

