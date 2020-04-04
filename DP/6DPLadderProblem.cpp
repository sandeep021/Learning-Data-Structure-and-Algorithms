//Q: No of ways to reach nth ladder step 1 to k steps at a time are allowed
///VERY GOOD MUST REMEBER IT 
#include <bits/stdc++.h>
using namespace std;
int memo[100];
int totalStepsTD(int n, int k, int dp[]){
    if (n==0) return 1;//base case
    int ways=0;
    if (dp[n]!=0) return dp[n];//lookout
    for(int i=1;i<=k;i++){
        if (n-i>=0)
            ways +=totalStepsTD(n-i,k,dp);
    }
    dp[n]=ways;
    return dp[n];
}

int toatlStepsBU(int n, int k){
    int dp[100]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int ways=0;
        for(int j=1;j<=k;j++){
            if (i-j>=0){
                ways+=dp[i-j];//adding last k cells if available
                //pichle n-1,n-1...n-k tk ane ka trika add kr rhe to get n tk
                //ka ane ka trika.
            }
        }
        dp[i]=ways;
    }
    return dp[n];
}
//VERY GOOD QUESTION
//optimize BU 

int toatlStepsBUOptimized(int n, int k){
    int dp[100]={0};
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=k;i++){
        dp[i]=2*dp[i-1];//using maths to reduce the loop
        }//for i<k we have not complete window so we are only adding the values 
        //not subtarcting any thing
    for(int i=k+1;i<=n;i++){
        dp[i]=2*dp[i-1]-dp[i-k-1];//using maths to reduce the loop
        //adding the value of next cell and subtracting the value of first cell
    }
    return dp[n];
}

int main(){
    int n,k;
    cin>>n>>k;
    memo[100]={0};
    cout<<totalStepsTD(n,k,memo)<<" ans by memo"<<endl;
    cout<<toatlStepsBU(n,k)<<" ans by dp"<<endl;
    cout<<toatlStepsBUOptimized(n,k)<<" ans by dp and optimized"<<endl;

}