#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col){
    int n = board.size();
    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            if(board[r][c] == 1){
                // check row and col
                if(row == r || col == c) return false;

                //check diagonal
                if(abs(row-r) == abs(col-c)) return false;
            }
        }
    }
    return true;
}

int solCount = 0;
bool NQueens(vector<vector<int>>& board, int row, int fixedRow){
    int n = board.size();

    if(row == n){
        cout<<"Solution "<<++solCount<<":"<<endl;
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                cout<<(board[r][c] ? " Q " : " . ");
            }
            cout<<"\n";
        }
        return true;
    }

    if(row == fixedRow){
        NQueens(board, row+1, fixedRow);
        return true;
    }

    bool found = false;

    for(int col=0; col<n; col++){
        if(isSafe(board, row, col)){
            board[row][col] = 1;
            if(NQueens(board, row+1, fixedRow)){
                found = true;
            };
            board[row][col] = 0;
        }
    }

    return found;
}

int main(){
    int n;
    cout<<"Enter Board Size: ";
    cin>>n;

    int row, col, fixedRow, fixedCol;
    cout<<"Enter fixed row & col: ";
    cin>>row>>col;

    fixedRow = row-1;
    fixedCol = col-1;

    vector<vector<int>> board(n, vector<int>(n, 0));

    board[fixedRow][fixedCol] = 1;

    if(NQueens(board, 0, fixedRow)){
        cout<<"Solution Found!!!!"<<endl;
    }else{
        cout<<"NO Solution Found!!"<<endl;
    }

    return 0;
}