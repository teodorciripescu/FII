#include <iostream>
#include <winbgim.h>
#include <stdlib.h>
#include <fstream>

#define PREVIEW_SIZE 3
#define BOARD_SIZE 7
#define P1_COLOR GREEN
#define P2_COLOR YELLOW
#define NEUTRAL_COLOR WHITE
#define OUTLINE COLOR(255,100,0)
#define BACKGROUND BLUE
using namespace std;

struct matrixCoords{
    int x1,y1,x2,y2;
};

//va trebui o functie care verifica la fiecare mutare starea jocului(daca este onGoing/s-a terminat)

void loadTable();void printB();
void drawMatrix(int top, int left, int previewSquares,int laturaPreview);
void drawBoardMatrix(int B[BOARD_SIZE+3][BOARD_SIZE+3], matrixCoords M[BOARD_SIZE][BOARD_SIZE]);
void generateCoordsForMatrix(matrixCoords M[BOARD_SIZE][BOARD_SIZE], int squares, int top, int left, int latura);
void generateCoordsForPreviewMatrix(matrixCoords M[PREVIEW_SIZE][PREVIEW_SIZE], int squares, int top, int left, int latura);
void drawPreviewMatrix(int L[PREVIEW_SIZE][PREVIEW_SIZE], matrixCoords M[PREVIEW_SIZE][PREVIEW_SIZE],int color);


matrixCoords boardCoords[BOARD_SIZE][BOARD_SIZE], previewCoordsL1[PREVIEW_SIZE][PREVIEW_SIZE], previewCoordsL2[PREVIEW_SIZE][PREVIEW_SIZE];
int previewL1top,previewL1left,previewL2top,previewL2left;
int BOARD[BOARD_SIZE+3][BOARD_SIZE+3],latura,L1[PREVIEW_SIZE][PREVIEW_SIZE]={0,1,0,0,1,0,0,1,1},L2[PREVIEW_SIZE][PREVIEW_SIZE]={1,1,0,0,1,0,0,1,0},turn;
int boardTop, boardLeft, boardWidth, boardHeight, boardLatura, boardLine, boardColumn;
int previewSquares=3, laturaPreview;

bool gata;

void initiateCanvas(int width, int height, int squares){
    cout<<"Initializing canvas...\n";
    int top, left,i;
    top = (getmaxx() - width) / 2;
    left =  (getmaxy() - height) / 2;
    cout<<"Drawing matrix from "<<top<<" (top), "<<left<<" (left).\n";
    setbkcolor(BACKGROUND);
    clearviewport();
    latura = width/squares;
    setcolor(OUTLINE);
    boardTop = top; boardLeft = left; boardWidth = width; boardHeight = height; boardLatura = latura;
    drawMatrix(top,left,squares,latura);
    generateCoordsForMatrix(boardCoords,squares,top,left,latura);
    drawBoardMatrix(BOARD,boardCoords);

    /*
    for(i=0;i<squares+1;i++){
        line(top+i*latura, left, top + i*latura, left + latura * squares);
        line(top, left + i*latura, top + latura * squares, left + i*latura);
    }
    */
    cout<<"Drawing move previews.\n";
    setcolor(OUTLINE);
    laturaPreview=latura/2;
    top/=squares;
    previewL1top=top;previewL1left=left;
    drawMatrix(previewL1top, previewL1left, previewSquares, laturaPreview);
    generateCoordsForPreviewMatrix(previewCoordsL1, previewSquares, previewL1top, previewL1left, laturaPreview);
    drawPreviewMatrix(L1,previewCoordsL1,P1_COLOR);

    top = getmaxx() - laturaPreview*(previewSquares+3);
    previewL2top=top;previewL2left=left;
    drawMatrix(previewL2top, previewL2left, previewSquares, laturaPreview);
    printB();
    //aici crapa BOARD
    generateCoordsForPreviewMatrix(previewCoordsL2, previewSquares, previewL2top, previewL2left, laturaPreview);
    //
    printB();
    drawPreviewMatrix(L2,previewCoordsL2,P2_COLOR);
    loadTable();
}
void drawMatrix(int top, int left, int squares, int latura){
    int i;
    for(i=0;i<squares+1;i++){
        //linii verticale
        line(top+i*latura, left, top + i*latura, left + latura * squares);
        //linii orizontale
        line(top, left + i*latura, top + latura * squares, left + i*latura);
    }

}
void generateCoordsForMatrix(matrixCoords M[BOARD_SIZE][BOARD_SIZE], int squares, int top, int left, int latura){
    int i,j;
    setcolor(OUTLINE);
    for(i=1;i<=squares+1;i++)
        for(j=1;j<=squares+1;j++){
            M[i][j].x1 = top + latura*(i-1);
            M[i][j].y1 = left + latura*(j-1);
            M[i][j].x2 = top + latura*i;
            M[i][j].y2 =  left + latura*j;
    }
}
void generateCoordsForPreviewMatrix(matrixCoords M[PREVIEW_SIZE][PREVIEW_SIZE], int squares, int top, int left, int latura){
    int i,j;
    setcolor(OUTLINE);
    for(i=0;i<=squares;i++)
        for(j=0;j<=squares;j++){
            M[i][j].x1 = top + latura*i;
            M[i][j].y1 = left + latura*j;
            M[i][j].x2 = top + latura*(i+1);
            M[i][j].y2 =  left + latura*(j+1);
    }
}


