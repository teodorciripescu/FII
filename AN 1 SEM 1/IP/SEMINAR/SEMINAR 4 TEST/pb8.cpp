#include<iostream>
#include<cstring>
using namespace std;
int frecventa[200];
//problema 8 subpunctul a
void litereCareNuApar(char sir[]){
    int i;
    for(int k=0;k<strlen(sir);k++)
        for(i=97;i<=122;i++){
            if(sir[k]==(char)i)frecventa[i]=1;
        }
        for(i=97;i<=122;i++)if(frecventa[i]==0)cout<<(char)i<<" ";
}

int main(){
    char sir[100];
    cin.get(sir,100);
    cin.get();
    litereCareNuApar(sir);
    return 0;
}
