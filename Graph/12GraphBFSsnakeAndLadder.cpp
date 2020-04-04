#include <bits/stdc++.h>
using namespace std;
//Given a 1 to N snake sand Ladder board, starting and the neding points 
//of all Snakes and Ladders. You have to find out the minimum nmber of dice
//throws to win the game. Each dice throw can have any number from 1 to 6.



class Graph{
    private :
        map<int ,list<int>> adjList;
    public :
        Graph(){

        }

        void addEdge(int u, int v, bool bidir =true){
            adjList[u].push_back(v);
            if(bidir) adjList[v].push_back(u);
        }

        int bf(int src, int des){
            map<int,int> parrent;
            map<int, int> distance;
            for(auto i: adjList) distance[i.first]=INT8_MAX;
            queue<int> q;
            q.push(src);
            parrent[src]=src;
            distance[src]=0;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto nei: adjList[node]){
                    if(distance[nei]==INT8_MAX){
                        distance[nei]=distance[node]+1;
                        parrent[nei]=node;
                        q.push(nei);
                    }
                }
            }
            int temp=des;
            while(temp!=src){
                cout<<temp<<"==>";
                temp=parrent[temp];
            }
            cout<<src;
            cout<<endl;
            return distance[des];
        }
};

int main(){
    Graph g;
    int board[36]={0};//for snakes and ladders
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[17]=-13;
    board[18]=11;
    board[25]=-10;
    board[32]=-2;
    board[34]=-22;
    board[20]=-14;
    board[24]=-8;
    for(int u=0;u<=36;u++){//making the graph
        for(int d=1;d<=6;d++){
            int v=u+d+board[u+d];
            g.addEdge(u,v,false);
        }
    }
    cout<<g.bf(0,36);
}