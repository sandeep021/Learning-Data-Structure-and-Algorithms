//given a 2d matrix of char in which some cell are block find way to reach fromm 0,0 to m,n
//with condition that rat cam move right or down
#include <bits/stdc++.h>
using namespace std;
int cnt=0;
int ratMaze(char maze[][10], int solu[][10], int i, int j, int m, int n){
    if (i==m-1 && j==n-1){
        solu[m-1][n-1]=1;
        //print sol 
        cnt++;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                 cout<<solu[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        return cnt;
    }
    if (i>=m || j>=n) return 0;
    if (maze[i][j]=='X') return 0;
    solu[i][j]=1;
    int right = ratMaze(maze, solu, i,j+1,m,n);
    int down= ratMaze(maze,solu,i+1,j,m,m);
    solu[i][j]=0;
    if (right || down) return cnt;
    return 0;
}

int main(){

    char maze[10][10]={"0XXX",
                     "0XXX",
                     "000X",
                     "0000"};
    int solu[10][10]={0};

    cout<<ratMaze(maze,solu,0,0,4,4);
}