void cyclicPreviewInterchange(int &a, int &b, int &c, int &d){
   int aux = a;
   a = b;
   b = c;
   c = d;
   d = aux;
}
void rotatePreviewMatrixClockwise(int L[PREVIEW_SIZE][PREVIEW_SIZE],matrixCoords coordsL[PREVIEW_SIZE][PREVIEW_SIZE],int color){
    int n=PREVIEW_SIZE;
    for(int i=0; i<n/2; i++)
       for(int j=0; j<(n+1)/2; j++)
           cyclicPreviewInterchange(L[i][j], L[n-1-j][i], L[n-1-i][n-1-j], L[j][n-1-i]);
    drawPreviewMatrix(L,coordsL,color);
}
void rotatePreviewMatrixCounterClockwise(int L[PREVIEW_SIZE][PREVIEW_SIZE],matrixCoords coordsL[PREVIEW_SIZE][PREVIEW_SIZE],int color){
    int n=PREVIEW_SIZE;
    for(int i=0; i<n/2; i++)
       for(int j=0; j<(n+1)/2; j++)
           cyclicPreviewInterchange(L[j][n-1-i], L[n-1-i][n-1-j], L[n-1-j][i], L[i][j]);
    drawPreviewMatrix(L,coordsL,color);
}
void flipPreviewMatrix(int L[PREVIEW_SIZE][PREVIEW_SIZE],matrixCoords coordsL[PREVIEW_SIZE][PREVIEW_SIZE],int color){
    for(int i=0,aux; i<PREVIEW_SIZE; i++) {
        aux = L[i][0];
        L[i][0] = L[i][PREVIEW_SIZE-1];
        L[i][PREVIEW_SIZE-1] = aux;
    }
    drawPreviewMatrix(L,coordsL,color);
}
void printMatrix(int L[3][3], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<L[i][j]<<" ";
        cout<<endl;
            }
    cout<<endl;
}


void drawBoardMatrix(int B[BOARD_SIZE+3][BOARD_SIZE+3], matrixCoords M[BOARD_SIZE][BOARD_SIZE]){
    int i,j;
    for(i=1;i<BOARD_SIZE+1;i++)
            for(j=1;j<=BOARD_SIZE+1;j++){
                if(B[i][j]==1){
                    setcolor(P1_COLOR); setfillstyle(SOLID_FILL,P1_COLOR);
                    bar(M[j][i].x1,M[j][i].y1,M[j][i].x2,M[j][i].y2);
                }
                else if(B[i][j]==2){
                    setcolor(P2_COLOR); setfillstyle(SOLID_FILL,P2_COLOR);
                    bar(M[j][i].x1,M[j][i].y1,M[j][i].x2,M[j][i].y2);
                }
                else if(B[i][j]==3){
                    setcolor(OUTLINE); setfillstyle(SOLID_FILL,NEUTRAL_COLOR);
                    bar3d(M[j][i].x1,M[j][i].y1,M[j][i].x2,M[j][i].y2,0,0);
                }
                else if(B[i][j]==0){
                    setcolor(OUTLINE);setfillstyle(SOLID_FILL,BACKGROUND);
                    bar3d(M[j][i].x1,M[j][i].y1,M[j][i].x2,M[j][i].y2,0,0);
                }
        }
}
void drawPreviewMatrix(int L[PREVIEW_SIZE][PREVIEW_SIZE], matrixCoords M[PREVIEW_SIZE][PREVIEW_SIZE],int color){
    int i,j;

        //drawMatrix(previewL1top, previewL1left, previewSquares, laturaPreview);
        for(i=0;i<PREVIEW_SIZE;i++)
            for(j=0;j<PREVIEW_SIZE;j++){
                if(L[i][j]==1){
                    setcolor(color); setfillstyle(SOLID_FILL,color);
                    bar(M[j][i].x1,M[j][i].y1,M[j][i].x2,M[j][i].y2);
                }
                else if(L[i][j]==0){
                    setcolor(OUTLINE);setfillstyle(SOLID_FILL,BACKGROUND);
                    bar3d(M[j][i].x1,M[j][i].y1,M[j][i].x2,M[j][i].y2,0,0);
                }
        }

}

