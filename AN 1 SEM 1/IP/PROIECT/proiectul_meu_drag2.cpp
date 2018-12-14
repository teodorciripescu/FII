#include <iostream>
#include <winbgim.h>
#include <stdlib.h>
#include <fstream>

#define BOARD_SIZE 6
#define BOARD_COORDS_SIZE 4

#define PREVIEW_SIZE 3
#define BORDER 5
#define NEUTRAL_PIECE 3
#define P1_PIECE 1
#define P2_PIECE 2
#define P1_COLOR GREEN
#define P2_COLOR YELLOW
#define NEUTRAL_COLOR WHITE
#define OUTLINE COLOR(255,100,0)
#define BACKGROUND BLUE

using namespace std;

struct matrixCoords{
    int x1,y1,x2,y2;
};
//BOARD GLOBAL VARS
int BOARD[BOARD_SIZE][BOARD_SIZE],latura;
int boardTop, boardLeft, boardWidth, boardHeight, boardLatura, boardSquares=4, boardLine, boardColumn;
matrixCoords boardCoords[BOARD_COORDS_SIZE][BOARD_COORDS_SIZE];
//PREVIEWS GLOBAL VARS
int L1[PREVIEW_SIZE][PREVIEW_SIZE]={0,1,0,0,1,0,0,1,1},L2[PREVIEW_SIZE][PREVIEW_SIZE]={2,2,0,0,2,0,0,2,0};
int previewL1top,previewL1left,previewL2top,previewL2left;
int previewSquares=3, laturaPreview;
matrixCoords previewCoordsL1[PREVIEW_SIZE][PREVIEW_SIZE], previewCoordsL2[PREVIEW_SIZE][PREVIEW_SIZE];

int turn;
bool gata;
bool pickedNeutralPiece=false,movedL=false;

void initiateCanvas(int width, int height, int squares);
//BOARD FUNCTIONS
void loadTable();
void printB();
void generateCoordsForMatrix(matrixCoords M[BOARD_COORDS_SIZE][BOARD_COORDS_SIZE], int squares, int top, int left, int latura);
void drawBoardMatrix(int B[BOARD_SIZE][BOARD_SIZE], matrixCoords M[BOARD_COORDS_SIZE][BOARD_COORDS_SIZE]);
//PREVIEW FUNCTIONS
void printL();
void rotatePreviewMatrixClockwise(int L[PREVIEW_SIZE][PREVIEW_SIZE],matrixCoords coordsL[PREVIEW_SIZE][PREVIEW_SIZE],int color);
void rotatePreviewMatrixCounterClockwise(int L[PREVIEW_SIZE][PREVIEW_SIZE],matrixCoords coordsL[PREVIEW_SIZE][PREVIEW_SIZE],int color);
void cyclicPreviewInterchange(int &a, int &b, int &c, int &d);
void flipPreviewMatrix(int L[PREVIEW_SIZE][PREVIEW_SIZE],matrixCoords coordsL[PREVIEW_SIZE][PREVIEW_SIZE],int color);
void generateCoordsForPreviewMatrix(matrixCoords M[PREVIEW_SIZE][PREVIEW_SIZE], int squares, int top, int left, int latura);
void drawPreviewMatrix(int L[PREVIEW_SIZE][PREVIEW_SIZE], matrixCoords M[PREVIEW_SIZE][PREVIEW_SIZE],int color);
void printMatrix(int L[PREVIEW_SIZE][PREVIEW_SIZE], int n);
//INPUT/MOVES FUNCTIONS
void click_handler(int x, int y);
void update();
bool canMakeMove(int givenX,int givenY,int L[PREVIEW_SIZE][PREVIEW_SIZE],int playerNmb,int opponentNmb);
void makeMove(int givenX,int givenY,int L[PREVIEW_SIZE][PREVIEW_SIZE],int playerNmb);
void removePieceFromTable(int playerNmb);

