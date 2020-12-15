#include <iostream>
#include <deque>
using namespace std;
//given n(size of array), k(size of window), you have to print max value of each window in O(n);
int main(){
    int n,k;
    cin>>n>>k;
    int arr[10000];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    deque<int> q(k);
    int i;
    //first we will push max value in the queue
    //we will also push_back the min value whuch comes just after the max
    //so that we can use it in next window
    for(i=0;i<k;i++){
        while(!q.empty() && arr[i]>=arr[q.back()]){//if we find a value great than the last value in queue
        //we will update the ;ast value
        q.pop_back();
        }
        q.push_back(i);
    }

    for(;i<n;i++){
        cout<<arr[q.front()]<<" ";
        //removng tha values which are not in window now
         while(!q.empty() && q.front()<=i-k){
            q.pop_front();
        }
        //check and updating new coming values
        while(!q.empty() && arr[i]>=arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);    
    }
cout<<arr[q.front()];

    
}

//input 
//9 3
//1 2 3 1 4 5 2 3 6
