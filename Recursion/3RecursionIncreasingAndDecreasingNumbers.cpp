//given n print 1 to n in increasing and decreasing order 
#include<bits/stdc++.h>
using namespace std;

void dec(int n){
    if(n==0) return ;
    else {
        cout<<n<<" ";//pehle print hoga fir call stack me jaega bar bar
        //print(5),f(4),print(4),f(3)......last me f(0) return kr jaega
        dec(n-1);
    }
}

void inc(int n){
    if(n==0) return ;
    else{
        inc(n-1);//phele pura call stack fill hoga functions call se n=0 tk
        //fir wha se return hote time sab print hona suru hoga n=1,n=2......
        cout<<n<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    dec(n);
    cout<<endl;
    inc(n);
}