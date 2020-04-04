#include <bits/stdc++.h>
using namespace std;

int maxProfitTD(int arr[], int n){
    if (n==0)  return 0;
    int best=0;
    for (int i=1;i<=n;i++){
        int netProfit=arr[i]+maxProfitTD(arr,n-i);
        best=max(netProfit,best);
        //cout<<best<<" "<<endl;
    }    
    return best;
    }
 
    int main(){
       int n=4;
       int arr[]={2,3,2,5};
       cout<<maxProfitTD(arr,n)<<" and by TD";
    }