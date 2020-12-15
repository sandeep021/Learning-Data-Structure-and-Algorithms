#include <iostream>
#include<map>
#include <string>
using namespace std;

int main(){
    multimap<char, string> map;
    map.insert(make_pair('a', "angry"));
    map.insert(make_pair('e', "empty"));
    map.insert(make_pair('d', "dog"));
    map.insert(make_pair('a', "animal"));
    map.insert(make_pair('f', "fly"));
    map.insert(make_pair('z', "zoo"));
    map.insert(make_pair('d',"dangerous"));

    for(auto i: map) cout<<i.first<<"->"<<i.second<<endl;
    cout<<endl;
    //subpart traversal
    auto it1= map.lower_bound('a');//index of first a ;(General; it give eqaul or just greater element(if not present))
    auto it2=map.lower_bound('f');//index just above last occuring f;(General it always gives just greater elemnent)
    for(auto i=it1;i!=it2;i++) cout<<i->second<<" ";
    cout<<endl;
    //erase
    auto it=map.begin();
    map.erase(it);
    cout<<endl;
    for(auto i: map) cout<<i.first<<"->"<<i.second<<endl;
    
    cout<<endl;
    //find
    auto f=map.find('d');
    if (f->second=="dangerous") cout<<"yes found";
    else cout<<"not found";


}