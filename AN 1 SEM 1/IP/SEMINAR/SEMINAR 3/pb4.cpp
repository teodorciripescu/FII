#include<iostream>
using namespace std;
unsigned int ackermann(unsigned int m, unsigned int n){
    if(m==0)return ackermann(m-1,1);
    //inca o cond?
    return ackermann(m-1,ackermann(m,n-1));
}
int main(){
    cout<<ackermann(2,4);
    return 0;
}

