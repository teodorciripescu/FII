/*
radacina patrata a numarului real pozitiv x, ca limita a sirului de numere an,
definit astfel a1=1,an=1/2*(a(n-1) + x/a(n-1))
se pot calc repetitiv termeni ai sirului, pana cand diferenta dintre ult 2 termeni este destul de mica
nu folosiv vectori /recursiv
*/
#include<iostream>
#include<cmath>
using namespace std;
double x,radical,a0=1,a1=1;
double a(double precedent){
    return (1/2.0) * (precedent + x/precedent);
}
int main(){
    cin>>x;
    a1=a(a0);
    while(abs(a1-a0)>0.001){
        a0=a1;
        a1=a(a0);
        //cout<<a1<<endl;
    }
    cout<<a1;
    return 0;
}
