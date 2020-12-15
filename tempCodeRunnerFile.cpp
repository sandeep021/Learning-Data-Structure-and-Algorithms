#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
#define ff first
#define ss second
#define pb push_back
#define debug(val, ch) cout <<val <<ch
#define FOR(i, st, en, ch) for(register int i = (st); i < (en) ; i += (ch))
#define RFOR(i, st, en, ch) for(register int i = (st); i > (en) ; i -= (ch))
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, -1, 1)
#define FORE(it, cont) for(auto it : cont)
 
typedef long long int lli;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<lli> vli;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;
typedef pair<double, double> pdd;
 


int main() {
 int test;
 cin>>test;
 while(test--){
   lli a,k;
   cin>>a>>k;
   
   for(lli i=1;i<k;i++){
     lli n=a;
     lli mini=INT_MAX;
     lli maxi=0;
     int p=5;
     while(n >0 && p>0){
       lli temp=n%10;
       mini=min(mini,temp);
       maxi=max(maxi,temp);
       n=n/10;
       p--;
     }
     if(mini*maxi==0) break;
     a=a+mini*maxi;
   }
   cout<<a<<endl;
 }
 return 0;
  
}