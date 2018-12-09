#include<iostream>
using namespace std;

int sumaCifre(int q){
    int suma=0;
    while(q){
        suma+=q%10;
        q/=10;
    }
    return suma;
}

int deosebit(int p){
    int sumaQ;
    for(int q=0;q<=p;q++){
        sumaQ = sumaCifre(q);
        if(q+sumaQ == p) return 1;
    }
    return 0;
}

int main(){
    int p,test;
    cin>>p;
    test = deosebit(p);
    if(test) cout<<p<<" este deosebit";
        else cout<<p<<" nu este deosebit";
    return 0;
}
