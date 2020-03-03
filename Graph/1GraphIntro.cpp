//facebook: edge rank algo
//uses of graph, google maps, facbook frieds, 
//routing techique(bellme ford)
/*Representatio of graph
1. Edge List
2. Adjacency Matrix
3. Adjacency list(mostly used)
*/


//integer adjacency list code
#include <iostream>
#include <list>
using namespace std;


class Graph{
        int V;
        list<int> *l;//pointer to list of integer

    public:
        Graph(int v){
        V=v;
        //Arrays(fixed size) of linked lists(dynamic)
        l=new list<int> [V];
        }
        //edge from u tov
        void addEdge(int u, int v, bool bidir=true){
            l[u].push_back(v);
            if (bidir)  l[v].push_back(u);
        }

        void PrintAdjacencyList(){
            for(int i=0;i<V;i++){
                cout<<i<<"->";
                for(int vertex: l[i]){
                    cout<<vertex<<", ";
                    }
                cout<<endl;
            }
        }


};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,3);
    g.PrintAdjacencyList();







}
