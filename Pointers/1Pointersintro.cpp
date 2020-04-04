//1. & is used to get adddress of variable.
//2. & doesnt give address of char, to get address we have to do 
//explicit type casting fron char* to void*.

#include <iostream>
using namespace std;
int main() {
    int x=10;
    int *xptr=&x;
    cout<<&x<<"======="<<xptr<<endl;
    //3. pointer is a variable which contain address of another variable
    float y=12.5;
    float *yptr;
    yptr=&y;
    cout<<&y<<"======"<<yptr<<endl;
    //4. similarly we have pointer for other data types like double and long
    char a='a';
    char *aptr=&a;
    cout<<aptr<<endl;
    //5.its not because of char buts its due to cout with character we will learn it later
    cout<< (void *) aptr<<endl;  //type conversion is one way to get the address
    //6. never use pointer of other data type to store address of other data type--> 
    //try to remember the reason if not watch video(cpp-pointers)
    //a. we will have problem in reading from memory map(starting addres* no of bits of data type).
    //b. if so we will be unable to do pointer arithmatics
    //7. you can reasign the pointer

    //8. SIZE OF POINTER IS ALWAYS 4 BYTE OR 8 BYTE DEPENDING ON SYSTEM-->TRY TO REMBER THE REASON IF CANT WATCH THE VIDEO(CPP-POINTER)
    //POINTER ALWAYS STORE THE STARTING ADDRES WHUCH IS A 4 BYTE HEXADECIMAL NUMBER thats why its size is same
    //for all.
    //example: 1-2-3-4 byte for int it will store address of 1 and 1 byte for char
    //here it will also store address of both have same size.
    //9. SIZE OF CHAR=1BYTE
    //10. SIZE OF INT=4BYTE

    //11. A c pointer knows the types of pointers and indirectly referenced
    //data items at runtime

    
}
