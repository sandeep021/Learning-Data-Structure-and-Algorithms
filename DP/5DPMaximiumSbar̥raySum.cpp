#include <bits/stdc++.h>
using namespace std;
const int minusinf = -1e9;

int maxSubArraySum(int arr[], int n){
    int maxSum=minusinf;
    int dp[100]={0};
    dp[0]=arr[0]>0?arr[0]:0;//if first element is positive then add it else add zero
    for(int i=1;i<n;i++){
        dp[i]=arr[i]+dp[i-1];
        if (dp[i]<0)  dp[i]=0;
        maxSum=max(maxSum,dp[i]);

    }
    return maxSum;
}
//spaec optimization: only use one variable (i.e last value) to get next sum

int main(){
    int arr[]={-3,2,5,-1,6,3,-2,7,-5,2};
    int n=10;
    cout<<maxSubArraySum(arr,n)<<" ans by dp"<<endl;
}