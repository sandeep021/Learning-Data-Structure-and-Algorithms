//do bfs for every node because if current node is source of bfs and is part of cycle then it will give the correct length
//if not then it will only give cycle length for those cycle of which it is part. 
//when you find a cylcle update the min length


//calling bfs on each node when we find a backage we will update our ans length.
#include <bits/stdc++.h>
#include<list>
#include<map>
#include <queue>
using namespace std;
//Cycle Detection in UNDIRECTED graph
class Graph{
        map<int, list<int>> adjList;
    public:
        Graph(){

        }
        void addEdge(int u, int v, bool bidir= true){
            adjList[u].push_back(v);
            if (bidir) adjList[v].push_back(u);
        }

        

        void isCycle(int src, int &ans){
            map<int, int> parrent;
            map<int , int> distance;
            for(int i=0;i<7;i++){
                distance[i]=INT_MAX;
                parrent[i]=0;
            }
            queue<int> q;
            q.push(src);
            parrent[src]=src;
            distance[src]=0;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto child: adjList[node]){
                    if(distance[child]==INT_MAX){
                        distance[child]=distance[node]+1;
                        q.push(child);
                    }
                    else if(distance[child]>=distance[node]) {//here it finds a backedge.
                        ans= min(ans, distance[node]+distance[child]+1);//updating the ans
                    }
                }
            }
        }
};

int main(){
    int ans=7;
    Graph  g;
    g.addEdge(5,6);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(2,5);
    g.addEdge(4,5);
    g.addEdge(5,3);
    for(int i=1;i<=6;i++){
        g.isCycle(i,ans);//calling on each node tp get all the cycles that will be formed
        // cout<<ans<<" ";
   }
    cout<<ans<<" ";
}
