#include<iostream>
using namespace std;
struct node{
    int info;
    node *urm;
    };
typedef node* lista;
int n;
void citire(lista &l){
    node *p,*q;
    cin>>n;
    l=new node;
    cin>>l->info;
    p=new node;
    l->urm=p;
    for(int i=1;i<n;i++){
        cin>>p->info;
        q=new node;
        p->urm=q;
        p=q;
    }
}
void afisare(lista l){
node *p;
p=l;
for(int i=0;i<n;i++)
{
    cout<<p->info<<" ";
    p=p->urm;
}
}
int main(){
lista l;
citire(l);
afisare(l);
return 0;}
