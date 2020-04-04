#include <iostream>
#include <climits> //it will give largest and smallest value if int
using namespace std;
int main() {
    int smallest=INT_MIN;
    int largest=INT_MAX;
//arrays has homogeneous values at continous location.
	//decleration
	int a[10];
	// if you only declare an array without initialization of any element
	//it will have garbage value
	for (int i=0;i<10;i++){
		cout<<a[i]<<",";
	}
	cout<<endl;
	//but if u initalize any elemnt then other will automatically become 0.
	int b[10]={1,2,3};
	for (int i=0;i<10;i++){
		cout<<b[i]<<",";
	}
	cout<<endl;
	//inputing array
	int c[10];
	for (int j=0;j<10;j++){
		//cout<<"enter elements; ";
		cin>>c[j];
	}
	for (int k=0;k<10;k++){
		cout<<c[k]<<",";
        //if u r taking input and storing then other left wii store garbage
	}


//NOTE: normal searching time array ka O(n) hota hai
//par a[5] call krne pe O(1) time me mil jata hai how?
//ans: address of a[0] hota hai array me isko 5 times krke a[5] ka 
//addres mil jata hai fir uski value.
}

//1.Linear Search
//2.Binary Search (only for sorted arrays)
//3. BUbble Sort
//4. Selection Sort
//5. Insertion Sort
