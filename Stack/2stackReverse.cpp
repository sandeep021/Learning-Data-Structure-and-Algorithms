//Q. reverse the stack in same stack and return it

//METHOD1. use 2 extra stack and trnsfer s1 to s2 and s2 to s3 and back s3 tos1

//Method2. using 1 extra stack
//take top element now pop all remaining elements to new stack
//push this top elemrnt to original stack
//again push back all the elemnet from s2 to original
//repeat above and left poping of set elements

#include <iostream>
#include <stack> 
using namespace std;

void transfer(stack<int>& s1, stack<int>& s2, int n){
    for (int i=0;i<n;i++){
        s2.push(s1.top());
        s1.pop();
    }
}

void reverseStack(stack<int>& s1){
     int n=s1.size();
     stack <int> s2;
     for (int i=0;i<n;i++){
     int x=s1.top();
     s1.pop();
     transfer(s1, s2, n-i-1);//i element set ho cheke hai
     //1 element nikal rkha h set krne ke liye
     s1.push(x);
     transfer(s2,s1,n-i-1);     
     }
}

void insertAtBottom(stack<int>&s, int x){
    if (s.empty()) {
        s.push(x);
        return;
        }
    else{
        int y= s.top();
        s.pop();
        insertAtBottom(s,x);
        s.push(y);
    }
}

void recursiveReverseStack(stack <int>& s){
    if (s.empty())    return;

    int x=s.top();
    s.pop();
    recursiveReverseStack(s);
    insertAtBottom(s,x);
}

int main(){
    stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    reverseStack(s);
    recursiveReverseStack(s);
    while(!s.empty()){
        cout<<s.top()<<", ";
        s.pop();
    }

    return 0;
}