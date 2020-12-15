#include <bits/stdc++.h>
using namespace std;

int memo[100];
int maxProfitTD(int arr[], int n){
    if (n==0)  return 0;
    if(memo[n]!=-1) return memo[n];
    int best=0;
    for (int i=1;i<=n;i++){
        int netProfit=arr[i-1]+maxProfitTD(arr,n-i);
        best=max(netProfit,best);
        //cout<<best<<" "<<endl;
    } 
    memo[n]=best;   
    return best;
    }
 
    int main(){
       int n=4;
       int arr[]={2,3,2,5};
       for(int i=0;i<=n;i++) memo[i]=-1;
       //memo[0]=0;
       cout<<maxProfitTD(arr,n)<<" and by TD ";
       for(int i=0;i<=n;i++) cout<<memo[i]<<" ";
    }