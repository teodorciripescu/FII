//pb6 subpct b
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

int esteNrPrim(int x){
    if(x<2)return 0;
    if(x==2)return 1;
    if(x%2==0)return 0;
    for(int i=3;i*i<=x;i+=2)if(x%i==0)return 0;
    return 1;
}
int suma;
void sumaPrime(arbore a){
    int nr;
    if (!esteArboreNul(a))
    {
        //cout<<a->info<<", ";
        nr=a->info;
        if(esteNrPrim(nr))suma+=nr;
        sumaPrime(a->st);
        sumaPrime(a->dr);
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
    sumaPrime(a);
    cout<<endl<<suma;
    return 0;
}

