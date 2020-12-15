//multiply a and b without using operator *\
//use recursion

#include <bits/stdc++.h>
using namespace std;
int fun(int a, int b){
    if(b==0) return 0;
    else if(b<0) return -fun(a,-b);
    else return a+fun(a,abs(b)-1);
}

//string to integer using recursion

double recFun(string s){
    if(s.length()==1) return s[0]-'0';
    double x=s[0]-'0';//first wale ko int kr diya aur x me store
    double y=recFun(s.substr(1));// baki bache walo ko recursion se int kr liya aur y me store
    ///cout<<y<<"  ";
    
    x=x*pow(10,s.length()-1)+y;//ab dono ko jod diya
    return x;
}


int main(){
    int a,b;
    //cin>>a>>b;
    //cout<<fun(a,b);
    //cout<<endl;
    //cout<<endl;
    cout<<recFun("12345");
}