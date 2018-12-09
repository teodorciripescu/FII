#include<iostream>
using namespace std;

int main(){
    int prod=1,n;
    cin>>n;
    double suma=0;
    for(int i=1;i<=n;i++){
        if(i%2==0){
            suma+=1/(double)i;
        }
        else{
            prod*=i;
            suma+=prod;
        }
    }
    cout<<suma;
    return 0;
}

