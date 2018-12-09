//problema 1 subpunctul b
#include<iostream>
#include<cmath>
using namespace std;

long double calculareLogaritm(long double x){
    long double ln1=0,ln2=0,i=1;
    do{
        ln2=ln1;
        ln1-=x/(long double)i;
        i++;
    }while(abs(ln1-ln2)>0.0001);
    return ln2;
}
int main(){
    long double x;
    cin>>x;
    cout<<calculareLogaritm(1-x);
    return 0;
}
