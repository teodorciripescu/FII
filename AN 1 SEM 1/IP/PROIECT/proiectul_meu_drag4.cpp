#include <iostream>
#include <winbgim.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <time.h>

#define BOARD_SIZE 6
#define BOARD_COORDS_SIZE 4

#define PREVIEW_SIZE 3
#define BORDER 5
#define NEUTRAL_PIECE 3
#define P1_PIECE 1
#define P2_PIECE 2
#define P1_COLOR RED
#define P2_COLOR BLUE
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
int L1[PREVIEW_SIZE][PREVIEW_SIZE],L2[PREVIEW_SIZE][PREVIEW_SIZE];
int previewL1top,previewL1left,previewL2top,previewL2left;
int previewSquares=3, laturaPreview;
matrixCoords previewCoordsL1[PREVIEW_SIZE][PREVIEW_SIZE], previewCoordsL2[PREVIEW_SIZE][PREVIEW_SIZE];
int startScreenTop, startScreenLeft;
int turn, midx, midy;
bool gata,gamemode,gameOver=false;
bool pickedNeutralPiece=false,movedL=false;

void initiateStartScreen();

void initiate_2players();
void initiateCanvas(int width, int height, int squares);
//BOARD FUNCTIONS
void loadTable();
void printB();
void generateCoordsForMatrix(matrixCoords M[BOARD_COORDS_SIZE][BOARD_COORDS_SIZE], int squares, int top, int left, int latura);
void drawBoardMatrix(int B[BOARD_SIZE][BOARD_SIZE], matrixCoords M[BOARD_COORDS_SIZE][BOARD_COORDS_SIZE]);
//PREVIEW FUNCTIONS
void printL();
void rotatePreviewMatrixClockwise(int L[PREVIEW_SIZE][PREVIEW_SIZE],matrixCoords coordsL[PREVIEW_SIZE][PREVIEW_SIZE],int color,bool draw);
void rotatePreviewLClockwise(int L[PREVIEW_SIZE][PREVIEW_SIZE]);
void rotatePreviewMatrixCounterClockwise(int L[PREVIEW_SIZE][PREVIEW_SIZE],matrixCoords coordsL[PREVIEW_SIZE][PREVIEW_SIZE],int color);
void cyclicPreviewInterchange(int &a, int &b, int &c, int &d);
void flipPreviewL(int L[PREVIEW_SIZE][PREVIEW_SIZE]);
void flipPreviewMatrix(int L[PREVIEW_SIZE][PREVIEW_SIZE],matrixCoords coordsL[PREVIEW_SIZE][PREVIEW_SIZE],int color,bool draw);
void generateCoordsForPreviewMatrix(matrixCoords M[PREVIEW_SIZE][PREVIEW_SIZE], int squares, int top, int left, int latura);
void drawPreviewMatrix(int L[PREVIEW_SIZE][PREVIEW_SIZE], matrixCoords M[PREVIEW_SIZE][PREVIEW_SIZE],int color);
void printMatrix(int L[PREVIEW_SIZE][PREVIEW_SIZE], int n);
//INPUT/MOVES FUNCTIONS
void mouse_hover_handler_startScreen(int x, int y);
void click_handler_startScreen(int x, int y);
void click_handler_1player(int x, int y);
void click_handler_2players(int x, int y);
void update();
bool canMakeMove(int givenX,int givenY,int L[PREVIEW_SIZE][PREVIEW_SIZE],int playerNmb,int opponentNmb);
void makeMove(int givenX,int givenY,int L[PREVIEW_SIZE][PREVIEW_SIZE],int playerNmb);
void removePieceFromTable(int playerNmb);
int checkIfGameOver(int L[3][3],int playerNmb,int opponentNmb);
//VS COMPUTER FUNCTIONS
int generateRandomNumber(int maxNmb);
int createCompPossibleMovesMatrix();
void randomMoveNeutralPieces();
void compMove();
//OTHER DRAW METHODS
void drawReadyButton();
void drawMatrix(int top, int left, int squares, int latura);

int main(){
    int x = getmaxwidth(), y=getmaxheight();
    initwindow(x-80,y);
    cout<<x-80<<" "<<y;
    initiateStartScreen();

    gata=false;
       do
       {
          update();
       }
       while (!gata);

    closegraph();
    return 0;
}

