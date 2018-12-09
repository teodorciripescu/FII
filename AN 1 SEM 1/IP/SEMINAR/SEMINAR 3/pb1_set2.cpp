#include<iostream>
#include<fstream>
using namespace std;

#define MAX_ARRAY_LENGTH 100
#define MAX_ARRAY_LENGTH_LONG 1000

struct vector{
unsigned int length;
int values[MAX_ARRAY_LENGTH];
};

struct matrix{
unsigned int lines;
unsigned int columns;
unsigned int values[MAX_ARRAY_LENGTH][MAX_ARRAY_LENGTH];
};
/*
void citire(matrix v1, matrix v2){
ifstream f("pb1_set2.in");
f>>v1.lines>>v1.columns;
int i,j;
for(i=0;i<v1.lines;i++)
    for(j=0;j<v1.columns;j++)f>>v1.values[i][j];
f>>v1.lines>>v1.columns;
for(i=0;i<v2.lines;i++)
    for(j=0;j<v2.columns;j++)f>>v2.values[i][j];
cout<<"FINISHED READING FILE"<<endl;
}
*/
void citire(vector v1,vector v2){
ifstream f("pb1_set2.in");
f>>v1.length;
for(int i=0;i<v1.length)f>>v1.values;
f>>v2.length;
for(int i=0;i<v2.length)f>>v2.values;
f.close();
}
unsigned int compare(vector v1, vector v2){
    //sort(&v1);
   // sort(&v2);
    int i=0,j=0;
    //verifica egalitatea
    if(v1.length==v2.length){
        for(i=0;i<v1.length;i++)
            if(v1.values[i]!=v2.values[i])return 3;
        return 1;
    }
    if(v1.length<v2.length){
        i=0;
        j=0;
        while(i<v1.length && j<v2.length){
            if(v1.values[i]==v2.values[j]){
                i++;
                j++;
            }
            else j++;
        }
        if(i==v1.length)return 1;
            return 3;
    }
    //mai e
}

int main(){
    vector v1,v2;
    citire(v1,v2);
    cout<<compare(v1,v2);
    return 0;
}

