#include <bits/stdc++.h>
using namespace std;
//simple algorithm that outputs linear ordering of vertices of the graph
///such that (u->v) then u comes before v
//works only of DAG directed acyclic graphs

void addEdge(string u, string v, map<string, list<string>> &adjlist, bool bidir=true){
    adjlist[u].push_back(v);
    if(bidir) adjlist[u].push_back(u);
}
//int this algo we will push the node which has indegree 0;
//pop them adjust the indegree of its child also have to maintail the 
//visiting map to mark the visited nodes 

void topoLOgicalSortBFS(map<string, list<string>> &adjlist){
    map<string, bool> visited;
    map<string, int> indegree;
    queue<string> q;
    for(auto i: adjlist){
        string node=i.first;
        visited[i.first]=false;
        indegree[i.first]=0;
    }
    for(auto u: adjlist){//here there is edge from u to v
        string x=u.first;
        for(auto v : adjlist[x]){
            indegree[v]++;
        }
    }
    for(auto i: adjlist){
        string node = i.first;
        if (indegree[node]==0) q.push(node);//pushing all node which has
        //indegree 0;
    }

    while(!q.empty()){
        string temp=q.front();
        cout<<temp<<" -->";
        visited[temp]=true;
        for(auto nei: adjlist[temp]){
            indegree[nei]--;
            if(indegree[nei]==0) q.push(nei);
        }
        q.pop();
    }
}

int main(){

    map<string, list<string>> adjlist;
    addEdge("English","Programming Logic",adjlist, false);
    addEdge("Math","Programming Logic",adjlist, false);
    addEdge("Programming Logic","HTML",adjlist, false);
    addEdge("English","Programming Logic",adjlist, false);
    addEdge("Programming Logic","Python",adjlist, false);
    addEdge("Programming Logic","Java",adjlist, false);
    addEdge("Python"," Web Dev",adjlist, false);
    addEdge("HTML","CSS",adjlist, false);
    addEdge("CSS","JS",adjlist, false);
    addEdge("CSS","JS",adjlist, false);
    addEdge("CSS","JS",adjlist, false);
    addEdge("JS","Web Dev",adjlist, false);
    topoLOgicalSortBFS(adjlist);
}