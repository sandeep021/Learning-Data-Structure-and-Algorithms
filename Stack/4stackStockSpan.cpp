#include <iostream>
#include <stack>
using namespace std;

void getSpan(int arr[], int n){
    stack <int> s;
    int ans[100]={};
    for (int day=0;day<n;++day){
        while (s.empty()==false && arr[s.top()]<arr[day])
                 s.pop();
        int betterDay=s.empty() ? 0 : s.top();
        int span= day-betterDay;
        ans[day]=span;
        s.push(day);
    }
    for (int i=0;i<n;i++){
        cout<<ans[i]<<", ";
    }
}

int main(){
    int arr[100]={100, 80, 60, 70, 60, 75, 85};
    int n=7;
    getSpan(arr,n);
}