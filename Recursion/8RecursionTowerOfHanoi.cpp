#include <bits/stdc++.h>
using namespace std;
void fun(int n, char A, char B , char C){//A=src, B =helper, C=dest.
    if (n==0) {
        
        return;
    }

    fun(n-1,A,C,B);//yhs upr ke n-1 ko utha ke B pe rakh diya recursion se
    cout<<"Move "<<n<<" disk from "<<A<<" to "<<C<<endl;//A pe ek disc bachi h use C pe rakh diya
    fun(n-1,B,C,A);//now n-1 ddisc ko recursively B se C pe dal diya 
 

    
}

int main(){
    fun(4,'A','B','C');
}

//can be done iteratively by using 3 stacks and some logic. 