// N-Queens

#include<iostream>
#include<vector>
using namespace std;

bool isSafe(const vector<vector<int>>& board, int row, int col){
    // condition 1: same column check
    for(int i=0; i<row; i++){
        if(board[i][col] == 1) return false;
    }

    // condition 2: up left diagonal
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 1) return false;
    }

    // condition 3: up right diagonal
    for(int i=row-1, j=col+1; i>=0 && j<board.size(); i--, j++){
        if(board[i][j] == 1) return false;
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row){
    int n = board.size();

    if(row == n) return true;

    for(int col = 0; col < n; col++){
        if(isSafe(board, row, col)){
            board[row][col] = 1;

            if(solveNQueens(board, row+1)) return true;

            board[row][col] = 0;
        }
    }

    return false;
}

int main(){
    int n;
    cout<<"Enter Board Size: ";
    cin>>n; cout<<"\n";

    if(n<=0){
        cout<<"Enter positive number!!"<<endl;
        return 0;
    }

    vector<vector<int>> board(n, vector<int>(n,0));

    if(solveNQueens(board, 0)){
        cout<<"Solution (1 - Queen, 0 - blank): "<<endl;

        for(int row = 0; row<n; row++){
            for(int col = 0; col<n; col++){
                cout<<board[row][col]<<"  ";
            }
            cout<<"\n";
        }
    }else{
        cout<<"No result Found!!";
    }
    
    return 0;
}