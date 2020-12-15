#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b){
    if(b==0) return a;
    else return GCD(b,a%b);
}


int x,y, gcd_;
void extendedEuclidean(int a, int b){
    if(b==0){
        x=1;
        y=0;
        gcd_=a;
        return;
    }
    extendedEuclidean(b, a%b);
    int cx=y;
    int cy= x-(a/b)*y;
    x=cx;
    y=cy;
}


int main(){
    int a,b;
    cin>>a>>b;
    cout<<GCD(a,b)<<endl;

    // 18x + 30y = GCD(18, 30); find x and y then we will use extended Euclidean
    //above is fixed formula we can derive it also but no need right now
    //derivation  :   https://online.codingblocks.com/app/player/72248/content/154821/205/lecture
    extendedEuclidean(18,30);
    cout<<x<<" "<<y;
}