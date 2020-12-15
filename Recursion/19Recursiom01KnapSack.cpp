#include<bits/stdc++.h>
using namespace std;
int maxsum=INT_MIN;
void fun(vector<int> w, vector<int> p, int capc, int sum, int start){
	if(start==w.size()-1 || capc==0) {
		cout<<sum<<" sum-------"<<endl;
		maxsum=max(sum, maxsum);
		return;
	}
	for(int i=0;i<w.size() && w[i+1]<=capc ;i++){	
		sum+=p[i];
		cout<<sum<<" fun "<<endl;
		fun(w, p, capc-w[i], sum, i+1);
		sum-=p[i];
	}
	return;
	
}

int main(){
     int n;
     cin>>n;
     vector<int> w;
     vector<int> p;
     for(int i=0;i<n;i++){
     	int a;
     	cin>>a;
     	w.push_back(a);
     }
     for(int i=0;i<n;i++){
     	int b;
     	cin>>b;
     	p.push_back(b);
     }
     fun(w, p, 6, 0, 0);
    cout<<maxsum;
	
}
	
/* input
  4
1 2 3 5
40 20 35 100
140
  output


*/