//you have to min steps to make n cells from 1 cell
//given three moves and their costs.
//moves             costs
// double            x
//i+1                y
//i-1                z

//SOLUTION
//since we can seet that in bottom uo DP we have to fill a cell i from i+1 which is not normal way
//we need to use trick

//for odd we cant move from i/2...because it doesnt exit ....
//we have 2 choices 1. dp[i-1]+ cost of increment  2. dp[(i+1)/2] + cost of double + cost of decrement.

//for even we can do dp[i/2] , dp[i-1], dp[i+1]------dp[i+1] will always cost more than the others it is odd

#include <bits/stdc++.h>
using namespace std;

int cellMetosis(int n , int x, int y, int z){
    int dp[n+1]={0};
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=n;i++){
       if(i%2==0) dp[i]=min(dp[i-1]+y, dp[i/2]+x);
       else dp[i]=min(dp[i-1]+y, dp[(i+1)/2]+x+z); 
    }
    return dp[n];
}

int main(){

    cout<<cellMetosis(5,2,1,3);
}