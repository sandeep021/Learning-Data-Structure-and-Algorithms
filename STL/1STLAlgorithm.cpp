#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int arr[]= {1,10,11,9,100};
    int n=sizeof(arr)/sizeof(int);
    int key=40;
    //cin>>key;
//1.search ----> find;
auto it =find(arr,arr+n,key);//it returns addres of the box of key
int index=it-arr;// box addres- starting addres to get index
if(index==n)  cout<<key<<" not in array"<<endl;//if key is not present it will
//return value equal to n
else cout<<"Present at index "<<index<<endl;


//2. Binary Search----->

int arr1[]={10,20,30,40,40,40,50,60,70,80};
int n1=sizeof(arr1)/sizeof(int);
bool x = binary_search(arr1,arr1+n1,key);
if (x) cout<<"element present"<<endl;
else cout<<"Element absent"<<endl;

//two more things in binary search


int* lb=lower_bound(arr1,arr1+n1, key);//returns address of box which value
//is >= key value
cout<<lb-arr1<<" lower bound of "<<key<<endl;
auto ub=upper_bound(arr1,arr1+n1, key);//returns address of box which value
//is > key value(strictly greater);
cout<<ub-arr1<<" upper bound of " <<key<<endl;
//using lb and ub you can calculate the frequency of a number in (Ologn)
cout<<ub-lb<<" is the frequency of "<<key<<endl;
//Note: compare function can be used in lb and ub too

//3. sort(arr,arr+n, comparator); and how to pass a comparator function inside
//function(implementattion)

//4. Next Permutation and Rotate ----->

//works similarly for arrays and vectors;

int arr2[]={10,20,30,40,50,60};
int n2=sizeof(arr2)/sizeof(int);
rotate(arr2,arr2+3,arr2+n2);//return rotated array from mid
for (int i=0;i<n2;i++)  cout<<arr2[i]<<" ";
cout<<endl;
//next permutation return just bigger no than the given in array
//eg array = 1,2,3 then next permute is 1,3,2........
vector <int> v{1,2,3};
next_permutation(v.begin(),v.end());
for(int x:v) cout<<x<<" ";
next_permutation(v.begin(),v.end());
cout<<endl;
for(int x:v) cout<<x<<" ";
cout<<endl;


//5. reverse(arr,arr+length till we want to reverse) 

//Pair

pair<int, char> p;//method 1 to create pair
p.first=10;
p.second='A';
cout<<p.first<<endl;
cout<<p.second<<endl;
 pair<int, char> p1(p);//p1 will be same as p

 pair<pair<int, int>,string> p2;
 p2.first.first=10;
 p2.first.second=20;
 p2.second="Audi";
cout<< p2.first.first<<" "<< p2.first.second<<" "<<p2.second<<endl;

pair<int,int> = make_pair(10,11);//method





}