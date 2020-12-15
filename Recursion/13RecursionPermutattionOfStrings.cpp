//good one must revise

#include <bits/stdc++.h>
using namespace std;
//find all the prmutations of a given string
 void permutation(char* in, char* out, int i, int j){
     if (in[i]=='\0'){
         out[j]='\0';
         cout<<out<<" ";
         return;
     }
     for(int k=i;k<in[k]!='\0';k++){
     out[j]=in[k];
     swap(in[i],in[k]);//eg . acb ho gya h array
     permutation(in,out,i+1,j+1);
     swap(in[i],in[k]);//Backtracking step. eg. waps se abc ke denge wrna glt caculate hoga ---------ek bar is line co comment kr ke dekh lo.
     //neeche jate time jo chenge kiya tha wo wps ate time bdla hua hoga aur next branch uske hisab se calculate hogi
     //isliye upr aate time usko waps se shi kr denge 
     }
     
 }

 int main(){
     char in[]={'a','b','c','d','e','\0'};
     char out[1000];
     permutation(in, out, 0, 0);
 }

 //Note General :  recursion me function ke upr wala call neeche jane ke liye hota h
 //function ke bad wala upr jane ke liye hota hai.