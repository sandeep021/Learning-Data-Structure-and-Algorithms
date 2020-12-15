// number less than n which are divisible by all prime numbers less than 20;
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=0;
    int prime[]={2,3,5,7,11,13,17,19};
    int subsets=1<<8-1;//same as 2^8-1;  generating all the subsets 
    for(int i=1;i<=subsets;i++){
        int denom=1;
        int setbits=__builtin_popcount(i);
        for(int j=0;j<8;j++){
            if(i&(1<<j)) {//checking if jth bit is 1 or zero using mask(i<<j)
            //eg 10001001 then denom will be prime[0]*prime[4]*prime[7].
                denom=denom*prime[j];//if bit is one then it will contribute in denominator.
            }
        }
        if(setbits&1) ans+=n/denom;//if no of bits are odd then a^b^c^d^e--------it should be added to ans
        else ans-=n/denom;//exclusion inclusion principle.
            
    }
    cout<<ans<<endl;

    }

    /*
    intput 18
    output 17*/
