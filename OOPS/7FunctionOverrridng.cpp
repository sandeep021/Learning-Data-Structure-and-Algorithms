#include<bits/stdc++.h>
using namespace std;



//function overidding and function overloading are different things.

class Animal{
    public:
        void makeSound(){
            cout<<"Animal Sound"<<endl;
        }
};

class Dog: public Animal{
    public:
        void makeSound(){
            cout<<"Dogs Bark"<<endl;;
        }
};

class Cat : public Animal{
    public:
       void makeSound(){
           cout<<"Cats Meow"<<endl;
       }
};


int main(){
    Animal a1;
    a1.makeSound();
    Dog d1;
    d1.makeSound();
    Cat c1;
    c1.makeSound();

}
