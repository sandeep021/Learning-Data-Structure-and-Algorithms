#include<bits/stdc++.h>
using namespace std;

void multiply(vector<int> &v, int &n, int no){
    int carry=0;
    for(int i=0;i<n;i++){
        int product=v[i]*no + carry;//hr column ko multiply and then update
        v[i]=product%10;
        carry=product/10;
    }
    while(carry>0){
        v[n]=carry%10;//remaining caary 1 se jada digit ki ho skti h
        carry=carry/10;
        n++;
    }
}


void factorial(int number){
    vector<int> v(1000,0);
    int n=1;
    v[0]=1;
    for(int i=1;i<=number;i++){
        multiply(v, n, i);//main function to multiply using array 
    }
    cout<<n<<endl;
    for(int i=n-1;i>=0;i--) cout<<v[i];
}

int main(){
    int n;
    cin>>n;
    factorial(n);
}


//6---1*2*3*4*5*6
//vector= 1
        //   2
        //   6
        //   24   42
        //   2*5 , 4*5+carry, carry

        //   120  021
        //   720  027