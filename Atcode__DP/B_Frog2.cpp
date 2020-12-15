#include <bits/stdc++.h>
using namespace std;
int dp[10000]={0};
int fun(vector<int> v, int k){
    int n=v.size();
    dp[0]=0;
    dp[1]=abs(v[1]-v[0]);
    for(int i=2;i<n;i++){
        int temp=INT_MAX;
        for(int j=1;j<=k && j<i;j++){
            temp=min(temp, abs(v[i]-v[j])+dp[j]);
        }
        dp[i]=temp;
    }
    for(int i=0;i<n;i++) cout<<dp[i]<<" ";
    return dp[n-1];

}

int main(){
     int n,k;
     cin>>n>>k;
     vector<int> v;
     for(int i=0;i<n;i++){
         int a;
         cin>>a;
         v.push_back(a);
     }
     fun(v,k);

}







{
            dp[i+1] = dp[i] + books[i][1];
            int width = books[i][0], height = books[i][1];
                for (int j = i-1; j >= 0 && width + books[j][0] <= shelf_width; --j)
                {
                    width += books[j][0];
                    height = max(height, books[j][1]);
                    dp[i+1] = min(dp[j]+height, dp[i+1]);
                }
        }