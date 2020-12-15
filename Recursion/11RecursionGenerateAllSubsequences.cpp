//important must solve while revising

#include <bits/stdc++.h>
using namespace std;
//we have to find all the subsequences of a given string

//we will take an output array for temproray storage
//now have e cases if we want to break problem in two part (1,n-1);
//case1: we will take first part + call recusion on n-1 parts;
//case2: we will only call recursion on n-1 parts without adding first part
void subsequences(char *in , char *ou, int i, int j){
    if (in[i]=='\0') 
    {   ou[j]='\0';
        cout<<ou<<"  ";//we can use 2d array and store thses values to it
        return ;
    }
    //case 1
    ou[j]=in[i];//taking first part
    subsequences(in, ou,i+1,j+1);//recursion on rest part
    //case2 
    subsequences(in, ou,i+1,j);

}

int main(){
    char in[]={'a','a','b','\0'};
    char out[1000];
    subsequences(in, out,0,0);
}