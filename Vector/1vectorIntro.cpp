//VECTOR
#include <iostream>
#include <vector>
//memory gets double in size if it get fulled
//always use reserved memory, initially it is efficient -->think--<
#include <algorithm>
using namespace std;
int main() {
   vector<int> v;
   int n,temp;
   cin>>n;
   for (int i=0;i<n;i++){
       cin>>temp;
       v.push_back(temp);//push at the end
       // do not use v[i] because if ith space is not present it will cause error
   }
v.pop_back();//pop from the last
cout<<"Printing the vector after one pop: ";
for (int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
}cout<<endl;
//v.clear() it will delete all the element
//cout<<v.capacity<<"capicity"<<endl//.capacity gives maximum (elemeents) size of vector
//v.reserve() Requests that the vector capacity be at least enough to contain n elements
//use to improve time complexity.
//v.max_size() //gives maximum size of a vector depending on system
//v.sort(v.begin(),v.end(),comparator_optional)
vector<int> vect(10,2);
cout<<"Example of creating a vector of size 10: ";
for (int i=0;i<vect.size();i++){
    cout<<vect[i]<<" ";}
  cout<<endl;
  cout<<v.back()<<endl;//return last value without poping
  cout<<v.front()<<endl;
//empty() tests whether vector is empty or not. Vector of size zero is
//considered as empty vector. It returns true if vector is empty
///otherwise false.
//v.insert(at location(i.e v.begin()+3),value to insert(i.e 100)) extends vector by inserting new element at position in container.
//vect.front() returns a reference to the first element of the vector.
//vect.at(0); //prints element at index 0 which is 1
//vect.back(); //prints the last element which is 4
//v1.swap(v2);  swap() exchanges the content of one vector v1 with contents of
//other vector v2 of same  type but size may differ, it works in O(1) time.
//resize(n) – Resizes the container so that it contains ‘n’ elements.
//vector<int> v(50) method to define a vector


/* METHOD OF CREATING VECTORS
vector <int> vn{1,2,3,4,5};
vector<int> vn1(vn); //copy element of vn in vn1
vector<int> vn2(vn1.begin(),vn1.end()); copy all element of vn1 in vn2
*/

//v.erase(v.begin()+2)  //delete particular value
//v.erase(v.begin()+1,v.begin()+4) //delete range of values

}



//More THings 
//1. Making Vector
//2. Templating Vector class


//vector<int> V[] is an array of vectors.

//vector< vector<int> > V is a vector of vectors.