//OTHER DRAW METHODS
void drawReadyButton();
int main(){
    int x = getmaxwidth(), y=getmaxheight();
    loadTable();
    initwindow(x-80,y);
    initiateCanvas(400,400,boardSquares);
    printMatrix(L1,3);

    //left click mouse handler
    registermousehandler(WM_LBUTTONDOWN, click_handler);

    gata=false;
       do
       {
          update();
       }
       while (!gata);

    closegraph();
    return 0;
}


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
    generateCoordsForMatrix(boardCoords,squares,top,left,latura);
    drawBoardMatrix(BOARD,boardCoords);


    cout<<"Drawing move previews.\n";
    laturaPreview=latura/2;
    top/=squares;
    previewL1top=top;previewL1left=left;
    generateCoordsForPreviewMatrix(previewCoordsL1, previewSquares, previewL1top, previewL1left, laturaPreview);
    drawPreviewMatrix(L1,previewCoordsL1,P1_COLOR);

    top = getmaxx() - laturaPreview*(previewSquares+3);
    previewL2top=top;previewL2left=left;
    printB();cout<<endl<<endl;
    generateCoordsForPreviewMatrix(previewCoordsL2, previewSquares, previewL2top, previewL2left, laturaPreview);
    printB();cout<<endl<<endl;
    drawPreviewMatrix(L2,previewCoordsL2,P2_COLOR);
    //loadTable();
    drawReadyButton();
}

void generateCoordsForMatrix(matrixCoords M[BOARD_COORDS_SIZE][BOARD_COORDS_SIZE], int squares, int top, int left, int latura){
    int i,j;
    for(i=0;i<BOARD_COORDS_SIZE;i++)
        for(j=0;j<BOARD_COORDS_SIZE;j++){
            M[i][j].x1 = top + latura*i;
            M[i][j].y1 = left + latura*j;
            M[i][j].x2 = top + latura*(i+1);
            M[i][j].y2 =  left + latura*(j+1);
    }
}
void generateCoordsForPreviewMatrix(matrixCoords M[PREVIEW_SIZE][PREVIEW_SIZE], int squares, int top, int left, int latura){
    int i,j;
    for(i=0;i<PREVIEW_SIZE;i++)
        for(j=0;j<PREVIEW_SIZE;j++){
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
           cout<<endl;
           printMatrix(L,3);
           cout<<endl;
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


void drawBoardMatrix(int B[BOARD_SIZE][BOARD_SIZE], matrixCoords M[BOARD_COORDS_SIZE][BOARD_COORDS_SIZE]){
    int i,j,iB,jB;
    for(iB=1;iB<BOARD_SIZE-1;iB++)
            for(jB=1;jB<BOARD_SIZE-1;jB++){
                i=iB-1; j=jB-1;
                if(B[iB][jB]==1){
                    //setcolor(P1_COLOR);
                    setfillstyle(SOLID_FILL,P1_COLOR);
                    bar(M[j][i].x1,M[j][i].y1,M[j][i].x2,M[j][i].y2);
                }
                else if(B[iB][jB]==2){
                    //setcolor(P2_COLOR);
                    setfillstyle(SOLID_FILL,P2_COLOR);
                    bar(M[j][i].x1,M[j][i].y1,M[j][i].x2,M[j][i].y2);
                }
                else if(B[iB][jB]==3){
                    //setcolor(OUTLINE);
                    setfillstyle(SOLID_FILL,NEUTRAL_COLOR);
                    bar3d(M[j][i].x1,M[j][i].y1,M[j][i].x2,M[j][i].y2,0,0);
                }
                else if(B[iB][jB]==0){
                    //setcolor(OUTLINE);
                    setfillstyle(SOLID_FILL,BACKGROUND);
                    bar3d(M[j][i].x1,M[j][i].y1,M[j][i].x2,M[j][i].y2,0,0);
                }
        }
  //      int *buf[4];
//        getimage("ready_btn_active.jpg",previewL1top,getmaxy()-latura,previewL1top+186,getmaxy()-latura+66,buf);

}
void drawPreviewMatrix(int L[PREVIEW_SIZE][PREVIEW_SIZE], matrixCoords M[PREVIEW_SIZE][PREVIEW_SIZE],int color){
    int i,j;

        //drawMatrix(previewL1top, previewL1left, previewSquares, laturaPreview);
        for(i=0;i<PREVIEW_SIZE;i++)
            for(j=0;j<PREVIEW_SIZE;j++){
                //cout<<endl<<"prev i= "<<i<<" j= "<<j<<" x1= "<<M[j][i].x1<<" y1= "<<M[j][i].y1<<endl;
                //cout<<endl<<"prev i= "<<i<<" j= "<<j<<" x2= "<<M[j][i].x2<<" y2= "<<M[j][i].y2<<endl;
                if(L[i][j]==1 || L[i][j]==2){
                    //setcolor(color);
                    setfillstyle(SOLID_FILL,color);
                    bar(M[j][i].x1,M[j][i].y1,M[j][i].x2,M[j][i].y2);
                }
                else if(L[i][j]==0){
                    //setcolor(OUTLINE);
                    setfillstyle(SOLID_FILL,BACKGROUND);
                    bar3d(M[j][i].x1,M[j][i].y1,M[j][i].x2,M[j][i].y2,0,0);
                }
        }

}
void drawReadyButton(){
    //make the button red if the L piece is not moved
    if(turn%2==0){
    readimagefile("ready_btn_active.jpg",previewL1top,getmaxy()-latura,previewL1top+186,getmaxy()-latura+66);
    readimagefile("ready_btn_inactive.jpg",previewL2top,getmaxy()-latura,previewL2top+186,getmaxy()-latura+66);
    }
    else{

   readimagefile("ready_btn_active.jpg",previewL2top,getmaxy()-latura,previewL2top+186,getmaxy()-latura+66);
    readimagefile("ready_btn_inactive.jpg",previewL1top,getmaxy()-latura,previewL1top+186,getmaxy()-latura+66);
    }
}
void update(){
    char c;

    c = (char) getch();
    //cout<<c;
    switch(c){

        //PLAYER 1 INPUT
        case 'w':
        case 'W':
        flipPreviewMatrix(L1,previewCoordsL1,P1_COLOR);
        break;
        case 'a':
        case 'A':
        rotatePreviewMatrixCounterClockwise(L1,previewCoordsL1,P1_COLOR);
        break;
        case 's':
        case 'S':
        flipPreviewMatrix(L1,previewCoordsL1,P1_COLOR);
        break;
        case 'd':
        case 'D':
        rotatePreviewMatrixClockwise(L1,previewCoordsL1,P1_COLOR);
        break;

        //PLAYER 2 INPUT
        case KEY_UP:
        flipPreviewMatrix(L2,previewCoordsL2,P2_COLOR);
        break;
        case KEY_LEFT:
        rotatePreviewMatrixCounterClockwise(L2,previewCoordsL2,P2_COLOR);
        break;
        case KEY_DOWN:
        flipPreviewMatrix(L2,previewCoordsL2,P2_COLOR);
        break;
        case KEY_RIGHT:
        rotatePreviewMatrixClockwise(L2,previewCoordsL2,P2_COLOR);
        break;
        case 'x':
        gata=true;
        break;

    }
    printMatrix(L1,3);
    //cand e finalizata mutarea punem turn++;

}
void printB(){
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++)cout<<BOARD[i][j]<<" ";
        cout<<endl;
        }
}
void printL(){
    for(int i=0;i<PREVIEW_SIZE;i++){
        for(int j=0;j<PREVIEW_SIZE;j++)cout<<L1[i][j]<<" ";
        cout<<endl;
        }
}

