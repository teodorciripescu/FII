#include<iostream>
#include<fstream>
using namespace std;
ifstream f("listasimpla.in");
struct node{
    float info;
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
void inserareInLista(lista &L,float val,int poz){
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
void insereazaMedie(lista &L){
    node *p,*q;
    float medie;
    int poz=0;
    p=L;
    while(p&&poz-1<=n){
        medie = (p->info + p->urm->info)/2.0;
        cout<<medie<<" ";
        inserareInLista(L,medie,poz+1);
        p=p->urm;
        poz+=2;
    }
    cout<<endl;
}
int main(){
    lista L;
    f>>n;
    initList(L);
    afiseazaLista(L);
    insereazaMedie(L);
    afiseazaLista(L);
    return 0;
}

