
//implementation
//constant variables
//initialization list
#include <iostream>
#include <cstring>
using namespace std;
class Car{
         int price;
    public:
         const int msp;//constant data member, cant be directly initialize
         int model_no;
         char* name;
         Car(): msp(99){//method of initializing constant data member.
             name=NULL;
         }
         Car(int p, int m, char* n, int minPrice=99):msp(minPrice){//taking input for initializing const data member.
         //know as initialization list
             price=p;
             model_no=m;
             name= new char[strlen(n)+1];
             strcpy(name, n);
         }
         void setPrice(int pn){
             price=pn;
         } 

         void print(){
             cout<<"price "<<price<<endl;
             cout<<"Model "<<model_no<<endl;
             cout<<"Name "<<name<<endl;
             cout<<endl;
         }

};

int main(){
    //constructor 1.
    Car A;
    A.setPrice(300);
    A.model_no=2345;
    A.name="Dezire";
    A.print();
    cout<<A.msp<<endl;

//Constructor two.
    Car C(100, 200, "Audi", 1000);
    C.print();
    cout<<C.msp<<endl;
}

//contant parameter : functon's data member which dont get updated
//constant function: class function which do not update any of its datamember
//it is used for easy debugging.

//void setPrice(const int pn){//it is const parameter example & it is not const function brcause value of "price is updated".
//              price=pn;
//          }



//void print() const{//it is const function syntax
//              cout<<"price "<<price<<endl;
//              cout<<"Model "<<model_no<<endl;
//              cout<<"Name "<<name<<endl;
//              cout<<endl;
//          }


