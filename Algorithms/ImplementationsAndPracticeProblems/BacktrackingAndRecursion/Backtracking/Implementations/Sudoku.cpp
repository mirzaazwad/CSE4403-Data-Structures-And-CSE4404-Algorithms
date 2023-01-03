#include<bits/stdc++.h>
using namespace std;
#define N 9

bool findEmptyLocation(int grid[N][N],int& x,int& y){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j]==0){
                x=i;
                y=j;
                return true;
            }
        }
    }
    return false;
}

bool isSafeInRow(int grid[N][N],int& row,int value){
    for(int i=0;i<N;i++){
        if(grid[row][i]==value){
            return false;
        }
    }
    return true;
}

bool isSafeInCol(int grid[N][N],int& col,int value){
    for(int i=0;i<N;i++){
        if(grid[i][col]==value){
            return false;
        }
    }
    return true;
}

bool isSafeBox(int grid[N][N],int& row,int& col, int value){
    int rowFactor=row-row%3;
    int colFactor=col-col%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i+rowFactor][j+colFactor]==value){
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int grid[N][N],int& row,int& col,int value){
    if(isSafeInRow(grid,row,value) && isSafeInCol(grid,col,value) && isSafeBox(grid,row,col,value)){
        return true;
    }
    return false;
}

bool solveSudoku(int grid[][N]){
    int row,col;
    if(!findEmptyLocation(grid,row,col)){
        return true;
    }
    for(int i=1;i<=9;i++){
        if(isSafe(grid,row,col,i)){
            grid[row][col]=i;
            if(solveSudoku(grid)){
                return true;
            }
            grid[row][col]=0;
        }
    }
    return false;
}

void solve(){
    string inp[N];
    for(int i=0;i<N;i++){
        getline(cin,inp[i]);
    }
    int grid[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            grid[i][j]=inp[i][j]-'0';
        }
    }
    solveSudoku(grid);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}



int main(void){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<": "<<endl;
        solve();
    }
    return 0;
}