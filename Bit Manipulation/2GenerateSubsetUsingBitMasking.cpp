#include<bits/stdc++.h>
using namespace std;

void filterChars(int n, char a[]){//making bit filters for priint;
    
    int j=0;
    while(n>0){
        int lastbit=(n&1); //101
        if((lastbit==1)) cout<<a[j];
        j++;
        n=n>>1;
    }
    cout<<endl;
    
}

void printSubsets(char a[]){
    int n=strlen(a);
    ///cout<<n<<endl;
    for(int i=0;i<(1<<n);i++){//inpuuting all the bit combinations for filter
        filterChars(i,a);
    }
}

int main(){
    char a[]="abc";
    printSubsets(a);
}