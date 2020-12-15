//All pair shortest pair path. O(n*n*n).
//dist[diaggonal]!=0 then there is a cycle in it;


//algo----------------
//dist is the dp vectorm we have to fill
//dist[i][j] will represent the distance betweem i and j.
//
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dist(n+1, vector<int> (n+1,INT_MAX));
    vector<vector<int>> edges;

    for(int i=0;i<m;i++){
        int from, to, weight;
        cin>>from>>to>>weight;
        edges.push_back({from, to, weight});
    }
    //taking 0 as intermediate
    //intermediate mean is node se hoker jane pe min dist.
    for(int i=1;i<=n;i++){
        dist[i][i]=0;
        dist[edges[i-1][0]][edges[i-1][1]]=edges[i-1][2];
    }
    //taking all other nodes as intermediate.
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);//formula for updation
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }


}