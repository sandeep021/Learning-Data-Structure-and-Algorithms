//implementation of lowerbound with comparator 
//greedy approach only for indian currency


//find the change of monwy in given denomination of coins for a money
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
    return a<=b;
}

int main(){
    int coins[]={1,2,5,10,20,50,100,200,500,2000};
    int n=sizeof(coins)/sizeof(int);
    int money=168;
    while(money>0){
        int lb=lower_bound(coins,coins+n,money,compare)-coins-1;
        money=money-coins[lb];
        //making our problem smaller with greedy choice
        cout<<coins[lb]<<" ";

    }

}