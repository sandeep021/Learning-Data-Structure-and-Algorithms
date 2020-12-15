//Q from gven array of no which contain 2 unique number and rest no are twice present find those unique number
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n+1,0);
    int xor1=0;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        xor1=xor1^v[i];
    }
    int temp=xor1;
    int pos=0;
    while((temp&1)==0){//finding position of first set bit
        pos++;
        temp=temp>>1;
    }
    cout<<pos<<endl;
    int mask=1<<pos;
    int a=0;
    for(int i=0;i<n;i++){
        if((v[i]&mask)>0) a^=v[i];//taking xor with all the no whose pos bit is 1
        //it is giving one unique no because while taking this set bit muust be present in one of the unique no
        //other will be zero
        //so swe will fiind one of the unique number
    }
    cout<<a<<endl;
    int b=0;
    b=xor1^a;
    cout<<b<<endl;


}
//input
//8
//2 2 4 4 3 7 5 5
 //output
 //7
//3

//a=    0111;
//b=    0011;
//xor1= 0100
//pos=2
//it means one of the unique no has set bit at 2
//using this we will find that number by taking xor from all the no of array which have set bit at 2 postion.
//other unique no will not come in it because it doesnot have set bit 2.

//b=7^3^7(a)=3 


/*
//fast implementation.

int Solution::singleNumber(const vector<int> &A) {
    int ans=0;
    for(int i=0;i<32;i++){//visiting each index of every number and adding then checkig 
        int sum=0;
        for(int j=0;j<A.size();j++){
            sum+=(A[j]>>i)&1;
        }
        sum=sum%3;
        ans+=sum*pow(2, i);
    }
    return ans;
}

*/