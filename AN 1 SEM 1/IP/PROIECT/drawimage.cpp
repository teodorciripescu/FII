#include <iostream>
#include <winbgim.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
using namespace std;
    char btnReadyTexturePath[100];
int main(int argc, char** argv){
    int x = getmaxwidth(), y=getmaxheight();
    initwindow(x-80,y);
    char *p = strrchr(argv[0], '\\');
    if(p) p[0] = 0;
    //cout<<argv[0];
    strcpy(btnReadyTexturePath,argv[0]);
    strcat(btnReadyTexturePath,"\\ready_btn.jpg");
    //cout<<argv[0];
    cout<<btnReadyTexturePath;
    setbkcolor(BLUE);
    //clearviewport();
    //readimagefile(btnReadyTexturePath,100,100,186,66);
    readimagefile("ready_btn_inactive.jpg",100,100,186,66);
    readimagefile("ready_btn_active.jpg",300,200,186,66);

    getch();
    closegraph();
    return 0;
}