void initiateStartScreen(){
    int i,j;
    int x=getmaxx(),y=getmaxy();
    readimagefile("background_dark.jpg",0,0,x,y);
    startScreenTop = x / 2 - 230;
    startScreenLeft =  y / 2 - 60;

    readimagefile("images/singleplayer_white.jpg",startScreenTop,startScreenLeft,startScreenTop+450,startScreenLeft+100);
    readimagefile("images/multiplayer_white.jpg",startScreenTop,startScreenLeft+150,startScreenTop+450,startScreenLeft+100+150);
    readimagefile("images/exit_white.jpg",startScreenTop,startScreenLeft+300,startScreenTop+450,startScreenLeft+100+300);
    registermousehandler(WM_MOUSEMOVE, mouse_hover_handler_startScreen);
    registermousehandler(WM_LBUTTONDOWN, click_handler_startScreen);
    //TODO: when start screen stopped, stop handler
    //registermousehandler(WM_MOUSEMOVE, NULL);
}
void initiate_1player(){
    midx = getmaxx() / 2;
    midy = getmaxy() / 2;
    turn = 0;
    loadTable();
    initiateCanvas(400,400,boardSquares);
    gamemode=0;
    //left click mouse handler
    registermousehandler(WM_LBUTTONDOWN, click_handler_1player);
    srand (time(NULL));
}
void initiate_2players(){
    midx = getmaxx() / 2;
    midy = getmaxy() / 2;
    turn = 0;
    loadTable();
    initiateCanvas(400,400,boardSquares);
    gamemode=1;
    //left click mouse handler
    registermousehandler(WM_LBUTTONDOWN, click_handler_2players);
}

