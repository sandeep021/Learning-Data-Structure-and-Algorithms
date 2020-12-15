//atep 1. distance[src]=0;
//        distance[others]=inf;

//step 2. relax all nodes n-1 times, n is no of nodes.

//if negative weight cycle is present then after n-1 iteratin next iteration will also change some values.

//TC is O(V.E) or O(n*n)

//Directed graps mostly
#include<bits/stdc++.h>
using namespace std;

vector<int > bellmanFord(int n, int src, vector<vector<int>> edges){
    vector<int> dist(n+1, 1000);
    dist[src]=0;

    //relaxation
    for(int i=0;i<n-1;i++){
        for(auto x: edges){
           int from =x[0];
           int to=x[1];
           int weight=x[2];
           if( dist[to]>dist[from]+weight){
               dist[to]=dist[from]+weight;
              // cout<<dist[to]<<" ";
           }
        }
    }
    for(auto x: edges){
           int from =x[0];
           int to=x[1];
           int weight=x[2];
           if(dist[to]>dist[from]+weight){
               cout<<"negative";
               exit(0);
           }
               
    }
    //for(auto i: dist) cout<<i<<" ";
    return dist  ;          
}


int main(){
    int n,m;//n is nodes m is edges.
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int from, to, weight;
        cin>>from>>to>>weight;
        edges.push_back({from, to, weight});//storing  edges no need to make whole graph.
    }
    vector<int > ans= bellmanFord(n, 1, edges );
    for(int  i=1 ; i<=n;i++) cout<<"distance from src to "<<i<<" is "<<ans[i]<<endl;

}