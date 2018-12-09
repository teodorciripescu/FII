//pb 4 subpct a
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


void sortarePrinModificareInfo(lista &L){
    int sortat,i,aux;
    node *p;
    do{
        sortat=1;
        p=L;
        while(p && p->urm){
            if(p->info > p->urm->info){
                aux = p->info;
                p->info = p->urm->info;
                p->urm->info = aux;
                sortat = 0;
            }
            //cout<<p->info<<" ";
            p=p->urm;
        }
    }while(!sortat);
}
int main(){
    lista L;
    f>>n;
    initList(L);
    afiseazaLista(L);
    sortarePrinModificareInfo(L);
    afiseazaLista(L);
    return 0;
}

