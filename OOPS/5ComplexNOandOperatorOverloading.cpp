#include<bits/stdc++.h>
using namespace std;

class ComplexNumber{
         int real;
         int imaginary;
     public:
         ComplexNumber(){
             real=0;
             imaginary=0;
         } 

         ComplexNumber(int r, int i){
             real=r;
             imaginary=i;
         }

         void setReal(int r){
             real=r;
         }
         void setImaginary(int i){
             imaginary=i;
         }

         int getReal() const{
             return real;
         }
         int getImaginary() const{
             return imaginary;
         }

         void print(){
             if(imaginary>0)
                    cout<<real<<" + "<<imaginary<<"i"<<endl;
             else 
                    cout<<real<<" - "<<imaginary<<"i"<<endl;
            cout<<endl;
         }
        ///ADDing start
        void add(const ComplexNumber &x){//adding c2 to c1-------c2 will be same and c1 will be changed
            real+=x.real;
            imaginary+=x.imaginary;
        }

        void operator+(const ComplexNumber &x){//adding using operator overloading
            real+=x.real;
            imaginary+=x.imaginary;
        }
        /////ADDING end;

         //////negation start.  overloading.
        void operator!(){
            imaginary *= -1;
        }
       //end of negation

       int operator[](string s){
           if(s=="real") return real;
           return imaginary;
       }
};

///overloading two objects of a class with operator.     bit advance topic.
//this will eork only for cin>>d;
// void operator>>(istream &is, ComplexNumber& x){//here "cin" can have any name because it is just an obect of istream class.
//     int r1, i1;
//     is>>r1>>i1;
//     x.setReal(r1);
//     x.setImaginary(i1);
// }

//this will work for cin>>d>>e>>f
//same can be done with add(+) operator by change the return type
istream& operator>>(istream &is, ComplexNumber& x){//here "cin" can have any name because it is just an obect of istream class.
    int r1, i1;//function return type is refrence based(&) because we dont want to make copy of istream class because it is big inbuilt class.
    is>>r1>>i1;
    x.setReal(r1);
    x.setImaginary(i1);
    return is;
}

void operator<<(ostream &os, ComplexNumber& x){
    x.print();
}
//end here

int main(){
    ComplexNumber C1(2,3);
    C1.print();
    ComplexNumber C2(3,2);
    C1 + C2;
    C1.print();
    !C2;
    C2.print();
    cout<<C2["real"]<<endl;
    ComplexNumber d;
    ComplexNumber e;
    cin>>d>>e;
    cout<<d;
    cout<<e;

}