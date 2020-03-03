#include <iostream>
#include <unordered_map>//seperate chaining
#include<map>//Balanced BST or Red Black Tree
using namespace std;

int main(){
    unordered_map<string,int> myMap;
    //3 ways of insertion
    myMap["Mango"]=100;
    myMap.insert(make_pair("apple",200));
    pair<string, int> p("kiwi", 300);
    myMap.insert(p);

    //Print
    for(auto node: myMap){//auto khud datatype detect kr leta h
    //auto nhi use krna to uski jagah pe data type likh do
        cout<<node.first<<", "<<node.second<<endl;
    }
    for (int i=0;i<myMap.bucket_count();i++){
        cout<<"Bucket "<<i<<" ->";
        for(auto it= myMap.begin(i);it!=myMap.end(i);it++)
            cout<<it->first<<" "<<it->second<<", ";
        cout<<endl;
    }  

}

//myMap.count("Mango") it returns 0(not present) or 1(present)