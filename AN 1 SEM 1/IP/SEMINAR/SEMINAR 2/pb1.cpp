#include<iostream>
using namespace std;
int main(){
    int suma=0,i,n,fact=1;
    cin>>n;
    for(i=1;i<=n;i++){
        fact=fact*i;
        suma+=fact;
        //cout<<"s="<<s<<endl;
        //cout<<"fact="<<fact<<endl;
    }
    cout<<suma;
    return 0;
}
