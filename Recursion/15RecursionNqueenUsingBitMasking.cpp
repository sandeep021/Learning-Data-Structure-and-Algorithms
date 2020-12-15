#include <iostream>
#include <bitset>
using namespace std;
bitset<30> col,d1,d2;

void nqueen(int r, int n, int &ans){
    if(r==n){
        ans++;
        return;
    }
    for(int c=0;c<n;c++){
        if(!col[c] && !d1[r-c+n-1] && !d2[r+c]){
            col[c]=d1[r-c+n-1]=d2[r+c]=1;
            nqueen(r+1,n,ans);
             col[c]=d1[r-c+n-1]=d2[r+c]=0;
        }
    }
}

int main(){
    int ans=0;
    int n;
    cin>>n;
    nqueen(0,n,ans);
    cout<<ans;
    return 0;
}