bool canMakeMove(int givenX,int givenY,int L[3][3],int playerNmb,int opponentNmb){
    int i, j, samePosEncountered=0;
    int iBoard = givenY+1, jBoard = givenX + 1, nBoard = givenX + 2;
   // cout<<iBoard<<" ... "<<BOARD_SIZE-2;
   cout<<endl<<"iBoard= "<<iBoard<<" jboard= "<<jBoard<<endl;
    if(iBoard<1 || jBoard<1 || iBoard>BOARD_SIZE-2 ||jBoard>BOARD_SIZE-2){cout<<"case1"; return false;}
    iBoard = givenY; jBoard = givenX;
    printB();
    for(i=0; i<3; i++, iBoard++){
        for(j=0, jBoard = givenX ; j<3 && jBoard<=nBoard; j++, jBoard++){
            if(  (BOARD[iBoard][jBoard]==BORDER
                ||BOARD[iBoard][jBoard]==NEUTRAL_PIECE
                ||BOARD[iBoard][jBoard]==opponentNmb) && L[i][j]==playerNmb){
                    cout<<endl<<"iBoard= "<<iBoard<<" jboard= "<<jBoard<<endl;
                    cout<<endl<<"i= "<<i<<" j= "<<j<<endl;
                    cout<<BOARD[iBoard][jBoard]<<" "<<"case2\n"; return false;}
            if(BOARD[iBoard][jBoard]==playerNmb && L[i][j]==playerNmb){
                samePosEncountered++;
                if(samePosEncountered==4) {cout<<"case3"; return false;}}
        }
    }
    return true;
}
void removePieceFromTable(int playerNmb){
    for(int i=1;i<BOARD_SIZE-1;i++)
            for(int j=1;j<BOARD_SIZE-1;j++)if(BOARD[i][j]==playerNmb)BOARD[i][j]=0;
}
void makeMove(int givenX,int givenY,int L[PREVIEW_SIZE][PREVIEW_SIZE],int playerNmb){
    int i, j, iBoard=givenY, jBoard=givenX, nBoard=givenX+2;
        removePieceFromTable(playerNmb);
        for(i=0; i<3; i++, iBoard++){
        for(j=0, jBoard = givenX ; j<3 && jBoard<=nBoard; j++, jBoard++){
                if(BOARD[iBoard][jBoard]==0 && L[i][j]==playerNmb) BOARD[iBoard][jBoard]=playerNmb;
            }
        }
        printB();
}
void testAndMakeMove(int givenX,int givenY,int L[3][3],int playerNmb,int opponentNmb){

}

