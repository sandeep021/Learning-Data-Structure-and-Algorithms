#include <iostream>
using namespace std;

class Car{
          int secret_no;//private data cant be directly acceced but can be acceced using a public
    public://by default it is private
          int price;
          int model_no;
          char name[20];
          void start(int a){
              cout<<"Grrrrrrrrrrrrrr............"<<a<<endl;
              secret_no=120;
              cout<<secret_no<<endl;

          }

};

int main(){
    Car A;//object of class
    cout<<sizeof(Car)<<endl;//class itself have no memory occupation(actually), output is 28 cause it is sayng it will ocupy when its object 
    //will be created 
    cout<<sizeof(A)<<endl;
    Car b[100]; //array of class


    Car C;
    C.price=500;//way to update.
    C.model_no=2;
    C.name[0] ='B';//way to initialize contents
    C.name[1]='M';
    C.name[2]='\0';
    cout<<C.price<<endl;
    C.start(12); //way to acces function
    Car * x= new Car;//car cobect stored in heap(dynamic memort)
    x->price=500;
    x->start(2);
    delete x;//deleting dynamic memory 
}