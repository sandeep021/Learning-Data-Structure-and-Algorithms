//You are provided n numbers of array. 
//You need to find the maximum length of bitonic subarray.
// A subarray A[i … j] is biotonic if there is a k with i <= k <= j
// such that A[i] <= A[i + 1] … <= A[k] >= A[k + 1] >= .. A[j – 1] > = A[j]
// i.e subarray is first increasing and then decreasing
// or entirely increasing or decreasing.


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            arr[i]=a;
        }
        int inc[n+1]={0};//to store increaing length
        int dec[n+1]={0};//to store decreasing length
        //output will be incresing + decresing lentgh both
        inc[0]=1;
        dec[n-1]=1;
        for(int i=1;i<n;i++) {
            if (arr[i]>=arr[i-1]) inc[i]=inc[i-1]+1;
            else inc[i]=1;
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=arr[i+1]) dec[i]=dec[i+1]+1;
            else dec[i]=1;
        }
        int maxi=inc[0]+dec[0]-1;//adding inc and dec values
        //minus 1 to remove repetetion
        for(int i=0;i<n;i++) maxi=max(maxi,inc[i]+dec[i]-1);
        cout<<maxi<<endl;
         
    }
}