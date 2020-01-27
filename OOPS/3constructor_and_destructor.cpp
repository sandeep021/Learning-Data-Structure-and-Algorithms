//FOUR DEFAULT FUNCTION PRESENT WITH CLASS
//THEY CAN BE OVERWRITTEN ACCORDING TO THE NEED


//1.constrctor
//--> constructor name== name of class
//--> automatically called whenever object is called
//--> automatic allocation
//--> its a function with no returntype (if user defined constructor)

//2.copy constructor (already exist but has some problem)
//--> makes a copy, both the copies will be diffrent all changes will be independent
//-->shallow copy constructor (it is default) and
//-->deep copy constructor(dynamic memory allocation, different copies will be diffrent all changes will be independent in this case)

//3.copy assignment operator (deep and shallow) default is shallow type
//D=E can be called mane times

//4.Destructor
//--> for stactic variables default destructor will work
//--for dynamic we have to delete explicitly

#include <iostream>
#include <cstring>
using namespace std;

class Car{
    public://by default it is private
          int price;
          int model_no;
          char name[20];
          const int tyres;
          void start() const{
              cout<<"Grrrrrrrrrrrrrr............"<<endl;
          }

         Car():name("uiuj"), tyres(4){             //constructor one, initialization list is used here it is optional
         // to make constant variable it is compulsory to use it because normal assignment cant be used
              cout<<"This constructor is ovverriding the default one"<<endl;
          }
        Car(int p, int mn, char *na):tyres(4),price(p),model_no(mn){   //constructor second
              strcpy(name,na);
          }

          void print(){
              cout<<price<<endl;
              cout<<model_no<<endl;
              cout<<name<<endl;
              cout<<endl;
          }
          Car(Car &x):tyres(4){  //NAME WALE SECTION LE LYE BECAUSE COPY COPY ME SYCLE BN RHI THI
              price=x.price;
              model_no=x.model_no;
              strcpy(name, x.name);//shallow copy constructor
              cout<<"user defined constructor"<<endl;
          }

          ~Car(){
              cout<<"Destructor"<<endl;
              
              
          }

};
int main(){
    Car a;//first constructor is called, which has no input arguments
    
    Car b(100,1,"Ferrari"); //here second is called
    b.print();

    Car c(b); // copy constructor function inbuilt wala 
    c.name[0]='G';  
    Car d= a; //same as above statement another way, works only when we are creating a new object that is it can be callled once
    c.print();

    Car *DC = new Car(100,201,"Dynamic Car");//dynamic object destructor will destroy it itself
    //delete DC;
    return 0;
}


//constant variables
//initialization list
//constant function---> if a fun is not making any updation to data member u can make it constant
//constant parameter