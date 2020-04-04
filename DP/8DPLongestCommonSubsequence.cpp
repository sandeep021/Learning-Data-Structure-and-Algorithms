#include <bits/stdc++.h>
using namespace std; 

int LIS(int arr[100], int n ){
    int dp[104];
    int best=-1;
    for (int i=0;i<n;i++)  dp[i]=1;
    for(int i=0;i<n;i++){//for each cell
        for (int j=0;j<i;j++){//for chacking all the previous value and updation current cell if lis exidt
            if (arr[j]<arr[i]){
                int currentLenght=dp[j]+1;//here state is the longest subsequence till that cell
                dp[i]=max(currentLenght,dp[i]);
            }
        }
        best=max(best,dp[i]);
    }
    return best;

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)  cin>>arr[i];

    cout<<LIS(arr,n)<<endl;
}