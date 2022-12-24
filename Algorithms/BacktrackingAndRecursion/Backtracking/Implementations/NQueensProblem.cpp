#include<bits/stdc++.h>
using namespace std;

int board[11][11];

bool isPossible(int n,int row,int col){
    //Check for same column
    for(int i=row-1;i>=0;i--){
        if(board[i][col]==1){
            return false;
        }
    }
    //Check for upper left diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1){
            return false;
        }
    }
    //Check for upper right diagonal
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if(board[i][j]==1){
            return false;
        }
    }
    //if none of the cases above meets return true
    return true;
}


void nQueenHelper(int n,int row){
    if(row==n){
        //we have reached some solution, print the board matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j])cout<<'q';
                else cout<<'.';
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    //place at all possible positions and move to smaller problem
    for(int j=0;j<n;j++){
        if(isPossible(n,row,j)){
            board[row][j]=1;//in ascending phase set to 1 to go to next step
            nQueenHelper(n,row+1);
            board[row][j]=0;//in descending phase set to 0 to backtrack
        }
    }
    return;
}

void placeQueens(int n){
    memset(board,0,sizeof(board));
    nQueenHelper(n,0);
}



int main(void){
    int n;
    cin>>n;
    placeQueens(n);
    return 0;
}