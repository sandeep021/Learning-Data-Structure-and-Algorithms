//good question must revise.

#include <iostream>
using namespace std;
bool issafe(int board[][10],int i ,int j, int n){
    //column check
    for(int row=0;row<i;row++)   {if (board[row][j]==1)   return false;}
    //left upper diag check
    int x=i;
    int y=j;
    while(x>=0 && y>=0){
        if (board[x][y]==1)  return false;
        x--;
        y--;
    }
//right upper daig check
      x=i;
      y=j;
    while(x>=0 && y<n){
        if (board[x][y]==1)  return false;
        x--;
        y++;
    } 
    return true;
}

bool solveNqueen(int board[][10],int i , int n){
     if (i==n){//last tak phuc gye to print kr do
         //print the board
         for (int r=0;r<n;r++){
             for (int c=0;c<n;c++) {
                 if (board[r][c]==1)   cout<<"Q ";
                 else
                    cout<<"_ ";
             }
             cout<<endl;
        }
        cout<<endl;
        //base case hit hine ke bad bhi
         return false;//yha false return kiya taki ho skta h aur trika ho rkne ka
         //to use bhi check kr liya j wala loop last tk le ja ke
     }

     //Recursive Case:
     //in recursion we assume ki n-1 problem khud se s0lve ho jaegi
     //1st hme krni hogi
     //1st problem hai ki first row me Q place ho jae.
     for(int j=0;j<n;j++){// first row ke sare spot ke liye looping
         if (issafe(board,i,j,n)){//ass pass chek krke rkhna safe hai ya nhi
             board[i][j]=1;
             bool nextSafePlace=solveNqueen(board,i+1,n);//aage rkhne  se false to nhi aa rha h
             //islye ye check kr rhe 
            if(nextSafePlace){//true aa rha to rkh diya first row me and true return kr diya
                return true;
             }
            board[i][j]=0;//agr aage se false aa rha to hta diya aur agle spot pe chale gye rkhne
            //backtracking
         }    
     }
     return false;//ksis bhi jgh nhi rkh paye row ke to false retun kr diya
}    
int main() {
    int n;
    cin>>n;
    int b[][10]={0};
    solveNqueen(b,0,n);
    return 0;
}

