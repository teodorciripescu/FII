#include<iostream>
using namespace std;
struct vector{
    unsigned int nrElemente;
    int element[200];
};
bool esteOrdonat(vector v){
    int i;
    for(i=0;i<v.nrElemente - 1;i++)if(v.element[i]>v.element[i+1])return false;
    return true;
}
int main(){
    vector v;
    cin>>v.nrElemente;
    for(int i=0;i<v.nrElemente;i++)cin>>v.element[i];
    cout<<esteOrdonat(v);
    return 0;
}

