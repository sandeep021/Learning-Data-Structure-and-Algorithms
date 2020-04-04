#include <iostream>
#include<list>
#include<map>
#include <queue>
using namespace std;
//Cycle Detection in UNDIRECTED graph
template<typename T>
class Graph{
        map<T, list<T>> adjList;
    public:
        Graph(){

        }
        void addEdge(T u, T v, bool bidir= true){
            adjList[u].push_back(v);
            if (bidir) adjList[v].push_back(u);
        }

        //in this algo we check if we visit a node1 that is already vistied it
        //means a cycle is present in it but we have to also check that this node1
        //is not parrent of the node from where we are visiting node1;
        // else everything is same as bfs 

        bool isCycle(T src){
            map<T,T> parrent;
            map<T,bool> visited;
            queue<T> q;
            q.push(src);
            visited[src]=true;
            parrent[src]=src;
            while(!q.empty()){
                T node=q.front();
                q.pop();//
                for(auto neighbours: adjList[node]){
                    if (visited[neighbours]==true && parrent[node]!=neighbours)
                        return true;
                    else if (!visited[neighbours]){
                        visited[neighbours]=true;
                        q.push(neighbours);
                        parrent[neighbours]=node;
                    }
                }
            }
            return false;


        }
};

int main(){
    Graph <int> g;
    g.addEdge(0,1);
    //g.addEdge(0,4);
    //g.addEdge(4,3);
    //g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    //g.addEdge(1,3);
    cout<<g.isCycle(0);
}