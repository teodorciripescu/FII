//pb3 subpct a
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
int esteCrescatoareSauDescrescatoare(lista L){
    node *p;
    int cresc=1,descresc=1;
    p=L;
    while(p){
        if(p->urm!=NULL){
            if(p->info < p->urm->info){
                descresc=0;
            }
            if(p->info > p->urm->info){
                cresc=0;
            }
        }
        p=p->urm;
    }
    if(cresc)cout<<"lista este crescatoare";
    else if(descresc)cout<<"lista este descrescatoare";
    else cout<<"lista nu este nici crescatoare, nici descrescatoare";
    cout<<endl;
}
int main(){
    lista L;
    f>>n;
    initList(L);
    afiseazaLista(L);
    esteCrescatoareSauDescrescatoare(L);
    return 0;
}

