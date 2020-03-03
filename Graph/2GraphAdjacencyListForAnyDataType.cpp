//code to implement graph of any data type;
//hash map is used 
//output will be in sorted order

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
};

int main(){
    Graph<string> g;
    g.addEdge("putin", "trump", false);
    g.addEdge("putin", "Modi", false);
    g.addEdge("putin", "pope", false);
    g.addEdge("Modi", "trump", true);
    g.addEdge("Yogi", "Prabhu", false);
    g.addEdge("Prabhu", "Modi", false);
    g.print();

    Graph<int> g1;
    g1.addEdge(2,3);
    g1.addEdge(0,1);
    g1.addEdge(0,4);
    g1.addEdge(4,3);
    g1.addEdge(1,4);
    g1.addEdge(1,2);
    g1.addEdge(1,3);
    g1.print();
}