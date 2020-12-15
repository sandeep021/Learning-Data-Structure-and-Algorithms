#include <bits/stdc++.h>
using namespace std;
//give a 4XN floor grid how many ways to fill tho whole floor grid by 1X4 or 4X1 size tiles
int tillingProb(int m, int n){
    if (n<=3) return 1;
    else if (n==4) return 2;
    int ans1=1+tillingProb(m,n-1);//when brick placed in vertical orientation
    int ans2=1+tillingProb(m,n-4);//when brick will be placed in horizaontal orientation
    return ans1+ans2;
}

int main(){
    cout<<tillingProb(1,5);
}