#include<bits/stdc++.h>
using namespace std;
 void fun(string &s, int i){
 	if(i==s.length()-1 || i==s.length()) return;
 	if(s[i]=='p' && s[i+1]=='i') {
 		int j=i+2;
 		while(j<s.length()) j++;
 		s.push_back(' ');
 		s.push_back(' ');
 		while(j>=i+2) {
 			s[j+2]=s[j];
 			j--;
 		}
 		s[i]='3';
 		s[i+1]='.';
 		s[i+2]='1';
 		s[i+3]='4';
 		fun(s, i+4);
 	}
 	else fun(s, i+1);
 	
 }


int main(){
	string s;
	cin>>s;
	fun(s, 0);
	cout<<s;
	

}