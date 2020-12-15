
#include<bits/stdc++.h>
using namespace std;
//mark all odd as prime
//now iterrate to all odd and if that odd is prime then mark all its multiple as non prime;
//remainiing marked ones are prime. 

//TC is O(n*log(logn));
int main(){
    int n;
    cin>>n;
    int arr[10000]={0};
    for(int i=2;i<10000;i++) {
        if(i%2==0) arr[i]=0;
        else arr[i]=1;
    };
    arr[1]=arr[0]=0;
    arr[2]=1;
    for(int i=3;i<10000;i+=2){
        if(arr[i]==1){
            for(int j=i*i;j<10000;j=j+i){
                arr[j]=0;
            }
        }
    }
    
    for(int i=0;i<=n;i++){
        if(arr[i]==1) cout<<i<<" ";
    }
}