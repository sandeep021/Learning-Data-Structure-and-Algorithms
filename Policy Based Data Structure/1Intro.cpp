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


//for pair of int................notice the changes
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    PBDS_pair;

int main(){
    PBDS st;
    st.insert(15);
    st.insert(0);
    st.insert(3);
    st.insert(7);
    st.insert(15);
    for(int i=0;i<st.size();i++){
        cout<<i<<" "<< *st.find_by_order(i) <<endl;//return iterator 
        //of ith largest element.
    }
    cout<<endl;
    cout<<st.order_of_key(15)<<endl;//return no of element strictly less than
    //i
    cout<<st.order_of_key(11)<<endl;
    cout<<st.order_of_key(17)<<endl;
}



// template<
// 	  typename Key, // Key type
// 	  typename Mapped, // Mapped-policy
// 	  typename Cmp_Fn = std::less<Key>, // Key comparison functor
// 	  typename Tag = rb_tree_tag, // Specifies which underlying data 