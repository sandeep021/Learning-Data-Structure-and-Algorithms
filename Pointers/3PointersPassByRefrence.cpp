#include <iostream>
using namespace std;
//pass by value
void increment(int a){
    a=a+1;
    cout<<"Inside Function Pass by value  "<<a<<endl;
}
//here local variable a is created and updated

//pass by refrence
void incrementRefrencce(int *a){
    *a=*a+1;
    cout<<"Inside Function Pass by refrence "<<*a<<endl;
}
//since we are giving addres of a variable
//all change done will be at same location so ans will be updated at same
//location

int main(){
   int a=10;
   int b=100;
   increment(a);//here another variable a created at some other location
   // which will not be updated by above function
   cout<<"Outside Function pass By value "<<a<<endl;
   incrementRefrencce(&b);
   cout<<"Outside Function pass By refrence "<<b<<endl;
}