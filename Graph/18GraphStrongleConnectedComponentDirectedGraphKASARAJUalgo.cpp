#include<bits/stdc++.h>
using namespace std;

//strongely connected components are those in which we can go to all the nodes of the component from any node
//of the component.

//a graph can have many SCC.

//kosaraju's algo----
//step1. do topological ordering 
//step2. create a copy of graph and reverse its all the edge directions.
//step3. pick first element from the odering(left to right) and do dfs taking it as a source ---this will give one SCC.
                        //also mark these node as visited 
                        //now do same for other unvisited nodes from ordering.
list<int> l;
void dfs(vector<int> adjList[100], int node, vector<int> &visited){
    visited[node]=1;
    for(auto nbr: adjList[node]){
        if(visited[nbr]==0) dfs(adjList, nbr, visited);
    }
    l.push_back(node);
}


void dfs2(vector<int> revG[100], int node, vector<int> &v ){
     v[node]=1;
     cout<<node<<" ";
     for(auto nbr: revG[node]) if(v[nbr]==0) dfs(revG, nbr, v);
}


int main(){
    vector<int> adjList[100];
    vector<int> revG[100];
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        revG[v].push_back(u);
    }
    vector<int> visited(n+1, 0);
    for(int i=0;i<n;i++){
        if(visited[i]==0) dfs(adjList, i, visited);
    }
    for(auto i: l)cout<<i<<" ";
    cout<<endl;
    vector<int> v(n, 0);
    char comp='A';
    for(auto i: l){
        //int node=l[i];
        if(v[i]==0) {
            cout<<" component "<<comp<<" -> ";
            dfs2(revG, i, v);
            comp++;
            cout<<endl;
        }
    }

}