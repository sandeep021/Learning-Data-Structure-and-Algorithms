#include <bits/stdc++.h>
using namespace std;
string arr[]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void print(int n){
    if (n<10) {
        cout<<arr[n]<<" ";
        return ;
    }  
    int x=n%10;//last wala nikal liya
    print(n/10);//remaining ko recursion
    cout<<arr[x]<<" ";//intial se print krana tha to 
    //function call sare call stack me store hen return ke time print
}

int main(){
    print(20108);
}