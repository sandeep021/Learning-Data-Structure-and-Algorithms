#include <bits/stdc++.h>
using namespace std;
//steps
//1. make a pivote element find its correct index and return the index
//make partiotion from that index
//3. sort both the partitioned elements.


int partition(int *arr,int s, int e){//e=index of last element;
    int pivote=arr[e];
    int i=s-1;//i is region of elemts less than pivote
    int j=s;
    while(j<e){
        if (arr[j]<pivote){//if you find a smaller one
            i++;//increse the region
            swap(arr[i],arr[j]);//and put it in that region
        }
        j++;
    }
    i++;//finally put pivote at its correct index
    swap(arr[i],arr[e]);
    return i;
    
    }

    void quickSort(int arr[], int s, int e){
        if (s>=e) return;//base case
        int q;
        q=partition(arr,s,e);
        quickSort(arr,e,q-1);
        quickSort(arr,q+1,e);
    }


    int main(){
    int arr[]={3,2,4,2,-1,0};
    quickSort(arr,0,5);
    for(int i=0;i<6;i++) cout<<arr[i]<<" ";
}