void update(){
    char c;
    c = (char) getch();
    //cout<<c;
    switch(c){

        //PLAYER 1 INPUT
        case 'W':
        if(!turn%2)flipPreviewMatrix(L1,previewCoordsL1,P1_COLOR);
        break;
        case 'A':
        if(!turn%2)rotatePreviewMatrixCounterClockwise(L1,previewCoordsL1,P1_COLOR);
        break;
        case 'S':
        if(!turn%2)flipPreviewMatrix(L1,previewCoordsL1,P1_COLOR);
        break;
        case 'D':
        if(!turn%2)rotatePreviewMatrixClockwise(L1,previewCoordsL1,P1_COLOR);
        break;
        case 'w':
        if(!turn%2)flipPreviewMatrix(L1,previewCoordsL1,P1_COLOR);
        break;
        case 'a':
        if(!turn%2)rotatePreviewMatrixCounterClockwise(L1,previewCoordsL1,P1_COLOR);
        break;
        case 's':
        if(!turn%2)flipPreviewMatrix(L1,previewCoordsL1,P1_COLOR);
        break;
        case 'd':
        if(!turn%2)rotatePreviewMatrixClockwise(L1,previewCoordsL1,P1_COLOR);printB();
        break;

        //PLAYER 2 INPUT
        case KEY_UP:
        if(turn%2){flipPreviewMatrix(L2,previewCoordsL2,P2_COLOR);}
        break;
        case KEY_LEFT:
        if(turn%2)rotatePreviewMatrixCounterClockwise(L2,previewCoordsL2,P2_COLOR);
        break;
        case KEY_DOWN:
        if(turn%2)flipPreviewMatrix(L2,previewCoordsL2,P2_COLOR);
        break;
        case KEY_RIGHT:
        if(turn%2)rotatePreviewMatrixClockwise(L2,previewCoordsL2,P2_COLOR);
        break;
    }
    printMatrix(L1,3);
    //cand e finalizata mutarea punem turn++;

}
void printB(){
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++)cout<<BOARD[i][j]<<" ";
        cout<<endl;
        }
}

bool canMakeMove(int givenX,int givenY,int L[3][3],int playerNmb,int opponentNmb){
    int i, j, samePosEncountered=0;
    int iBoard = givenX-1, jBoard = givenY - 1, nBoard = givenX + 1;
    if(iBoard<0 || jBoard<0) return false;
    //printB();cout<<endl;printL();cout<<endl;
    printB();
    for(i=0; i<3; i++, iBoard++){
        for(j=0, jBoard = givenY - 1; j<3 && jBoard<=nBoard; j++, jBoard++){
            //cout<<BOARD[i1][j1]<<" ";
            if(  (BOARD[iBoard][jBoard]==5
                ||BOARD[iBoard][jBoard]==3
                ||BOARD[iBoard][jBoard]==opponentNmb) && L[i][j]==playerNmb) return false;
            //if(BOARD[i1][j1]==2&&L1[i][j]==1) return false;
            //if(BOARD[i1][j1]==3&&L1[i][j]==1) return false;
            if(BOARD[iBoard][jBoard]==playerNmb && L[i][j]==playerNmb){
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
                 //cout<<BOARD[iBoard][jBoard]<<" ";
                //if(BOARD[iBoard][jBoard]==playerNmb && L1[i][j]==0) BOARD[iBoard][jBoard]=0;
                if(BOARD[iBoard][jBoard]==0 && L1[i][j]==playerNmb) BOARD[iBoard][jBoard]=1;
            }//cout<<endl;
            }
    printB();
}
bool delayed=false;
void click_handler(int x, int y){


    if (x>=boardTop && x<=boardTop+boardWidth && y>=boardLeft&&y<=boardLeft+boardHeight)
       {
           //cout<<"clicked on board";
//printB();
          boardLine=(x-boardTop)/boardLatura+1; boardColumn=(y-boardLeft)/boardLatura+1;
          if(canMakeMove(boardColumn,boardLine,L1,1,2)){
                cout<<"caaan doo\n";
                makeMove(boardColumn,boardLine,L1,1);
                drawBoardMatrix(BOARD,boardCoords);

          }
          else cout<<"can't doo\n";
          //if(BOARD[boardColumn][boardLine]==1)cout<<"AM DAT CLICK ";
       }
   // if(delayed){}
   //     else {delayed=true;delay(500);}
}

void loadTable(){
    int n;
    ifstream f("start_table.in");
    f>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)f>>BOARD[i][j];
    f.close();
    printB();
}
int main(){
    int x = getmaxwidth(), y=getmaxheight();
    loadTable();
    initwindow(x-80,y);
    initiateCanvas(400,400,4);
    printMatrix(L1,3);

    //printMatrix(L2,3);
    //left click mouse handler
    registermousehandler(WM_LBUTTONDOWN, click_handler);
    gata=false;
       do
       {
          update();
       }
       while (!gata);

    //initiateCanvas((x-80)/4,y/4,4);
    closegraph();
    return 0;
}

