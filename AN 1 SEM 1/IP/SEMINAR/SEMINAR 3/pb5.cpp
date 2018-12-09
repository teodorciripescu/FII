#include<iostream>
using namespace std;
bool palindrom(int n){
int ogl=0,cn=n;
while(n){
    ogl=ogl*10+n%10;
    n/=10;
}
if(ogl==cn)return true;
return false;
}
int main(){
    int n;
    cin>>n;
    cout<<palindrom(n);
    return 0;
}

