#include <iostream>
using namespace std;
int main() {
   //&bucket=address//& means address of..
   //*address=bucket//* means value at..
   //* is derefrencing operator
   int x=10;
   int *xptr=&x;
   cout<<&x<<endl;
   cout<<xptr<<endl;
   cout<<*(&x)<<endl;
   cout<<*(xptr)<<endl;
   //pointer arithmetics
   cout<<*(xptr)+1<<"operation"<<endl;//value at the addres +1;
   cout<<*(xptr+1)<< "operation1"<<endl;//it will give value of next int bucket
   //i.e if addresss at xptr is 2054 the address at xptr+1 will be 2058(because
   //x is int). 
   cout<<*(&xptr)<<endl;
   cout<<&(*xptr)<<endl;
   //try to find output of above codes
   cout<<*(&x+1)<<endl;// gives garbage value
   cout<<*(xptr)+1<<endl;
   //double pointer is a pointer variable used to store addres of a pointer
   float y=11.9;
   float *yptr=&y;
   float **yyptr=&yptr;
   cout<<yptr<<endl;
   cout<<yyptr<<endl;
   cout<<*yyptr<<endl;
   //never derefrence a not assingned pointer it will give run-time error or garbage value
   //it is also call segement fault.
   //a[]={1,2,3,4}
   //sizeof(a) in main() it gives 16 bytes
   //in function it gives 4 byte 
   //in function array is passed as refrence(addres of first dabba which will be 4 byte).
   //refrence variable
   //x=10;
   //int &y=x;
   //both x and y are same here change to one will change the other
   //y is refrence variable ..it must be initialized else it will give compilation error.
   //A reference can never be null.
   //A reference once established cannot be changed.
    int a=9;
    int &b=a;
    //int &c; try this 
    cout<<a<<" a"<<endl;
    cout<<b<<" b"<<endl; // Reference doesn't need an explicit dereferencing mechanism.
}
