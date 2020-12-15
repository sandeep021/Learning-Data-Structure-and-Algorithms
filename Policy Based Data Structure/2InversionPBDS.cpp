#include<bits/stdc++.h>
using namespace std;


//for pbds
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

//for int
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    PBDS;

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        v.push_back(a);
    }
    int inversions=0;
    PBDS st;
    for(int i=0;i<n;i++){
        inversions+=st.size()-st.order_of_key(v[i]);//element greater than current element in the set. used to find inversions.
        st.insert(v[i]);
    }
    cout<<inversions<<endl;
}

//codeforces https://codeforces.com/problemset/problem/1324/D