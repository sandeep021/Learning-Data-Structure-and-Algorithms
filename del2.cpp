#include <bits/stdc++.h>
using namespace std;

int fun(int n){
    return (n*(n+1))/2;
}

int main() {
  int t;
  cin>>t;
  for(int test=1;test<=t;test++){
      int n,k;
      cin>>n>>k;
      int arr[n+1];
      int p[n+1]={0};
      p[0]=arr[0];
      for(int i=1;i<n;i++) p[i]=p[i-1]+arr[i];
      int cnt=0;
      int sumi=fun(k);
      if(p[k-1]=fun(k)) cnt++;
      for(int i=k;i<n;i++){
          if(p[i]-p[i-k]==sumi){
              cnt++;
          }
      }
      cout<<cnt;
      
     
  }
 return 0;
  
}