#include <iostream>
using namespace std;

class Car{
    private:
           int price;  //private data
    public://by default it is private
          int model_no;
          char name[20];

          void start(){
              cout<<"Grrrrrrrrrrrrrr............"<<endl;
          }

          setprice(int p){   //public function
              price =p;
          }
          getprice(){
              return price;
          }


};
int main(){
    Car c;
    c.setprice(1000);//outside function updation of private data
    cout<<c.getprice()<<endl;//you will get error if you try to update if directly.
return 0;

}

//GETTER AND SETTER CAN BE USED TO UPDATE AND RETURN THE PRIVATE DATA FROM OUTSIDE THE CLASS
//THESE FUNCTIONS CAN ALSO IMPOSE CONDITION WHILE UPDATING