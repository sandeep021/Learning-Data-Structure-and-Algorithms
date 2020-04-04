#include <bits/stdc++.h> 
using namespace std;
//SSSP for weighted graph, bfs is used for only non weighted graph
//it give wrong result for negative weighted graphs(duue to negative cycle )
//O(VlogV+E) time with priority queue and (V*V+E) if array is used to store 
//to extract min value distance 
template<typename T>
class Graph{
    private:
        unordered_map<T,list<pair<T,int>>> m;
    public:
         void addEdge(T u, T v, int dist, bool bidir = true){
             m[u].push_back(make_pair(v,dist));
             if (bidir) m[v].push_back(make_pair(u,dist));
         }

         void PrintAdjList(){
             for(auto i: m){
                 cout<<i.first<<"-->";
                 for(auto j: m[i.first]){
                     cout<<" ("<<j.first<<" "<<j.second<<"), ";
                 }
                 cout<<endl;
             }
         }
//visited a node update its neighbour distance if possible
//repeat for all the nodes.

         void dijsktraSSSP(T src){
             unordered_map<T,int> dist;//to store distance
             set<pair<int, T>> s;//to store unvisted and in sorted oder distances
             for(auto i: m){
                 dist[i.first]=INT_MAX;//intially all distance are infinity
             }
             dist[src]=0;//distance of source is 0
             s.insert(make_pair(0,src));//pushing source node
             while(!s.empty()){//while set is  not empty
                 auto p=*(s.begin());//pop the min element
                 T node=p.second;
                 int nodeDist=p.first;
                 s.erase(s.begin());
                 for(auto nei: m[node]){//visit all its neighbour fro updating
                 //elaxing distances
                     
                     if(nodeDist + nei.second < dist[nei.first] ){
                         //we cant update value in set
                         //so we have to delte old one and 
                         //add the new value
                         T dest= nei.first;
                         auto f=s.find(make_pair(dist[dest],dest));
                         if (f!=s.end())  s.erase(f);
                         dist[dest]=nodeDist + nei.second;
                         s.insert(make_pair(nodeDist + nei.second,dest));
                     }
                 }  
             }
             for(auto i: dist){
                 cout<<"diatance of "<<i.first<<" from "<<src<<" is "<<i.second<<endl;
             }

         }

};

int main(){
    Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    //g.PrintAdjList();
   g.dijsktraSSSP(1);
}