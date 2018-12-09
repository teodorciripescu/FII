//pb9
#include<iostream>
using namespace std;
//declarare
typedef int tipDate;
struct nod {
    tipDate info;
    struct nod *st; struct nod *dr;
};
typedef nod * arbore;
//arb binar de cautare - initializare
int esteArboreNul(arbore a)
{
   return (a==NULL);
}
void initArbore(arbore& a)
{
   if (!esteArboreNul(a)) a=NULL;
}
//adaugare nod in arbore binar de cautare
bool adaugaLaArboreElement(arbore& a, tipDate el) {
    if (esteArboreNul(a)) {
        a=new nod;
        if (!a) return false;
        a->info = el; a->st = NULL; a->dr = NULL;
        return true;
    }
    else if (el < a->info)
        return adaugaLaArboreElement(a->st, el);
    else
        return adaugaLaArboreElement(a->dr, el);
}

int maxi;
int inaltimeArboreMax(arbore a,int inalt){
    if(a==NULL)return 0;
    if(a)
        if(inalt>maxi)maxi=inalt;
    inaltimeArboreMax(a->st,inalt+1);
    inaltimeArboreMax(a->dr,inalt+1);
}

int v[100];
void produsParePeNivele(arbore a,int niv){
    if(!esteArboreNul(a)){
        if(a->info % 2 == 0){
        if(v[niv]==0)v[niv]=1;
        v[niv]*=a->info;
        cout<<endl<<v[niv]<<endl;
            //cout<<a->info;
        }
        produsParePeNivele(a->st,niv+1);
        produsParePeNivele(a->dr,niv+1);
    }
}
void afisProdusParePeNivele(arbore a){
    cout<<endl;
    for(int i=0;i<=maxi;i++)cout<<v[i]<<" ";
    cout<<endl;
}

int main()
{
    //cout << "Arbori binari de cautare\n\n";
    arbore a; initArbore(a);
    unsigned int i; unsigned int n;
    tipDate x;
    //cout<<"Dati numarul de elemente ale arborelui: ";
    cin>>n;
    for (i=1; i<=n; i++) {
        //cout<<"Dati elementul al "<<i<<"-lea: ";
        cin>>x; adaugaLaArboreElement(a,x);
    }
    produsParePeNivele(a,0);
    inaltimeArboreMax(a,0);
    afisProdusParePeNivele(a);
    return 0;
}

