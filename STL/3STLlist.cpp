#include <iostream>
#include<list>
using namespace std;
//list is like double ended linked list
int main(){
    list<string> l;
    l.push_back("Apple");//push at back
    l.push_front("kiwi");//push at back;
    l.push_back("mango");
    l.push_front("grapes");

    for(auto s: l) cout<<s<<"-->";
    cout<<endl;
    l.sort();//inbuild sort function
    for(auto it =l.begin();it!=l.end();it++) cout<<*it<<"->";
    cout<<endl;

    string s1=l.front();//acces front element;
    l.pop_front();//delete front element
    string s2=l.back();//access back element
    l.pop_back();//pop back element
    cout<<s1<<endl;
    cout<<s2<<endl;
    l.push_back("lemon");//push at back
    l.push_front("orange");//push at back;
    l.push_back("mango");
    l.push_front("Apple");

    //it will remove all the occurences of apple from the list
    l.remove("Apple");
    for(auto it =l.begin();it!=l.end();it++) cout<<*it<<"->";
    cout<<endl;

    auto it =l.begin();
    it++;  //we cant do it+3
    it++;
    l.erase(it);//can rease element at particular index
    for(auto it =l.begin();it!=l.end();it++) cout<<*it<<"->";
    cout<<endl;

    auto it1 =l.begin();
    it1++;  //we cant do it+3
    it1++;
    l.insert(it1,"NewADD");

    for(auto it =l.begin();it!=l.end();it++) cout<<*it<<"->";
    cout<<endl;


    //forward_list---it is singly list
    //push, pop and top operration of stack works in O(1) time 

}