#include<iostream>
#include<cmath>
using namespace std;
struct punct{
    float x;
    float y;
    };
struct triunghi{
    punct A;
    punct B;
    punct C;
    };
//subpunctul b
float perimetru(triunghi t){
float AB,BC,AC;
AB = sqrt((t.B.x - t.A.x)*(t.B.x - t.A.x) + (t.B.y - t.A.y)*(t.B.y - t.A.y));
BC = sqrt((t.C.x - t.B.x)*(t.C.x - t.B.x) + (t.C.y - t.B.y)*(t.C.y - t.B.y));
AC = sqrt((t.C.x - t.A.x)*(t.C.x - t.A.x) + (t.C.y - t.A.y)*(t.C.y - t.A.y));
return AB + BC + AC;
}
//subpunctul c
float arie(triunghi t){
float AB,BC,AC,p;
AB = sqrt((t.B.x - t.A.x)*(t.B.x - t.A.x) + (t.B.y - t.A.y)*(t.B.y - t.A.y));
BC = sqrt((t.C.x - t.B.x)*(t.C.x - t.B.x) + (t.C.y - t.B.y)*(t.C.y - t.B.y));
AC = sqrt((t.C.x - t.A.x)*(t.C.x - t.A.x) + (t.C.y - t.A.y)*(t.C.y - t.A.y));
p = AB + BC + AC;
return sqrt(p*(p-AB)*(p-BC)*(p-AC));
}
int main(){
    triunghi t;
    cin>>t.A.x>>t.A.y;
    cin>>t.B.x>>t.B.y;
    cin>>t.C.x>>t.C.y;
    cout<<perimetru(t)<<endl;
    cout<<arie(t);
    //ex 1 2    1 1     2 1
    return 0;
}
