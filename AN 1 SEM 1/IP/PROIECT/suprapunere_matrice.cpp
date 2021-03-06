#include<iostream>
#include<fstream>
using namespace std;
int BOARD[10][10];
int L1[3][3]={0,1,0,0,1,0,0,1,1};
void loadTable(){
    int n;
    ifstream f("start_table.in");
    f>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)f>>BOARD[i][j];
    f.close();
}
printB(){
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++)cout<<BOARD[i][j]<<" ";
        cout<<endl;
        }
}
printL(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)cout<<L1[i][j]<<" ";
        cout<<endl;
        }
}
bool canMakeMove(int givenX,int givenY,int L1[3][3],int playerNmb,int opponentNmb){
    int i, j, samePosEncountered=0;
    int iBoard = givenX-1, jBoard = givenY - 1, nBoard = givenX + 1;
    if(iBoard<0 || jBoard<0) return false;
    //printB();cout<<endl;printL();cout<<endl;
    for(i=0; i<3; i++, iBoard++){
        for(j=0, jBoard = givenY - 1; j<3 && jBoard<=nBoard; j++, jBoard++){
            //cout<<BOARD[i1][j1]<<" ";
            if(  (BOARD[iBoard][jBoard]==5
                ||BOARD[iBoard][jBoard]==3
                ||BOARD[iBoard][jBoard]==opponentNmb) && L1[i][j]==playerNmb) return false;
            //if(BOARD[i1][j1]==2&&L1[i][j]==1) return false;
            //if(BOARD[i1][j1]==3&&L1[i][j]==1) return false;
            if(BOARD[iBoard][jBoard]==playerNmb && L1[i][j]==playerNmb){
                samePosEncountered++;
                //cout<<samePosEncountered<<"<-sameposencountered\n";
                if(samePosEncountered==4) return false;}

        }
        //cout<<endl;
    }
    //cout<<BOARD[n1][n1]<<" ";
    return 1;
}
void makeMove(int givenX,int givenY,int L1[3][3],int playerNmb){
    int i, j, iBoard=givenX-1, jBoard=givenY-1, nBoard=givenX+1;
        for(int i=0;i<6;i++)
            for(int j=0;j<6;j++)if(BOARD[i][j]==1)BOARD[i][j]=0;

        for(i=0; i<3; i++, iBoard++){
            for(j=0, jBoard=givenY-1; j<3 && jBoard<=nBoard; j++, jBoard++){
                 cout<<BOARD[iBoard][jBoard]<<" ";
                //if(BOARD[iBoard][jBoard]==playerNmb && L1[i][j]==0) BOARD[iBoard][jBoard]=0;
                if(BOARD[iBoard][jBoard]==0 && L1[i][j]==playerNmb) BOARD[iBoard][jBoard]=1;
            }cout<<endl;
            }
    printB();
}

int main(){
loadTable();
int givenX=3, givenY=1;
bool ableToMove = canMakeMove(givenX,givenY,L1,1,2);
cout<<endl<<ableToMove<<endl;
if(ableToMove) makeMove(givenX, givenY,L1,1);
return 0;
}


/*
bool canMakeMove(int givenX,int givenY,int L1[3][3]){
int i,j;int test=0,ok=0;int isDifPos=0;int samePosEncountered=0;

int i1=givenX-1,n1=i1+2,j1=givenY-1;
if(i1<0 || j1<0)return 0;
cout<<"test"<<test++<<endl;
printB();cout<<endl;printL();
for(i=0;i<3;i++)
{
    for(j=0;j<3;j++){
        cout<<"i1="<<i1<<", j1="<<j1<<endl;
        cout<<"test"<<test++<<endl;
        if(BOARD[i1][j1]==5&&L1[i][j]==1)return false;
        if(BOARD[i1][j1]==2&&L1[i][j]==1) return false;
        if(BOARD[i1][j1]==3&&L1[i][j]==1) return false;
        if(BOARD[i1][j1]==1)samePosEncountered++;
        if(samePosEncountered==4){
                //cannot move fix

                return false;
        }
        if((BOARD[i1][j1]==0&&L1[i][j]==1)){
            cout<<"ok"<<++ok<<"\n";
            BOARD[i1][j1]=9;
cout<<"test"<<test++<<endl;
        }
        isDifPos=1;
        j1++;
        if(j1==n1-1){
            j1=givenY-1;
            i1++;
        }
    }
}
//clean matrix
for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(BOARD[i][j]==1)BOARD[i][j]=0;
            else if(BOARD[i][j]==9)BOARD[i][j]=1;
        }
        }
printB();
}
*/
