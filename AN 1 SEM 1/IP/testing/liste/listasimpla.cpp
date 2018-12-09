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
int main(){
    lista L;
    f>>n;
    initList(L);
    afiseazaLista(L);
    inserareInLista(L,3,2);
    afiseazaLista(L);
    return 0;
}
