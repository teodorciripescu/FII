#include<iostream>
using namespace std;

int main(){
    int suma=0,fact=1,n;
    cin>>n;
    for(int i=1;i<=n;i++){
        fact*=i;
        suma+=fact;
        cout<<i<<"!+";
    }
    cout<<"\b= "<<suma;
    return 0;
}

