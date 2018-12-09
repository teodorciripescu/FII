#include<iostream>
#include<cmath>
using namespace std;

long double generatePi(){
long double pi1=0,pi2=0;
long long i=0,numitor=1;
do{
    pi2=pi1;
    if(i==0){
        pi1+=4/(long double)numitor;
        numitor+=2;
        i=1;
    }
    else if(i==1){
        pi1-=4/(long double)numitor;
        numitor+=2;
        i=0;
    }
}while(abs(pi1-pi2)>0.00000001);
return pi2;
}


int main(){
    cout<<generatePi();
    return 0;
}
