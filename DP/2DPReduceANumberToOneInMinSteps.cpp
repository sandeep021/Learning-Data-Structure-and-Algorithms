#include <bits/stdc++.h>
using namespace std;
const int inf =(int)1e9;

int reduceNo(int n){
    if (n==1)  return 0;
    int q1=inf, q2=inf, q3=inf;
    if (n%3==0) q1=1+reduceNo(n/3);//3 se divide kr lo baki ans recuesion de dega
    if (n%2==0)  q2=1+reduceNo(n/2);//2 se divede kr lo baki ans recursion de dega 
    q3=1+reduceNo(n-1);//1 se minus kro baki ans recursion se;
    return min(q1,min(q2,q3));//min can be use for only two arguments;
}

int memo[10000];
int reduceNoMemo(int n){
    if (n==1)  return 0;
    int q1=inf, q2=inf, q3=inf;
    if (memo[n]!=-1)  return memo[n];
    if (n%3==0) q1=1+reduceNo(n/3);//3 se divide kr lo baki ans recuesion de dega
    if (n%2==0)  q2=1+reduceNo(n/2);//2 se divede kr lo baki ans recursion de dega 
    q3=1+reduceNo(n-1);//1 se minus kro baki ans recursion se;
    memo[n]= min(q1,min(q2,q3));;
    return memo[n];//min can be use for only two arguments;
}


int reduceNoBottomUPDP(int n){
    int dp[100]={0};
    dp[1]=0;
    for (int i=2;i<=n;i++){    
        int q1=inf;
        int q2=inf;
        int q3=inf;
        if (i%3==0) q1=dp[i/3];
        if (i%2==0) q2=dp[i/2];
        q3=dp[i-1];
        dp[i]=min(min(q1,q2),q3)+1;

    }
    for(int i=0;i<=n;i++)  cout<<dp[i]<<"  ";
    cout<<"   "<<endl;
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    fill(memo,memo+n+1,-1);//keyword to fill all values with -1;
    //algoritm libray hai ye
    
    //cout<<reduceNo(n)<<" ans by recursion"<<endl;
    cout<<reduceNoMemo(n)<<" ans by memoization"<<endl;
    cout<<reduceNoBottomUPDP(n)<<" Ans by bottomup approach"<<endl;

}