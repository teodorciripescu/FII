#include<iostream>
using namespace std;
struct nod{
    int info;
    nod *urm;
};
typedef nod *lista;

void citesteListaSimpla(lista& L) {
    unsigned int nrElemente;
    cout<<"Dati numarul de elemente: ";
    cin>>nrElemente;
    int element;
    L=NULL; lista p;
    for (unsigned int i=1; i<=nrElemente; i++)
    {
        //cout<<"Dati elementul al "<<i<<"-lea: ";
        cin>>element; p=new nod; p->info=element;
        p->urm=L;L=p;
    }
}
void afiseazaListaSimpla(lista L) {
    lista p; p=L;
    while (p!=NULL) {
        cout<<p->info<<" ";
        p=p->urm;
    }
    cout<<"\n";
}
//pb1
void adaugaLaFinal(lista &L,int nr){
nod *p;
p=new nod;
p->info=nr;
p->urm = L;
L=p;
}
//pb7
void insereazaNrInainteaVal(lista &L,int nr,int val){
    lista p; p = L;
    nod *q,*r;
    while(p!=NULL){
        if(p->urm->info==val){
           cout<<"DA\n";
           q=new nod;
           q->info=nr;
           //p=q;
           r=p->urm;
           q->urm=r;
           p->urm=q;

           //q->urm=p;
           //p->urm=q;
        }
        p=p->urm;
    }
}
void inserare(int val,int nr,lista L){
nod *p,*q,*r;
p=L;
if(L->info==val){
    p=new nod;
    p->info=nr;
    p->urm=L;
    L=p;
    p=p->urm->urm;
}
q=p->urm;
while(q!=NULL){
    if(q->info==val){
        r=new nod;
        r->info=nr;
        p->urm=r;
        r->urm=q;
        p=r;
    }
    p=p->urm;
    q=q->urm;
    }
}

int sumaPare(nod *L){
    //7
    //3 4 8 7 10 9 2
    int s=0;
    nod *r,*p,*q;
    p=q=L;
    while(q->urm!=NULL){
        r=p;
        p=p->urm;
        q=p->urm;
        if(p->info%2==1)
        {
            if(r->info%2==0 && p->info%2==0)s+=p->info;
        }
    }
    return s;
}
int perechiConsecutive(lista L) {
    lista p; p=L;
    int perechi=0;
    int elem=0;
    while (p!=NULL) {
        //cout<<p->info<<" ";
        if(p->info==p->urm->info){
            elem++;
        }
        else if(elem>0){
            perechi++;
            cout<<"gasit pereche cu "<<elem + 1<<" elemente\n";
            elem=0;
        }
        p=p->urm;
    }
    return perechi;
}
int main(){
    lista L;
    citesteListaSimpla(L);
    afiseazaListaSimpla(L);
    //adaugaLaFinal(L,2123);
    //cout<<sumaPare(L);
    //insereazaNrInainteaVal(L,2,3);
    //inserare(2,3,L);//input: 1 2 3 4
    perechiConsecutive(L);
    afiseazaListaSimpla(L);
    return 0;
}
