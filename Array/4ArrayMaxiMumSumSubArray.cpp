//You are provided n numbers (both +ve and -ve). Numbers are arranged in a circular form.
 //You need to find the maximum sum of consecutive numbers(subarrays).

 #include <iostream>
using namespace std;

   int kaden(int a[1000],int n){
      int currentsum=0;
      int maxsum=0;
       for (int i=0;i<n;i++){
           currentsum=currentsum+a[i];
           if (currentsum<0){
               currentsum=0;
           }
           maxsum=max(currentsum,maxsum);

    
   }
   return maxsum;
}
int main(){
    int a[1000];
    int b[1000];
    int n,t;
    cin>>t;
    while (t--){
    cin>>n;
    int sum=0;
    for (int i=0;i<n;i++)
    {   
        cin>>a[i];
        b[i]=-a[i];
        sum+=a[i];
    }
    int c1=kaden(a,n);
    int c2=kaden(b,n)+sum;
    cout<<max(c1,c2)<<endl;
    }
}