// recursive function for checking that array is sorted or not


#include <iostream>
using namespace std;

bool check_array(int a[],int n){
    if (n==1)            //Base Case
        return true;
    else
    {
        if (a[0]<a[1] && check_array(a+1,n-1))   //Recursive call
              return true;
        else
              return false;

    }  
        
}
int main(){
    int n;
    cin>>n;
    int a[n+1];
    for (int i=0;i<n;i++)
        cin>>a[i];
    cout<<check_array(a,n);
}