//dynamic_memory using new and one

#include <iostream>
using namespace std;
int main() {
    int  *p= new int(30);// small brackets used to give initalized value to a variable
    cout<<*p<<endl;
    int *q= new int;// if dont want to initialize 
    cout<<*q<<endl;
    int *arr=new int[30];//square brackets for array memmory allocatin and its size 
    //here size of array is 30.
    for (int i=0;i<30;i++){
        arr[i]=2+i;
    }
    for (int i=0;i<30;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete p;
    delete q;
    delete []arr;
    //2-D ARRAY 


    int ** a=new int *[4];//primary array created
    for (int i=0;i<4;i++){
        a[i]=new int[6];//secondary array created
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<6;j++){
            a[i][j]=i*j;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<6;j++){
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }
  for (int i=0;i<4;i++){
      delete [] a[i];// first delete secondary arrays
  }
  delete []a; //then secondary arrays
  cout<<"success";
}
