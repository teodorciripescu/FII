#include<iostream>
using namespace std;
struct punct{float x;
             float y;
             };
struct segment{
              punct A;
              punct B;
              };
punct punctMijloc(segment S){
    punct M;
    M.x = (S.A.x + S.B.x)/2.0;
    M.y = (S.A.y + S.B.y)/2.0;
    return P;
}

int main()
{
    segment S;
    S.A.x = 1;
    S.A.y = 2;
    S.B.x = 5;
    S.B.y = 2;
    punct M = punctMijloc(S);
    cout<<M.x<<" "<<M.y;
    return 0;
}
