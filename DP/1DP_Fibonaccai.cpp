//normal recursion will take O(2^n) time
//usinng dp it takes only O(n)
#include <bits/stdc++.h>
using namespace std;
int memo[1000];//global memoization table

int fibo(int n){
    if (n==0)  return 0;
    if (n==1) return 1;
    if (memo[n]!=-1) return memo[n];//checking that value is already calculated or not
    //because already calculated value will take O(1)[base adddres* i] time instead of getting 
    //calculated again
    int ans = fibo(n-1)+fibo(n-2);
    memo[n]=ans;//storing the result;
    return ans;
}

//bottom up approach for fib no--> in this we asuume to calculate the n th 
//fib number but actuall we calculate  all no from 0 to n-1 and store it
//beacuse we know that we have to calculate them at some time.
//this approcah is actuall dp.
int fib(int n){
    int dp[1000];//to store previous values
    dp[0]=0;
    dp[1]=1;
    for (int i=2;i<=n;++i)
        dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}


//bottom up approach with space optimizatio can be used 
//,sice we are using only previous two variables we will store them
// in two variable and the space complexity will become O(1)

int fibSpace(int n){
    int a=0;
    int b=1;
    int c;
    for (int i=2;i<=n;++i){
        c=a+b;
        a=b;
        b=c;
    }
        
    return c;
}

int main(){
    int n;
    cin>>n;
    for (int i=0;i<=n;i++)  memo[i]=-1;  //because -1 cant represent any fibo no
    cout<<fibo(n)<<" ans from memoization "<<endl;
    cout<<fib(n)<<" answer from bottom up"<<endl;
    cout<<fibSpace(n)<<" ans by space optimaization of bottom up approach"<<endl;
}