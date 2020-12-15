//sort the edges and start joining(uniting DSU ka) start adding nodes with min weighted edge
//jb cycle bnane lage tb add na kro bs.

#include <bits/stdc++.h>
using namespace std;

class DSU{
    public :
    vector <int> parent;
    int total_comp;
   DSU(int n){
       parent.resize(n);
       for(int i=1;i<=n;i++) parent[i]=i;//making every element their own parent
       total_comp=n;//total sets will be n;
    }

    int get_superParent(int x){//recursive funtion visulizw while revising
        if(x==parent[x]) return x;
        else return parent[x]=get_superParent(parent[x]);//path compression // TC is O(1)
    }

    void unite(int x, int y){//taking union of two sets
        int superParent_x=get_superParent(x);
        int superParent_y=get_superParent(y);
        if( superParent_x!=superParent_y){//checking if they are in same component or not
            parent[superParent_x]=superParent_y;
            total_comp--;
        }
    }

};


int main(){
   
    int n, edges;//n is total nodes
    cin>>n>>edges;
    int cnt=0;
    vector<vector<int>> weightEdge(edges);
    for(int i=0;i<edges;i++){
        int x,y,w;
        cin>>w>>x>>y;
        weightEdge[i]={w,x,y};      
    }
    sort(weightEdge.begin(), weightEdge.end());
    DSU dsu(n);
    int totalweight=0;
    for(int i=0;i<edges;i++){
        int w=weightEdge[i][0];
        int x=weightEdge[i][1];
        int y=weightEdge[i][2];
        //cout<<w<<" "<<x<<" "<<y<<endl;
         if(dsu.get_superParent(x)!=dsu.get_superParent(y)){
             dsu.unite(x,y);
             totalweight+=w; 
             //cout<<"check "<<totalweight<<endl; 
         }                   
    }
    cout<<totalweight<<endl;
}

/*
intput

4 6   nodes, edges
1 1 2 weight, node1, node2
2 1 3
2 2 3
3 2 4
3 3 4
2 1 4

*/