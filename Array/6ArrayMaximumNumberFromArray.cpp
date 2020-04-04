///ou are provided an array of numbers. 
//You need to arrange them in a way that yields the largest value.


#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int comapare(int a,int b){
    stringstream ss1;
    ss1 << a;
    string str1 = ss1.str();//let it be X
    stringstream ss2;
    ss2 << b;
    string str2 = ss2.str();//let it be Y
    string s12=str1.append(str2);//so it is XY
    string s21=str2.append(str1);//and it is YX
    return s12.compare(s21) > 0 ? 1: 0; //returning maxof(XY, YX) basis of ssorting
    //this will form the largest number
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        vector<int> a;
        cin>>n;
        for (int i=0;i<n;i++){
             cin>>m;
             a.push_back(m);}
        sort(a.begin(),a.end(),comapare);
        for(int j=0;j<n;j++)
             cout<<a[j];
        cout<<endl;    
    }
	return 0;
}