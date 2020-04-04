//time complexitu O(V+E)
//space O(V)
//cant be used to find shortedt path like bfs
//recursive approach
#include <iostream>
#include<list>
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
        void dfsHelper(T node, map<T,bool> &visited){
            visited[node]=true;
            cout<<node<<" ";
            //find not visited neighbour of node and solved it recusively
            for(auto neighbour: adjList[node]){
                if (!visited[neighbour]){
                    dfsHelper(neighbour, visited);
                }
            }
        }

        void dfs(T src){
            map<T,bool> visited;
            dfsHelper(src, visited);
            //here to get another component of graph we have to
            //find the vertex from adjList which is not visited then call
            //dfsHwlpwer on that
            /* cout<<endl;
            int component=0;
            for(auto i: adjList){
                T city=i.first;
                if(!visited[city]){
                    defHelper(city, visited);
                    component++;
                }
            }*/
        }
};


int main(){
    Graph <int> g;
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,3);
    g.dfs(0);
}
//it can be used to detect disconnencted if the graph is disconnected
//then it will give only connected part with given source
//to get all the connected part(forest) we hav to input source of each part