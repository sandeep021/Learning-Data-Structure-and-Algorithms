#include <iostream>
#include <queue>
using namespace std;
//very powerfull always thk of this once if sorting is getting used

//push---> O(logn);
//pop---->O(logn);
//empty
int main(){
    priority_queue<int> pq_max;//by default pq is max heap prioroty;
    pq_max.push(1);
    pq_max.push(3);
    pq_max.push(10);
    pq_max.push(6);
    pq_max.push(0);
    pq_max.push(-5);
    cout<<pq_max.size()<<endl;
    while(!pq_max.empty()){
        cout<<pq_max.top()<<" ";
        pq_max.pop();
    }
    cout<<endl;

    priority_queue <int, vector<int>, greater<int>> pq_min;// method to reverse the priority
    pq_min.push(1);
    pq_min.push(3);
    pq_min.push(10);
    pq_min.push(6);
    pq_min.push(0);
    pq_min.push(-5);

    while(!pq_min.empty()){
        cout<<pq_min.top()<<" ";
        pq_min.pop();
    }
    cout<<endl;
    
    

}

//running time k largest element waala question isase aram se ho jaega;
//k size ka min heap pq maintain rakho smallest se bda aye to add kr do 
//query aye to sare pq ko print kr do
//QUICKSELECT