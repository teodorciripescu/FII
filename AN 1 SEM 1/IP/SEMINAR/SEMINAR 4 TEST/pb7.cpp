#include<iostream>
#include<cstring>
using namespace std;
struct vector {
    unsigned int nrElemente;
    char element[200];
};
int frecventa[1000];
//problema 7 subpunctul a
void maximAparitii(vector v){
    int i,maxx=0,k;
    for(k=0;k<v.nrElemente;k++)frecventa[v.element[k]]++;
    for(k=0;k<1000;k++){
            //cout<<frecventa[k]<<" ";
            if(maxx>frecventa[k])maxx=frecventa[k];}
    for(k=0;k<1000;k++)if(frecventa[k]==maxx )cout<<(int)v.element[k]<<" ";
}

int main(){
    vector v;
    cin>>v.nrElemente;
    for(int i=0;i<v.nrElemente;i++)cin>>v.element[i];
    maximAparitii(v);
    return 0;
}

