#include <bits/stdc++.h> 
using namespace std;
//in bubble sort we send the largestr element to last then second largest to secon last amd so on, we use swaping
void bubbleSort(int arr[], int n){
    if(n==1)  return ;
    for(int i=0;i<n-1;i++){//sending one (the largest) elemnt to the last
        if (arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
    }
    bubbleSort(arr,n-1);//now doing the same for all the n-1 elements recusively;
}
//in the above function we have a loop we should also convert this loop into recursive call but how?
//we know that the loop is used to make one iteration and put the element to its position
//to remove loop we have to take i as a parameter in function

void bubbleSortRec(int arr[], int n, int i){
    if(n==1)  return ; //base case 

    //for sorting one element
    if (i==n-1) return bubbleSortRec(arr,n-1,0);//in previous function when first loop completes, the value of i is n-1 
    //and last element is at its correct location we do sorting for rest other n-1 elements and agin i starts
    //form 0 and will iterate to element which is just before to the right placed eelement

    //RECURSIVE CASE
    if (arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
    bubbleSortRec(arr,n,i+1);// for sorting the other elements recursively.
    return;
}




int main(){
    int arr[]={3,2,4,1,0};
    int n=sizeof(arr)/sizeof(int);
    //bubbleSort(arr,n);
    bubbleSortRec(arr,n,0);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}