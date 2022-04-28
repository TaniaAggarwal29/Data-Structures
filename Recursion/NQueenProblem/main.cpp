// Place N queens on NxN chess board such that no queen can attack each other

#include <iostream>
using namespace std;

void printBoard(int n, int board[][20]) {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool canPlace(int n, int board[][20], int x, int y){
    // check column
    for(int i=0; i<x; i++){
        if(board[i][y] == 1)
            return false;
    }

    // check left diagonal
    int i = x, j = y;
    while(i>=0 and j>=0){
        if(board[i][j] == 1)
            return false;
        i--; j--;
    }

    // check right diagonal
    i = x, j = y;
    while(i>=0 and j<=n){
        if(board[i][j] == 1)
            return false;
        i--; j++;
    }
    return true;
}

bool placeNQueens(int n, int board[][20], int i){
    // base case
    // if the control reached beyond (n-1)th row, that means all the queens are successfully placed
    if(i==n) {
        printBoard(n, board);
        return true;
    }

    // recursive case
    for(int j=0; j<n; j++){
        if(canPlace(n, board, i, j)){
            board[i][j] = 1;
            bool success = placeNQueens(n, board, i+1);
            if(success){
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int board[20][20] = {0};

    bool success = placeNQueens(n, board, 0);
    cout << success << endl;

    return 0;
}
