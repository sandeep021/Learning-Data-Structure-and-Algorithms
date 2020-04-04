#include <bits/stdc++.h>
using namespace std;
//Cycle detection in directed Graph using DFS

void addEdge(int u, int v, map<int, list<int>> &adjlist, bool bidir=true){
    adjlist[u].push_back(v);
    if(bidir) adjlist[v].push_back(u);
}
//here while traversing the node we put them in stack, and while revisiting it
//if we find it in stack again then its a cycle. we emptuing the stack while
//returning recursively.

bool dfsHelper(int node,map<int, bool> &visited,map<int, bool> & instack, map<int, list<int>> &adjlist ){
    visited[node]=true;
    instack[node]=true;
    for(auto nei: adjlist[node]){
        if((!visited[nei] && dfsHelper(nei,visited,instack,adjlist)) || (instack[nei] && visited[node]))
        //there are two cases when we get a cycle
        //1. when a node is not visited but it goes to a node which is making cycle
        //2. a node is already visited and also is in instack 
             return true;
    }
    instack[node]=false;
    return false;
}

bool isCycleDFS(map<int, list<int>> &adjlist){
    map<int, bool> visited;
    map<int,bool> instack;
    for(auto i: adjlist){//for  all the component of graph
        if(!visited[i.first]){
            bool cycle=dfsHelper(i.first, visited, instack, adjlist);
            if(cycle) return true;
        }
    }
    return false;
}

int main(){

    map<int, list<int>> adjlist;
    addEdge(0,2,adjlist, false);
    addEdge(0,1,adjlist, false);
    addEdge(2,3,adjlist, false);
    addEdge(2,4,adjlist, false);
    addEdge(3,0,adjlist, false);
    addEdge(4,5,adjlist, false);
    addEdge(1,5,adjlist, false);
    cout<<isCycleDFS(adjlist);
}