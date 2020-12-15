// recursive function to calculate a power b
//time= O(lonb)

#include <iostream>
using namespace std;

int fastpower(int a, int b){
    if (b==0)
        return 1;
    else{
        if (b%2==0)
            return fastpower(a,b/2)*fastpower(a,b/2);
        else
            return a*fastpower(a,b/2)*fastpower(a,b/2);
    }
    
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<fastpower(a,b);
}
