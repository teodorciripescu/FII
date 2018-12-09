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
//cautarea unui element in arbore
bool existaElementInArbore(arbore a, tipDate el)
{
    if (!esteArboreNul(a)) // sau if (a)
    {
        if (a->info==el) return true;
        else
          if (el<a->info)
             return existaElementInArbore(a->st, el);
          else
             return existaElementInArbore(a->dr, el);
    }
    else
        return false;
}
//RSD (de obicei ea este folosita)
void parcurgereInPreordine(arbore a)
{
    if (!esteArboreNul(a))
    {
        cout<<a->info<<", ";
        parcurgereInPreordine(a->st);
        parcurgereInPreordine(a->dr);
    }
}
//SDR
void parcurgereInPostordine(arbore a)
{
    if (!esteArboreNul(a))
    {
        parcurgereInPostordine(a->st);
        parcurgereInPostordine(a->dr);
        cout<<a->info<<", ";
    }
}
//SRD
void parcurgereInInordine(arbore a)
{
    if (!esteArboreNul(a))
    {
        parcurgereInInordine(a->st);
        cout<<a->info<<", ";
        parcurgereInInordine(a->dr);
    }
}
//la partial ne poate intreba de:
//care este parcurgearea in ... a unui arbore

int suma,nrimp;//el impare
float media;
void sumaImpare(arbore a){
    int nr;
    if (!esteArboreNul(a))
    {
        //cout<<a->info<<", ";
        nr=a->info;
        if(nr%2==1){ suma+=nr;nrimp++;}
        sumaImpare(a->st);
        sumaImpare(a->dr);
    }
}
void mediaImpare(){
    media=suma/(float)nrimp;
}
int maxi;
int inaltimeArboreMax(arbore a,int inalt){
    if(a==NULL)return 0;
    if(a)
        if(inalt>maxi)maxi=inalt;
    inaltimeArboreMax(a->st,inalt+1);
    inaltimeArboreMax(a->dr,inalt+1);
}
int mini=999;
int inaltimeArboreMin(arbore a,int inalt){
    if(a==NULL)return 0;
    if(a){

    inaltimeArboreMin(a->st,inalt+1);
    inaltimeArboreMin(a->dr,inalt+1);
     if(inalt<mini)mini=inalt;
     }
}
void inaltimeArboreMin2(arbore a,int nr){
    if(!esteArboreNul(a)){
    inaltimeArboreMin2(a->st,nr+1);
    inaltimeArboreMin2(a->dr,nr+1);
    }
    else if(nr<mini)mini=nr;
}
//det daca exista un drum de la nodul root pana la orice nod frunza, a.i. suma valorilor nodurilor sa fie = cu sum
int ok=0;
int sumOfElemsEqualsSum(arbore a,int sumOfElems,int sum){
    if(!esteArboreNul(a)){
    sumOfElemsEqualsSum(a->st, sumOfElems + a->info, sum);
    sumOfElemsEqualsSum(a->dr, sumOfElems+ a->info, sum);
    }
    else if(sumOfElems==sum)ok=1;
}

int reprezArboreString(arbore a){
    if(!esteArboreNul(a)){
    cout<<"("<<a->info;
    reprezArboreString(a->st);
    reprezArboreString(a->dr);
    cout<<")";
    }
}
///*
int v[100];
void sumePeNivele(arbore a,int niv){
    if(!esteArboreNul(a)){
        v[niv]+=a->info;
        sumePeNivele(a->st,niv+1);
        sumePeNivele(a->dr,niv+1);
    }
}
void afisSumaPeNivele(arbore a){
    for(int i=0;i<=90;i++)cout<<v[i]<<" ";
    cout<<endl;
}
//*/
//input:
//n= 9
//6 3 9 1 5 2 7 12 10

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
    //cout<<"\nElementele parcurse in inordine sunt ordonate crescator:\n";
    //parcurgereInInordine(a);
    //sumaImpare(a);cout<<"suma: "<<suma<<endl;
    //mediaImpare();cout<<"media: "<<media<<endl;
    inaltimeArboreMax(a,0);cout<<"inaltime arbore max: "<<maxi<<endl;
    inaltimeArboreMin2(a,0);cout<<"inaltime arbore min: "<<mini-1<<endl;
    cout<<"sum of elems equals sum= ";
    sumOfElemsEqualsSum(a,0,37);
    cout<<ok<<endl;
   // reprezArboreString(a);cout<<endl;
    sumePeNivele(a,0);
    afisSumaPeNivele(a);
    return 0;
}
