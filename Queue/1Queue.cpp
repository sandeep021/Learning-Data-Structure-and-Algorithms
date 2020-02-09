//front=0,rear=n-1,insertion will always take place at r+1


#include <iostream>
#include<vector>
using namespace std;

template<typename T>
class Queue{
    int f;//front
    int r;//rear
    int cs;//current size
    int ms;//max size
    int *arr;
    public:
        Queue(int ds=4){//default size of constructor
            ms=ds;
            f=0;
            r=-1;
            cs=0;
            arr=new T[ms];
        }


bool isFull()  {
    return cs==ms;
}

bool isEmpty(){
     return cs==0;
     }

void push(T data){
    if(!isFull()){
        r=(r+1)%ms;
        arr[r]=data;
        cs++;
    }
}

void pop(){
    if(!isEmpty()){
          f=(f+1)%ms;
          cs--;
    }
}

T getFront(){
    return arr[f];
}
};


int main(){
    Queue<int> q(100);
    for(int i=0;i<=6;i++){
        q.push(i);
    }

    q.pop();
    q.push(8);

    while(!q.isEmpty()){
        cout<<q.getFront()<<", ";
        q.pop();
 
    }
return 0;
}

//STL for queue available, more at c plus plus.com