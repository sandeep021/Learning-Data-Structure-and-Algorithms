//time complexitu O(V+E)
//space O(V)
//queue for fifo and array/map tp maintain the record of the visited nodes
//iterative approach
//used in single source shortest path unweighted graph algo
//used in finding connected componets 
//used in flood fill algo in Bucket Tool in photoshop, paint etc
// for coloring regions with same color
#include <iostream>
#include<list>
#include <queue>
#include<map>
using namespace std;

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

        void print(){
            for(auto i: adjList){
                cout<<i.first<<"-> ";
                for(auto j: i.second)
                    cout<<j<<", ";
                cout<<endl;
            }
        }
        void bfs(T src){
            queue<T> q;
            map<T,bool> visited;
            q.push(src);
            visited[src]=true;
            while(!q.empty()){
                T node=q.front();
                cout<<node<<", ";
                q.pop();
                //for neighbours of current node find nodes which are not visited
                for (auto neighbour: adjList[node]){
                    if (!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour]=true;
                    }
                }

            }

        }

        void SSSPusingBFS(T src){
            queue<T> q;
            map<T,int> distance;
            map<T,T> parrent;
            for(auto i: adjList)
                    distance[i.first]=INT8_MAX;
            q.push(src);
            distance[src]=0;
            parrent[src]=src;
            while(!q.empty()){
              T node =q.front();
              q.pop();
              for (auto neighbours: adjList[node]){
                  if (distance[neighbours]==INT8_MAX){
                      q.push(neighbours);
                      distance[neighbours]=distance[node]+1;
                     parrent[neighbours]=node;
                  }
              }
                
            }
            for(auto i: adjList)
                cout<<"distance of "<< i.first <<"from "<<src<<" is "<<distance[i.first]<<endl;
            
        }
};

int main(){
    Graph<int> g1;
    g1.addEdge(2,3);
    g1.addEdge(0,1);
    g1.addEdge(0,4);
    g1.addEdge(4,3);
    g1.addEdge(1,4);
    g1.addEdge(1,2);
    g1.addEdge(1,3);
    //g1.print();
    //g1.bfs(0);
    g1.SSSPusingBFS(0);
}