//if x and y are in same component and we got another edge(unite(x,y)) then this edge will form a cycle 
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
    DSU dsu(n);
    int cnt=0;
    for(int i=0;i<edges;i++){
        int x,y;
        cin>>x>>y;
        if(dsu.get_superParent(x)!=dsu.get_superParent(y))
                dsu.unite(x,y);
        else cnt++;
    }
    if(cnt) cout<<"no cycle formed";
    else cout<<"cycle formed";
}