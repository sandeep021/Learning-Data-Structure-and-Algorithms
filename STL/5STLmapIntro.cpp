#include <iostream>
#include<map>
#include <string>
using namespace std;
//map stores values in sorted order wrt to keys
//uses bst so operations are logrithmic times
int main(){
    map<string, int> map;
    map.insert(make_pair("apple",30));
    map["kiwi"]=10;
    pair<string, int> p=make_pair("banana",20);
    map.insert(p);
    map["lichi"]=40;

    // search  method 1
    auto it=map.find("kiwi");
    if(it==map.end()) cout<<"not found";
    else cout<<"Price is "<<map["kiwi"]<<endl;

    map.erase("kiwi");//can alsoe delete;

    // search method2
    //this method works because map stores unique keys only
    //map.count() return 0 or 1.
    if (map.count("kiwi")) cout<<"present"<<endl;
    else cout<<"cant found"<<endl;
    
    for(auto it =map.begin();it!=map.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl;

    for(auto i: map){
        cout<<i.first<<" "<<i.second<<endl;
    }


}

//vertical order print of BST problem