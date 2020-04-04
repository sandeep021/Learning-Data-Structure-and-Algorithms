//Q: you have list of wines you have to sell them to get max profit also follow these rules
//rules: only first or last wine can be sell in one year
//rules: only one wine can be(must be) selled in one year


//it is optomisation problem, not greedy because after choosing max between first and
//last interior order will also affect
//also overlapping
//2d DP solution
#include <bits/stdc++.h>
using namespace std;
//const int inf =(int)1e9;
int memo[1000][1000];

int profit(int wines[], int i, int j, int y, int dp[][1000]){
    if (i>j) return 0;//base case 
    if (dp[i][j]!=0) return dp[i][j];//lookout
    int q1=wines[i]*y+ profit(wines, i+1, j, y+1,dp);
    int q2=wines[j]*y+ profit(wines, i, j-1, y+1,dp);
    return dp[i][j]= max(q1,q2);

}


int main(){
    memo[1000][1000]={0};
    int wines[]={2,3,5,1,4};
    cout<<profit(wines,0,4,1,memo)<<" ans by memo"<<endl;

}