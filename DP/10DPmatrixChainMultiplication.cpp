#include<bits/stdc++.h>
using namespace std;


int memo[100][100]={0};
int MCM(int m[], int i, int j){//i,j is to make partition to find max
    if(i==j){ 
        memo[i][j]=0;
        return 0;
        
    }
    if(memo[i][j]!=-1) return memo[i][j];
    int mini=INT_MAX;
    for(int k=i;k<j;k++){//k is partition point  A(BCD) k=1 ,  AB(CD) , k=2
        int temp= MCM(m,i,k) + MCM(m,k+1,j) + m[i-1]*m[k]*m[j];//i to k tk ka cost + k+1 to j tk ka cost + waps merging ka time ka cost 
        mini=(mini,temp);//sare partition me se best wala le lenge
    }
    memo[i][j]=mini;
    return mini;
}

int MCMbottomUP(int m[], int n){
    int dp[100][100]={0};
    //for(int i=0;i<n;i++) dp[i][i]=0;
    for(int L=2;L<n;L++){
        for(int i=1;i<=n-L;i++){
            int j=i+L-1;
            int temp=INT_MAX;
            for(int k=i;k<j;k++){
                temp=min(temp, dp[i][k]+dp[k+1][j] + m[i-1]*m[k]*m[j]);
            }
            dp[i][j]=temp;
        }
    }
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<dp[i][j]<<" ";
        cout<<endl;
     }
    return dp[2][n];

}



int main(){
    int m[]={1,2,3,4};//----1X2 , 2X3, 3X4 ke teen matrix hai
    int n=4;//size of array
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++) memo[i][j]=-1;
    }
    cout<<MCM(m,1,3);//1 se 3 tk partition kr skte hai.
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++) cout<<memo[i][j]<<" ";
        cout<<endl;
    }
    MCMbottomUP(m,4);
}



//practice by drawing the tree diagram..

//https://www.youtube.com/watch?v=D1U74eFLg_g       ---------tutorial;