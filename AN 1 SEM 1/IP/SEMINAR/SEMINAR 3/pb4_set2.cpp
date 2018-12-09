#include<iostream>
#include<cstring>
using namespace std;

void cuvLungMaxima(char sir[100]){
    int lungime,maxLungime=0;
    char sirMax[100];
    char *p;
    p=strtok(sir," ");
    while(p){
        lungime = strlen(p);
        if(lungime>maxLungime){
            maxLungime=lungime;
            strcpy(sirMax,p);
        }
        p=strtok(NULL," ");
    }
    cout<<sirMax;
}

int main(){
    char sir[100];
    cin.get(sir,100);
    cin.get();
    cuvLungMaxima(sir);
    return 0;
}

