#include <iostream>
#include <set>
using namespace std;
//same as set but not maintains the unique elemnt property
//uses BST internally.
typedef multiset<int>::iterator It;

int main() {

    int arr[] = {10,20,30,30,30,20,10,10,80};
    multiset<int> m(arr,arr+9);

    //3. Erase
    cout<<m.erase(20) <<endl;

    //1. Iterator
    for(int x:m){
        cout<<x<<",";
    }
    cout<<endl;
    //2. Count Function
    m.insert(78);
    cout<<"count is"<< m.count(78) <<endl;

    //4. Find
    auto it = m.find(30);
    cout<<(*it)<<endl;

    //5. Equal Range---------------------------------------->new
    //to get all the occurances of a element.
    pair<It,It> range = m.equal_range(10);
    for(auto it = range.first;it!=range.second;it++){
        cout<<*it<<endl;
    } 


    //Lower Bound and Upper Bound
    for(auto it=m.lower_bound(10);it!=m.upper_bound(80);it++){
        cout<<*it<<",";
    }

    return 0;
}
