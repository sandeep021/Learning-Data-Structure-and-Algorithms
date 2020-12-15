// //FOUR DEFAULT FUNCTION PRESENT WITH CLASS
// //THEY CAN BE OVERWRITTEN ACCORDING TO THE NEED


// //1.constrctor
// //--> constructor name == name of class
// //--> automatically called whenever object is called and called only once
// //--> automatic allocation
// //--> its a function with no returntype (if user defined constructor)

// //2.copy constructor 
// //-->shallow copy constructor (it is default)
// //-->deep copy constructor(dynamic memory allocation, different copies will be diffrent all changes will be independent in this case)


// //3.Destructor
// //-->clearout the memory of object , it gets called automaticaly when function is over.
// //--> for stactic variables default destructor will work
// //--for dynamic we have to delete explicitly
// //first deletes the latest creatted object then second latest the..........LIFO type order

////4. Assingment(=)
#include <iostream>
#include <cstring>
using namespace std;




class Car{
         int price;//private data
    public:
         int model_no;
         char* name;//pointer to char array.
         Car(){//constructor one
             name=NULL;
         }

         Car(int p, int m, char* n){//constructor two
             price=p;
             model_no=m;
             name= new char[strlen(n)+1];//dynamic memmory allocation of array, this is main logic for deep copy.
             strcpy(name, n);//copy array
         }

         void setPrice(int pn){//setter
             price=pn;
         }

         //start   of    Deep Copy Constructor
          Car(Car &X){
            cout<<"Deep Copy called for copy constructor"<<endl;
             price=X.price;
             model_no=X.model_no;
             name= new char(strlen(X.name)+1);//created new memory location.
             strcpy(name, X.name);//now copy the update to that.
         }
           //end 

        //start of deep assingment operator
        void operator=(Car &X){
            cout<<"Deep Copy called for assingment operator"<<endl;
             price=X.price;
             model_no=X.model_no;
             name= new char(strlen(X.name)+1);//created new memory location.
             strcpy(name, X.name);//now copy the update to that.
        }
         //end

         void print(){
             cout<<"price "<<price<<endl;
             cout<<"Model "<<model_no<<endl;
             cout<<"Name "<<name<<endl;
             cout<<endl;
         }
//start for destructor to delete dynamic memmory;
         ~Car(){
             if(!name){
                 delete [] name;
             }
             cout<<"to destroy dynamic allocated memory of object with name "<<name <<endl;
         }
//this is how default distructor work and is called automatically.
        //  ~Car(){
        //      cout<<"Inside distructor of car "<<name<<endl;
        //  }
};

int main(){
    //constructor 1.
    Car A;
    A.setPrice(300);
    A.model_no=2345;
    A.name="Dezire";
    A.print();

//Constructor two.
    Car C(100, 200, "Audi");
    C.print();
    Car D(C);//Copy constructor syntax , Car D=C is second way for copy constructor .
    D.setPrice(400);
    D.name[0]='B';
    D.print();

    Car E;//Initializae then assignment, so it is now Copy Assingment.
    E=C;
    E.name[0]='F';
    E.print();

    Car *e = new Car(10, 20, "ferari");//this is dynamic memory
    e->print();
    delete e;//for destroying object e;

}





/* DIFFERENCE BETWEEN ASSINGMENT AND COPY CONSTRUCTOR.
Copy constructor is called when a new object is created from an existing object,
 as a copy of the existing object. Cpoy Assignment operator (=) is called when an already 
 initialized object is assigned a new value from another existing object. 
 Copy Assingment is also a shallow copy.
 */





