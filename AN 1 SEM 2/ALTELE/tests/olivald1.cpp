#include<iostream>
#include<fstream>
using namespace std;
ifstream in("varfuri.in");
ofstream out("varfuri.out");
int v[10000],n,m,c,s,i,nrmax;
int main(){
in>>c;
in>>n;
for(i=1;i<=n;++i)in>>v[i];

in.close();

if(c==1){

m=v[1];
for(i=2;i<=n;++i)
    if(v[i]>m)m=v[i];

for(i=1;i<=n;++i)
    if(m==v[i])++nrmax;
s=m*nrmax;

out<<m<<" ";
out<<s;

}
if(c==2){








}



out.close();
return 0;}
