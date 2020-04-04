


#include <bits/stdc++.h>
using namespace std;
//Cycle detection in Undirected Graph using DFS

void addEdge(int u, int v, map<int, list<int>> &adjlist, bool bidir=true){
    adjlist[u].push_back(v);
    if(bidir) adjlist[v].push_back(u);
}
//in this we will visit all the nodes and chech if we are revisiting a node


bool dfsHelper(int node,map<int, bool> &visited, map<int, list<int>> &adjlist, int parrent ){
    visited[node]=true;
    for(auto nei: adjlist[node]){
        if(!visited[nei]){
            //1.node is not visited but it reaching to node which is returning
            //a cycle(whcih we are checking below)
            bool cycle = dfsHelper(nei,visited,adjlist, node);
            if(cycle) 
                return true;   
        }
        //2. if nide is visited and its parrent is node the node from which
        //we are reaching to it.
        else if(nei!=parrent)
                return true;
    }
    return false;
}

bool isCycleDFS(map<int, list<int>> &adjlist){
    map<int, bool> visited;

    for(auto i: adjlist){//for  all the component of graph
        if(!visited[i.first]){
            bool cycle=dfsHelper(i.first, visited, adjlist, i.first );
            if(cycle) return true;
        }
    }
    return false;
}

int main(){

    map<int, list<int>> adjlist;
    addEdge(1,2,adjlist);
    addEdge(2,3,adjlist);
    addEdge(3,4,adjlist);
    addEdge(4,1,adjlist);
    cout<<isCycleDFS(adjlist);
}