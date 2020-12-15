//loop from 2 to root(n);
//loop to check how many times it divides thhe number
//
//finally when loop breaks iif (n!=1) then also add n to the factors list;\

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> v;
    for(int i=2;i*i<=n;i++){//root n tk
        int cnt=0;
        while(n%i==0){//check kitni bar divide kiya
            n=n/i;
            cnt++;
        }
        v.push_back(make_pair(i,cnt));
    }
    if(n!=1) v.push_back({n,1});
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<' '<<v[i].second<<endl;
    }
}

//sieve bhi use kr skte hai more optimisation ke liye ya rangeke liye