void click_handler(int x, int y){
int opponent, player;
    //ready button click events
    if(x>=previewL1top && x<=previewL1top+186 && y>=getmaxy()-latura && y<=getmaxy()-latura+66){
        cout<<"Player 1 ready button clicked.\n";
        if(turn%2==0 && movedL==true && pickedNeutralPiece==false){
            cout<<"Player 1 ready button is active.\n";
            turn++;
            movedL=false;
            drawReadyButton();
        }
        else{
            cout<<"Player 1 ready button is inactive.\n";
        }
    }
    else if(x>=previewL2top && x<=previewL2top+186 && y>=getmaxy()-latura && y<=getmaxy()-latura+66){
        cout<<"Player 2 ready button clicked.\n";
        if(turn%2==1 && movedL==true && pickedNeutralPiece==false){
            cout<<"Player 2 ready button is active.\n";
            turn++;
            movedL=false;
            drawReadyButton();
        }
        else{
            cout<<"Player 2 ready button is inactive.\n";
        }
    }
    else
    if (x>=boardTop && x<=boardTop+boardWidth && y>=boardLeft&&y<=boardLeft+boardHeight){
        boardColumn=(x-boardTop)/boardLatura; boardLine=(y-boardLeft)/boardLatura;
            cout<<"boardLine= "<<boardLine<<" "<<"boardColumn= "<<boardColumn<<endl;
            if(BOARD[boardLine+1][boardColumn+1]==NEUTRAL_PIECE){if(movedL)if(!pickedNeutralPiece){
                pickedNeutralPiece=true;
                BOARD[boardLine+1][boardColumn+1]=0;
                drawBoardMatrix(BOARD,boardCoords);
                }
            }
            else if(pickedNeutralPiece && BOARD[boardLine+1][boardColumn+1]==0){
                cout<<"NEUTRAL PIECE REPLACED";
                pickedNeutralPiece=false;
                BOARD[boardLine+1][boardColumn+1]=NEUTRAL_PIECE;
                drawBoardMatrix(BOARD,boardCoords);
            }
       if(turn%2==0){
            if(movedL && BOARD[boardLine+1][boardColumn+1]==P1_PIECE){
                removePieceFromTable(P1_PIECE);
                drawBoardMatrix(BOARD,boardCoords);
                movedL=false;
            }
            else if(!movedL && canMakeMove(boardColumn,boardLine,L1,1,2)){
                cout<<"caaan doo\n";
                makeMove(boardColumn,boardLine,L1,1);
                drawBoardMatrix(BOARD,boardCoords);
                movedL=true;
                //turn++;
            }

            else cout<<"can't doo\n";
        }
        else{
            if(movedL && BOARD[boardLine+1][boardColumn+1]==P2_PIECE){
                removePieceFromTable(P2_PIECE);
                drawBoardMatrix(BOARD,boardCoords);
                movedL=false;
            }

            else if(!movedL && canMakeMove(boardColumn,boardLine,L2,2,1)){
                cout<<"caaan doo\n";
                makeMove(boardColumn,boardLine,L2,2);
                printB();
                drawBoardMatrix(BOARD,boardCoords);
                movedL=true;
                //turn++;
            }
            else cout<<"can't doo\n";
        }
    }
}


void loadTable(){
    int n;
    ifstream f("start_table.in");
    f>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)f>>BOARD[i][j];
    f.close();
}



