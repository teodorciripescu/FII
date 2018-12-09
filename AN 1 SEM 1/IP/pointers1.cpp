#include<iostream>
using namespace std;
int f(int &a){
cout<<a;
}
int main(){
int a=10;
f(a+3);
return 0;}
