//given a number genarate all the bracket pairs equal to the number
//eg n=2
//return (()), ()() 

#include<bits/stdc++.h>
using namespace std;

void fun(int n, int i, int open, int close, string temp){
	if(i==2*n){
		 cout<<temp<<endl;
		 return;
    }
    if(open<n) {
    	temp+='(';
    	fun(n, i+1, open+1, close, temp);
    	temp.pop_back();
    }
    
    if(close<open)	{
    	temp+=')';
    	fun(n, i+1, open, close+1, temp);
    	temp.pop_back();
    }
    
    return;
		
}

int main(){
    int n;
    cin>>n;
    string temp="";
    fun(n, 0, 0, 0, temp);
	
}
	

//intput 
//3
//output
/* 
((()))
(()())
(())()
()(())
()()()
*/