void initiateCanvas(int width, int height, int squares){
    cout<<"Initializing canvas...\n";
    int top, left,i,j,x=getmaxx(),y=getmaxy();
    top = (getmaxx() - width) / 2;
    left =  (getmaxy() - height) / 2;
    cout<<"Drawing matrix from "<<top<<" (top), "<<left<<" (left).\n";
    setbkcolor(BACKGROUND);
        clearviewport();
    for(i=0;i<=x;i+=180){
        for(j=0;j<=y;j+=180) readimagefile("images/background2.jpg",i,j,i+180,j+180);
    }

    latura = width/squares;
    setcolor(OUTLINE);
    boardTop = top; boardLeft = left; boardWidth = width; boardHeight = height; boardLatura = latura;
    generateCoordsForMatrix(boardCoords,squares,top,left,latura);
    drawBoardMatrix(BOARD,boardCoords);


    cout<<"Drawing move previews.\n";
    laturaPreview=latura/2;
    top/=squares;
    previewL1top=top;previewL1left=left;
    //L2 preview
    top = getmaxx() - laturaPreview*(previewSquares+3);
    previewL2top=top;previewL2left=left;

    generateCoordsForPreviewMatrix(previewCoordsL1, previewSquares, previewL1top, previewL1left, laturaPreview);
    drawPreviewMatrix(L1,previewCoordsL1,P1_COLOR);

    generateCoordsForPreviewMatrix(previewCoordsL2, previewSquares, previewL2top, previewL2left, laturaPreview);
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
void rotatePreviewMatrixClockwise(int L[PREVIEW_SIZE][PREVIEW_SIZE],matrixCoords coordsL[PREVIEW_SIZE][PREVIEW_SIZE],int color,bool draw){
    int n=PREVIEW_SIZE;
    for(int i=0; i<n/2; i++)
       for(int j=0; j<(n+1)/2; j++)
           cyclicPreviewInterchange(L[i][j], L[n-1-j][i], L[n-1-i][n-1-j], L[j][n-1-i]);
           //cout<<endl;
           //printMatrix(L,3);
           //cout<<endl;
    if(draw)drawPreviewMatrix(L,coordsL,color);

}
void rotatePreviewMatrixCounterClockwise(int L[PREVIEW_SIZE][PREVIEW_SIZE],matrixCoords coordsL[PREVIEW_SIZE][PREVIEW_SIZE],int color){
    int n=PREVIEW_SIZE;
    for(int i=0; i<n/2; i++)
       for(int j=0; j<(n+1)/2; j++)
           cyclicPreviewInterchange(L[j][n-1-i], L[n-1-i][n-1-j], L[n-1-j][i], L[i][j]);
    drawPreviewMatrix(L,coordsL,color);
}
void flipPreviewMatrix(int L[PREVIEW_SIZE][PREVIEW_SIZE],matrixCoords coordsL[PREVIEW_SIZE][PREVIEW_SIZE],int color,bool draw){
    for(int i=0,aux; i<PREVIEW_SIZE; i++) {
        aux = L[i][0];
        L[i][0] = L[i][PREVIEW_SIZE-1];
        L[i][PREVIEW_SIZE-1] = aux;
    }
    if(draw)drawPreviewMatrix(L,coordsL,color);
}
void printMatrix(int L[3][3], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<L[i][j]<<" ";
        cout<<endl;
            }
    cout<<endl;
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
void drawBoardMatrix(int B[BOARD_SIZE][BOARD_SIZE], matrixCoords M[BOARD_COORDS_SIZE][BOARD_COORDS_SIZE]){
    int i,j,iB,jB;
    int c , x = boardTop, y = boardLeft-3;
    setcolor(BLACK);

    setlinestyle(0, 0, 6);

    line(x, y, x+400, y);
    line(x-3, y, x-3, y+400);
    line(x+403,y,x+403,y+400);
    line(x-3,y+406,x+403,y+406);

    for(iB=1;iB<BOARD_SIZE-1;iB++)
            for(jB=1;jB<BOARD_SIZE-1;jB++){
                i=iB-1; j=jB-1;
                if(B[iB][jB]==1)
                    readimagefile("images/lava.jpg",M[j][i].x1,M[j][i].y1,M[j][i].x2,M[j][i].y2);
                else if(B[iB][jB]==2)
                    readimagefile("images/ice2.jpg",M[j][i].x1,M[j][i].y1,M[j][i].x2,M[j][i].y2);

                else if(B[iB][jB]==3)
                    readimagefile("images/neutral.jpg",M[j][i].x1,M[j][i].y1,M[j][i].x2,M[j][i].y2);

                else if(B[iB][jB]==0)
                    readimagefile("images/floor4.jpg",M[j][i].x1,M[j][i].y1,M[j][i].x2,M[j][i].y2);

        }
    setlinestyle(0, 0, 1);
    drawMatrix(boardTop,boardLeft,4,latura);
}
void drawPreviewMatrix(int L[PREVIEW_SIZE][PREVIEW_SIZE], matrixCoords M[PREVIEW_SIZE][PREVIEW_SIZE],int color){
    int i,j;
    for(i=0;i<PREVIEW_SIZE;i++)
        for(j=0;j<PREVIEW_SIZE;j++){
            if(L[i][j]==1)readimagefile("images/lava_small.jpg",M[j][i].x1,M[j][i].y1,M[j][i].x2,M[j][i].y2);
            else if(L[i][j]==2) readimagefile("images/ice2_small.jpg",M[j][i].x1,M[j][i].y1,M[j][i].x2,M[j][i].y2);
            else if(L[i][j]==0)readimagefile("images/floor4_small.jpg",M[j][i].x1,M[j][i].y1,M[j][i].x2,M[j][i].y2);
    }
    drawMatrix(previewL1top,previewL1left,3,laturaPreview);
    drawMatrix(previewL2top,previewL2left,3,laturaPreview);
}

void drawReadyButton(){
    //make the button red if the L piece is not moved
    if(turn%2==0){
        if(movedL==true)readimagefile("ready_btn_active.jpg",previewL1top,getmaxy()-latura,previewL1top+186,getmaxy()-latura+66);
        else if(movedL==false) readimagefile("ready_btn_waiting_move.jpg",previewL1top,getmaxy()-latura,previewL1top+186,getmaxy()-latura+66);
    readimagefile("ready_btn_inactive.jpg",previewL2top,getmaxy()-latura,previewL2top+186,getmaxy()-latura+66);
    }
    else{
    if(movedL)readimagefile("ready_btn_active.jpg",previewL2top,getmaxy()-latura,previewL2top+186,getmaxy()-latura+66);
    else readimagefile("ready_btn_waiting_move.jpg",previewL2top,getmaxy()-latura,previewL2top+186,getmaxy()-latura+66);
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
        flipPreviewMatrix(L1,previewCoordsL1,P1_COLOR,true);
        break;
        case 'a':
        case 'A':
        rotatePreviewMatrixCounterClockwise(L1,previewCoordsL1,P1_COLOR);
        break;
        case 's':
        case 'S':
        flipPreviewMatrix(L1,previewCoordsL1,P1_COLOR,true);
        break;
        case 'd':
        case 'D':
        rotatePreviewMatrixClockwise(L1,previewCoordsL1,P1_COLOR,true);
        break;

        //PLAYER 2 INPUT
        case KEY_UP:
        flipPreviewMatrix(L2,previewCoordsL2,P2_COLOR,true);
        break;
        case KEY_LEFT:
        rotatePreviewMatrixCounterClockwise(L2,previewCoordsL2,P2_COLOR);
        break;
        case KEY_DOWN:
        flipPreviewMatrix(L2,previewCoordsL2,P2_COLOR,true);
        break;
        case KEY_RIGHT:
        rotatePreviewMatrixClockwise(L2,previewCoordsL2,P2_COLOR,true);
        break;
        case 'x':
        gata=true;
        break;
        case ' ':
        if(gameOver){
            gameOver = false;
            if(gamemode==0)initiate_2players();
            else if(gamemode==1)initiate_1player();
        }
    }
    printMatrix(L1,3);

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

   //cout<<endl<<"iBoard= "<<iBoard<<" jboard= "<<jBoard<<endl;
    if(iBoard<1 || jBoard<1 || iBoard>BOARD_SIZE-2 ||jBoard>BOARD_SIZE-2){
        //cout<<"case1";
        return false;}
    iBoard = givenY; jBoard = givenX;
    //printB();
    for(i=0; i<3; i++, iBoard++){
        for(j=0, jBoard = givenX ; j<3 && jBoard<=nBoard; j++, jBoard++){
            if(  (BOARD[iBoard][jBoard]==BORDER
                ||BOARD[iBoard][jBoard]==NEUTRAL_PIECE
                ||BOARD[iBoard][jBoard]==opponentNmb) && L[i][j]==playerNmb)return false;
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

bool singleHovered,multiHovered,exitHovered;
void mouse_hover_handler_startScreen(int x, int y){
    if(x>=startScreenTop && x<=startScreenTop+450 && y>=startScreenLeft && y<=startScreenLeft+100){
        readimagefile("images/singleplayer_green.jpg",startScreenTop,startScreenLeft,startScreenTop+450,startScreenLeft+100);
        singleHovered=true;
    }
    else if(x>=startScreenTop && x<=startScreenTop+450 && y>=startScreenLeft+150 && y<=startScreenLeft+100+150){
        readimagefile("images/multiplayer_green.jpg",startScreenTop,startScreenLeft+150,startScreenTop+450,startScreenLeft+100+150);
        multiHovered=true;
    }
    else if(x>=startScreenTop && x<=startScreenTop+450 && y>=startScreenLeft+300 && y<=startScreenLeft+100+300){
        readimagefile("images/exit_red.jpg",startScreenTop,startScreenLeft+300,startScreenTop+450,startScreenLeft+100+300);
        exitHovered=true;
    }
    else{
        if(singleHovered){
            readimagefile("images/singleplayer_white.jpg",startScreenTop,startScreenLeft,startScreenTop+450,startScreenLeft+100);
            singleHovered=false;
        }
        else if(multiHovered){
            readimagefile("images/multiplayer_white.jpg",startScreenTop,startScreenLeft+150,startScreenTop+450,startScreenLeft+100+150);
            multiHovered=false;
        }
        else if(exitHovered){
            readimagefile("images/exit_white.jpg",startScreenTop,startScreenLeft+300,startScreenTop+450,startScreenLeft+100+300);
            exitHovered=false;
        }
    }
}
void click_handler_startScreen(int x, int y){
    //BUTTON SINGLEPLAYER
    if(x>=startScreenTop && x<=startScreenTop+450 && y>=startScreenLeft && y<=startScreenLeft+100){
        registermousehandler(WM_MOUSEMOVE, NULL);
        registermousehandler(WM_LBUTTONDOWN, NULL);
        clearviewport();
        initiate_1player();
    }
    //BUTTON MULTIPLAYER
    else if(x>=startScreenTop && x<=startScreenTop+450 && y>=startScreenLeft+150 && y<=startScreenLeft+100+150){
        registermousehandler(WM_MOUSEMOVE, NULL);
        registermousehandler(WM_LBUTTONDOWN, NULL);
        clearviewport();
        initiate_2players();
    }
    //BUTTON EXIT
    else if(x>=startScreenTop && x<=startScreenTop+450 && y>=startScreenLeft+300 && y<=startScreenLeft+100+300){
        exit(0);
    }
}

void click_handler_1player(int x, int y){
int opponent, player;
    //ready button click events
    if(x>=previewL1top && x<=previewL1top+186 && y>=getmaxy()-latura && y<=getmaxy()-latura+66){
        cout<<"Player 1 ready button clicked.\n";
        if(turn%2==0 && movedL==true && pickedNeutralPiece==false){
            cout<<"Player 1 ready button is active.\n";
            movedL=false;
            if(checkIfGameOver(L2,1,2)){cout<<"PLAYER 1 WON!\n";outtextxy(midx-100, midy, "Player1 won. Press SPACE to play again.");}
                else{
                    compMove();
                    randomMoveNeutralPieces();
                    if(checkIfGameOver(L1,2,1)){cout<<"COMPUTER WON!\n";outtextxy(midx-100, midy, "Computer won. Press SPACE to play again.");}
                }

            drawBoardMatrix(BOARD,boardCoords);
            drawReadyButton();
            }
            else{
            cout<<"Player 1 ready button is inactive.\n";
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
            if(movedL && BOARD[boardLine+1][boardColumn+1]==P1_PIECE && !pickedNeutralPiece){
                removePieceFromTable(P1_PIECE);
                drawBoardMatrix(BOARD,boardCoords);
                movedL=false;
            }
            else if(!movedL && canMakeMove(boardColumn,boardLine,L1,1,2)){
                cout<<"caaan doo\n";
                movedL=true;
                makeMove(boardColumn,boardLine,L1,1);
                drawBoardMatrix(BOARD,boardCoords);
                drawReadyButton();
            }
            else cout<<"can't doo\n";
        }
    }
}
int generateRandomNumber(int maxNmb){
    /* initialize random seed: */
  //srand (time(NULL));
  /* generate secret number between 1 and 10: */
  return rand() % (maxNmb+1);
  }

int compPossibleMoves[4][4];

int createCompPossibleMovesMatrix(){
    int i,j,possibleMoves=0;
    for(i=1;i<=4;i++)
        for(j=1;j<=4;j++){
                if(BOARD[i][j]==0){compPossibleMoves[i-1][j-1]=1;possibleMoves++;}
                else if(BOARD[i][j]==2 && canMakeMove(j-1,i-1,L2,2,1)){
                        compPossibleMoves[i-1][j-1]=1;
                        possibleMoves++;
                        }
        }
    compPossibleMoves[0][0]=compPossibleMoves[0][3]=compPossibleMoves[3][0]=compPossibleMoves[3][3]=0;
    return possibleMoves;
}
void randomMoveNeutralPieces(){
    int i,j,pieces=2;
    bool ready=false;
    for(i=1;i<=4;i++)
        for(j=1;j<=4;j++){
            if(BOARD[i][j]==3)BOARD[i][j]=0;
        }
    while(!ready){
        i = generateRandomNumber(3);
        j = generateRandomNumber(3);
        if(BOARD[i][j]==0){
            BOARD[i][j]=3;
            pieces--;
            if(!pieces)ready=true;
            drawBoardMatrix(BOARD,boardCoords);
            }
    }
}
void compMove(){
    int i,j,k;
    createCompPossibleMovesMatrix();
    for(k=0;k<4;k++){
        for(i=0;i<BOARD_SIZE;i++)
            for(j=0;j<BOARD_SIZE;j++)
                if(compPossibleMoves[i][j]){if(canMakeMove(j,i,L2,2,1)){
                        drawPreviewMatrix(L2,previewCoordsL2,P2_COLOR);
                        makeMove(j,i,L2,2);
                        delay(200);
                        drawBoardMatrix(BOARD,boardCoords);
                        return;}
                    }
                    else{}
        flipPreviewL(L2);
        for(i=0;i<BOARD_SIZE;i++)
            for(j=0;j<BOARD_SIZE;j++)
                if(canMakeMove(j,i,L2,1,2)){
                        drawPreviewMatrix(L2,previewCoordsL2,P2_COLOR);
                        makeMove(j,i,L2,2);
                        delay(200);
                        drawBoardMatrix(BOARD,boardCoords);
                        return;}
        flipPreviewL(L2);
        rotatePreviewLClockwise(L2);
        }
}

void click_handler_2players(int x, int y){
int opponent, player;
    //ready button click events
    if(x>=previewL1top && x<=previewL1top+186 && y>=getmaxy()-latura && y<=getmaxy()-latura+66){
        cout<<"Player 1 ready button clicked.\n";
        if(turn%2==0 && movedL==true && pickedNeutralPiece==false){
            cout<<"Player 1 ready button is active.\n";
            turn++;
            movedL=false;
            drawReadyButton();
            if(checkIfGameOver(L2,1,2)){cout<<"PLAYER 1 WON!\n";outtextxy(midx-100, midy, "Player1 won. Press SPACE to play again.");

            }
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
            if(checkIfGameOver(L1,2,1)){cout<<"PLAYER 2 WON!\n";outtextxy(midx-100, midy, "Player2 won. Press SPACE to play again.");}
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
            if(movedL && BOARD[boardLine+1][boardColumn+1]==P1_PIECE && !pickedNeutralPiece){
                removePieceFromTable(P1_PIECE);
                drawBoardMatrix(BOARD,boardCoords);
                movedL=false;
            }
            else if(!movedL && canMakeMove(boardColumn,boardLine,L1,1,2)){
                cout<<"caaan doo\n";
                movedL=true;
                makeMove(boardColumn,boardLine,L1,1);
                drawBoardMatrix(BOARD,boardCoords);
                drawReadyButton();

                //turn++;
            }

            else cout<<"can't doo\n";
        }
        else{
            if(movedL && BOARD[boardLine+1][boardColumn+1]==P2_PIECE && !pickedNeutralPiece){
                removePieceFromTable(P2_PIECE);
                drawBoardMatrix(BOARD,boardCoords);
                movedL=false;
            }

            else if(!movedL && canMakeMove(boardColumn,boardLine,L2,2,1)){
                cout<<"caaan doo\n";
                movedL=true;
                makeMove(boardColumn,boardLine,L2,2);
                //printB();
                drawBoardMatrix(BOARD,boardCoords);
                drawReadyButton();

                //turn++;
            }
            else cout<<"can't doo\n";
        }
    }
}


int checkIfGameOver(int L[3][3],int playerNmb,int opponentNmb){
//0 - not over;  1 - PLAYER 1 WON; 2 - PLAYER 2 WON.
    int i,j,k,midx,midy;
    for(k=0;k<4;k++){
        for(i=0;i<BOARD_SIZE;i++)
            for(j=0;j<BOARD_SIZE;j++)
                //checks if opponent can make any moves
                if(canMakeMove(j,i,L,opponentNmb,playerNmb))return 0;
        flipPreviewL(L);
        for(i=0;i<BOARD_SIZE;i++)
            for(j=0;j<BOARD_SIZE;j++)
                if(canMakeMove(j,i,L,opponentNmb,playerNmb))return 0;
        flipPreviewL(L);
        rotatePreviewLClockwise(L);
        printL();cout<<endl;
        }
    gameOver=true;

    //display winner message
    clearviewport();


    return playerNmb;
}
void rotatePreviewLClockwise(int L[PREVIEW_SIZE][PREVIEW_SIZE]){
    int n=PREVIEW_SIZE;
    for(int i=0; i<n/2; i++)
       for(int j=0; j<(n+1)/2; j++)
           cyclicPreviewInterchange(L[i][j], L[n-1-j][i], L[n-1-i][n-1-j], L[j][n-1-i]);

}

void flipPreviewL(int L[PREVIEW_SIZE][PREVIEW_SIZE]){
    for(int i=0,aux; i<PREVIEW_SIZE; i++) {
            aux = L[i][0];
            L[i][0] = L[i][PREVIEW_SIZE-1];
            L[i][PREVIEW_SIZE-1] = aux;
        }
}
void loadTable(){
    int n;
    ifstream f("start_table.in");
    f>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)f>>BOARD[i][j];
    for(int i=0;i<PREVIEW_SIZE;i++)
        for(int j=0;j<PREVIEW_SIZE;j++)f>>L1[i][j];
    for(int i=0;i<PREVIEW_SIZE;i++)
        for(int j=0;j<PREVIEW_SIZE;j++)f>>L2[i][j];
    f.close();
}



