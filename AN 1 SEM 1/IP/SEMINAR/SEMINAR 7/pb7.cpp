//pb7
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


int reprezArboreString(arbore a){
    if(!esteArboreNul(a)){


    reprezArboreString(a->st);
    if(a->st)cout<<"("<<a->st->info;
    cout<<"-"<<a->info<<"-";
    if(a->dr)cout<<a->dr->info<<")";
    reprezArboreString(a->dr);

    }
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
    ///folosim parcurgere de tip SRD(inordine)
    reprezArboreString(a);cout<<endl;

    return 0;
}