#include<iostream>
using namespace std;
double s=1,p=1;
int main(){
    int i,n;
    for(i=1;i<=n;i++){
        if(i%2==0){
            s+=1/(1.0*i);
        }
        else{
            p*=i;
            s+=p;
        }
    }
    cout<<s;
    return 0;
}
