//good one must revise it

#include <bits/stdc++.h>
using namespace std;
//print all the cobination of alphabets. intput are string of number.
//these numbers ara mapped with the alphabets as are in mobile kepad;
string arr[10]={"\0","\0","ABC\0","DEF\0","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void printFun(string in, char* out, int i, int j){
    if (in[i]=='\0'){
        out[i]='\0';
        cout<<out<<" ";
    }
    int digit=in[i]-'0';
    if(digit<0) return;
    for(int k=0;arr[digit][k]!='\0';k++){//pehle ke liye kiya
        out[j]=arr[digit][k];
        printFun(in,out,i+1,j+1);//baki ke liye recursuion
    }

}

int main(){
    string in="23";
    in+='\0';
    char out[1000];
    printFun(in,out,0,0);
}








/*
//good one must revise it

#include <bits/stdc++.h>
using namespace std;
//print all the cobination of alphabets. intput are string of number.
//these numbers ara mapped with the alphabets as are in mobile kepad;
char arr[][10]={"\0","\0","ABC\0","DEF\0","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void printFun(char* in, char* out, int i, int j){
    if (in[i]=='\0'){
        out[i]='\0';
        cout<<out<<" ";
    }
    int digit=in[i]-'0';
    cout<<digit<<"dw ";
    for(int k=0;arr[digit][k]!='\0';k++){//pehle ke liye kiya
        out[j]=arr[digit][k];
        printFun(in,out,i+1,j+1);//baki ke liye recursuion
    }

}

int main(){
    char in[]={'2','3','\0'};
    char out[1000];
    printFun(in,out,0,0);
}

*/