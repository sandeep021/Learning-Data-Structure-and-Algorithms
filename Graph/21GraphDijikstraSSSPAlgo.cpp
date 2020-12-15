///it is single source shortest path algorith for weighted graph.
//for unweighted graph we can use BFS also.
//


///take initial distances as infinity .
//now make distance of start 0
//go to all its neighbour and update distance as dist[parent]+w;
//pick least distance node from all the neighbour(used set for getting min in O(1)) 
//and repeat 8.

#include<bits/stdc++.h>
using namespace std;

void dijikstra(int src, map<int, vector<pair<int, int>>> G){
	set < pair<int, int>> set;//first is distance second is node number
	unordered_map<int, int> dist;//node and distance from src.
	for(auto i: G) dist[i.first]=INT_MAX;
	dist[src]=0;                                     //picking src
	set.insert({0, src});
	while(!set.empty()){                             //for picking least nodes
		auto p=*set.begin();
		int node= p.second;//node.
		int nodeDist=p.first;//distance of th node.
		set.erase(set.begin());
		//cout<<node<<endl;                          //going to all its neighbours
		for(auto nbr : G[node]){
			//cout<<"check ";
			if(dist[nbr.first]>nodeDist+nbr.second) {  //checking and updting dist
			auto f= make_pair(dist[nbr.first], nbr.first);
				if(set.find(f)!=set.end()){
					set.erase(f);
				}
			dist[nbr.first]=nodeDist+nbr.second;
			set.insert({dist[nbr.first], nbr.first});
			}
		}
	}
	for(auto i: dist) cout<<src<<" --> "<<i.first<<"  "<<i.second<<endl;
}


int main(){
 map<int, vector<pair<int, int>>> G;
int n,m;
cin>>n>>m;
for(int i=0;i<m;i++){
	int u,v,w;
	cin>>u>>v>>w;
	G[u].push_back({v, w});
	G[v].push_back({u, w});
}
//for(auto k: G[1]) cout<<k.first<<" "<<k.second<<endl;
dijikstra(1, G);
}

/*
input
5 6
1 2 4
2 4 6
4 3 3
3 5 1
5 1 2
1 4 7

output
1 --> 5  2
1 --> 4  6
1 --> 3  3
1 --> 1  0
1 --> 2  4
*/


