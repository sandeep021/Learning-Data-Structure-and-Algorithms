#include <bits/stdc++.h>
using namespace std;

bool canPlace(int mat[9][9], int i, int j, int n, int number){
    //row and column check
    for (int num=1;num<=n;num++){
        if (mat[num][j]==number || mat[i][num]==number) return false;
    }
    //grid check
    int rn=sqrt(n);
    int sx=(i/rn)*rn;
    int sy=(j/rn)*rn;
    for (int p=sx;p<sx+rn;p++){
        for(int q=sy;q<sy+rn;q++){
            if (mat[p][q]==number) return false;
        }
    }
    return true;

}

bool sudukoSolve(int mat[][9], int i, int j, int n){
    if(i==n){
        for(int p=0;p<n;p++){
            for(int q=0;q<n;q++)  cout<<mat[p][q];
        }
        return true;
    }
    if (j==n){
        return sudukoSolve(mat,i+1,0,n);
    }
    if (mat[i][j]!=0){
        sudukoSolve(mat,i,j+1,n);
    }
    for (int number=1;number<=n;number++){
        if (canPlace(mat,i,j,n,number)){
            //assume ki shi hai
            mat[i][j]=number;
            bool check =sudukoSolve(mat,i,j+1,n);
            if (check) return true;
           
        }
    }
     mat[i][j]=0;
    return false;

}

int main(){
    int mat[9][9]=
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {6,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}



    };
    sudukoSolve(mat,0,0,9);
    return 0;
}