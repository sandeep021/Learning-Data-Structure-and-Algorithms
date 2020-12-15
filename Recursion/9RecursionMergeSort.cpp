#include <bits/stdc++.h>
using namespace std;
//in this steps are
//1. break the array
//2. sort the first part recursively
//3. sort the second part recursively
//4. merge the both part recusively



void merge(int *a, int s, int e){
    int mid=(s+e)/2;
    int i=s;//index to start of first part
    int j=mid+1;//index to start of second part
    int k=s;//index at new temp array where we will store the temporary values
    int temp[10000];
    while(i<=mid && j<=e){
        if(a[i]<a[j]) temp[k++]=a[i++];
        else temp[k++]=a[j++];
    }
    while(i<=mid){//if secoond part is exausted
        temp[k++]=a[i++];
    }
    while(j<=e){
        temp[k++]=a[j++];//if first part is exausted
    }
    for(int i=0;i<=e;i++) a[i]=temp[i];//copyting back the value to a    
}

void mergeSort(int arr[], int s, int e){
    if (s>=e) return ;
    int mid=(s+e)/2;//for breaking array
    mergeSort(arr,s,mid);//sorting first part
    mergeSort(arr,mid+1,e);//sorting second part
    merge(arr,s,e);//merging

}

int main(){
    int arr[]={3,2,4,2,-1,0};
    mergeSort(arr,0,5);
    for(int i=0;i<6;i++) cout<<arr[i]<<" ";
}