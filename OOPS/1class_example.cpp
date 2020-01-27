#include <iostream>
using namespace std;

class Car{
    public://by default it is private
          int price;
          int model_no;
          char name[20];
          void start(){
              cout<<"Grrrrrrrrrrrrrr............"<<endl;
          }

};

int main(){
    Car A;//object of class
    cout<<sizeof(Car)<<endl;//class itself have no space
    cout<<sizeof(A)<<endl;
    Car b[100]; //array of class


    Car C;
    C.price=500;
    C.model_no=2;
    C.name[0] ='B';//way to initialize contents
    C.name[1]='M';
    C.name[2]='\0';
    cout<<C.price<<endl;
    C.start(); //way to acces function


}