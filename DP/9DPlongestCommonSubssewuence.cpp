#include<bits/stdc++.h>
using namespace std;

int LCS(string a, string b){
    int m=(a.length());
    int n=(b.length());
    int dp[100][100]={0};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i]==b[j]) {
                dp[i+1][j+1]=1+dp[i][j];
            }
            else {
                dp[i+1][j+1]=max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
           cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[m][n];
}

int main(){
    string a="fabcd";
    string b="axyd";
    cout<<LCS(a,b);
}