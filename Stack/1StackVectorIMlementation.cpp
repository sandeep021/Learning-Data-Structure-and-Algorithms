//vector implementation of stack.
//template is use to generalize this stack for all data types.

#include <iostream>
#include<vector>
using namespace std;

template<typename T> 
//template<typenmae T, typename U>  //to generalize it for any data tpe, multiple typename can be used
class stack{
    private:
        vector<T> v;
    public:
        void push(T data){
            v.push_back(data);
        }

        bool isEmpty(){
            return (v.size()==0);
        }

        void pop(){
            if (!isEmpty())
                v.pop_back();
            else cout<<"stack is empty cant be poped"<<endl;
        }

        T top(){
            return v[v.size()-1];
        }
};


int main(){
    stack<char> s;
    for (int i=65;i<70;i++){
        s.push(i);

    }

    while(!s.isEmpty()){
        cout<<s.top()<<", ";
        s.pop();
    }


    return 0;
}


//stack STL is present refer cplusplus.com for more info.