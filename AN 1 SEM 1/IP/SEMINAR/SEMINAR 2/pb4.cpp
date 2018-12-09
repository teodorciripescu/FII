//cmmdc dintre m multe nrs
/*
4
12 36 60 102
output:6
*/
#include<iostream>
using namespace std;


int cmmdc2(int a,int b){
    while(a!=b){
        if(a>=b)a=a-b;
        else b=b-a;
    }
    return a;
}
int main(){
    int nr1,nr2,n,divComun;
    cin>>n>>nr1;
    for(int i=2;i<=n;i++){
        cin>>nr2;
        divComun = cmmdc2(nr1,nr2);
        nr1 = divComun;
    }
    cout<<divComun;
    return 0;
}
