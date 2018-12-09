#include<iostream>
using namespace std;

unsigned long long nTermenFib(unsigned int n){
    unsigned long long f1=1,f2=1,f3;
    int cnt=2;
    while(n!=cnt){
        f3 = f2 + f1;
        f1 = f2;
        f2 = f3;
        cnt++;
    }
    return f3;
}

int main(){
    unsigned long long nr;
    int n;
    cin>>n;
    nr = nTermenFib(n);
    cout<<nr;
    return 0;
}

