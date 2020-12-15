//very important coin change problem

///  https://leetcode.com/problems/coin-change-2/             must see why loops interchanged







//min coins of denomination 1,7,10 are available

#include <bits/stdc++.h>
using namespace std;
const int inf =(int)1e9;


//Top Down Approach: it is recursion using memoisation
 int memo[1000];
// int minChangeMemo(int n, int t, int dp[], int coins[] ){
//     if (n==0) return 0;//base case
//     if (memo[n]!=-1)  return memo[n];//lookout case
//     int ans=inf;
//     for(int i=0;i<t;i++){
//         if(n-coins[i]>=0){
//             int subProblem=minChangeMemo(n-coins[i], t, dp, coins);
//             ans=min(ans,subProblem+1);

//         }
//     }
//     dp[n]=ans;
//     return dp[n];
// }

// int minChangeBU(int n, int t, int coins[]){
//     int dp[100]={0};
//     for (int i=1;i<=n;i++){//for filling dp array
//         int ans=inf;
//         for (int j=0;j<t;j++){//for all the coins to gett min
//              if (i-coins[j]>=0){
//                  int subProblem=dp[i-coins[j]];
//                  ans=min(ans,subProblem+1);
//              }
//         }
//         dp[i]=ans;//storing ans in dp
//     }
//     //for(int i=0;i<=n;i++)  cout<<dp[i]<<"  ";
//     //cout<<"   "<<endl;
//     return dp[n];
// }

int minChangeBU2(int coins[], int n, int t){
    int dp[100][100]={0};
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=t;j++) dp[0][j]=inf;//INT_MAX-1 use krenge wrna plus one hone pe value negative hoo jaegi fir gdbad ho jaega 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=t;j++){
            if(coins[i-1]<=j) dp[i][j]=min(dp[i][j-coins[i-1]]+1, dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=t;j++) cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[n][t];
}


int main(){
int n,t;
    cin>>n>>t;
    int coins[t]={100,50,20};
    fill(memo,memo+n+1,-1);
    memo[0]=0;
    //cout<<minChangeMemo(n,t,memo,coins)<<" ans by memoization"<<endl;
   // cout<<minChangeBU(n,t, coins)<<" ans by dp"<<endl;
   minChangeBU2(coins, n,t);
   // cout<<minChangeBU2(coins, n,t)<<" ans by dp2"<<endl;
   // cout<<"JBJNJNJNJ";
}


