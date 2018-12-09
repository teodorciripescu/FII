//PROBLEMA 1 SUBPUNCTUL A
#include<iostream>
#include<fstream>
using namespace std;
ifstream f("listasimpla.in");
struct node{
    int info;
    node *urm;
};
typedef node *lista;
int n;
void initList(lista &L){
    L=NULL;L=new node;f>>L->info;
    node *p,*q;p=new node;f>>p->info;L->urm=p;
    for(int i=2;i<n;i++){
        q=new node;
        f>>q->info;
        p->urm = q;
        p=q;
    }
    f.close();
}
void afiseazaLista(lista L){
    node *p;
    p=L;
    while(p){
        cout<<p->info<<" ";
        p=p->urm;
    }
    cout<<endl;
}
void inserareInLista(lista &L,int val,int poz){
    node *p=L,*q,*r;
    int i=0;
    while(p){
        if(i==poz-1){
            q=new node;
            q->info=val;
            r=p->urm;
            p->urm=q;
            q->urm=r;
            return;
        }
        p=p->urm;
        i++;
    }
}
int esteNrPrim(int x){
    if(x<2)return 0;
    if(x==2)return 1;
    if(x%2==0)return 0;
    for(int i=3;i*i<=x;i+=2)if(x%i==0)return 0;
    return 1;
}
void stergePrime(lista &L){
    node *p,*q;
    p=L;
    if(esteNrPrim(p->info)){
        q=p->urm;
        delete p;
    }
    q=p->urm;
    while(p!=NULL){

        if(esteNrPrim(p->urm->info)){
        cout<<p->urm->info<<" ";
        q=p->urm->urm;
        p->urm=p->urm->urm;
        p->urm=q;
        }
    p=p->urm;
    }
}
int main(){

    lista L;
    f>>n;
    initList(L);
    afiseazaLista(L);
    stergePrime(L);
    afiseazaLista(L);
    return 0;
}
