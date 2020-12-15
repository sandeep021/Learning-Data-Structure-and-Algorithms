#include <iostream>
#include<set>
using namespace std;
//stores unique and orderd ememnts;
//uses BST ot RBT 
//all operations in logn time.
//for updation u have delete then insert.
int main(){
    //int arr[10]={1,2,3,2,3,4,10,34,20};
    //int n=sizeof(arr)/sizeof(int);
    set<int> s={1,2,3,2,3,4,10,34,20};;
    //for(int i=0;i<n;i++) s.insert(arr[i]);
    for(auto it=s.begin();it!=s.end();it++) cout<<*it<<" ";
    cout<<endl;
    cout<<endl;
    s.erase(10);//it works also---------------imp;
    for(auto it=s.begin();it!=s.end();it++) cout<<*it<<" ";
    cout<<endl;
    cout<<endl;
    //u can also use find and then erase using thr index iterator
    auto it=s.find(3);
    s.erase(it);
    for(auto it=s.begin();it!=s.end();it++) cout<<*it<<" ";
}

//lower_bound and upper_bound also available