#include<bits/stdc++.h>

using namespace std;

void printSolution(int ** solution,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solution[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void mazeHelper(int maze[][20],int n, int ** solution, int x, int y){
    if(x==n-1 && y==n-1){
        solution[x][y]=1;
        printSolution(solution,n);
        solution[x][y]=0;
    }
    if(x<0 || x>=n || y<0 || y>=n || maze[x][y]==0 || solution[x][y]==1){
        return;
    }
    solution[x][y]=1;
    mazeHelper(maze,n,solution,x-1,y);
    mazeHelper(maze,n,solution,x+1,y);
    mazeHelper(maze,n,solution,x,y-1);
    mazeHelper(maze,n,solution,x,y+1);
    solution[x][y]=0;
    
}


void ratInMaze(int maze[][20],int n){
    int ** solution = new int*[n];
    for(int i=0;i<n;i++){
        solution[i] = new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            solution[i][j]=0;
        }
    }
    mazeHelper(maze,n,solution,0,0);
}

int main(void){
    int n;
    cin>>n;
    int maze[n][20];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }
    ratInMaze(maze,n);
    return 0;
}