// Solve Sudoku

#include <iostream>
using namespace std;

void printMatrix(int mat[][9], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int mat[][9], int num, int i, int j) {
    // check for row and column
    for(int k=0; k<9; k++){
        if(mat[i][k]==num || mat[k][j]==num)
            return false;
    }

    // check subgrid
    int sx = (i/3)*3;
    int sy = (j/3)*3;
    for(int x=sx; x<sx+3; x++){
        for(int y=sy; y<sy+3; y++){
            if(mat[x][y] == num)
                return false;
        }
    }

    return true;
}

bool solveSudoku(int mat[][9], int i, int j){
    // base case
    if(i==9){
        printMatrix(mat, 9);
        return true;
    }

    // if crossed the last column
    if(j==9){
        return solveSudoku(mat, i+1, 0);
    }

    // if the cell is pre-filled, skip it
    if(mat[i][j] != 0){
        return solveSudoku(mat, i, j+1);
    }

    // if the cell is empty, try all possibilities
    for(int num=1; num<=9; num++) {
        if(isSafe(mat, num, i, j)){
            mat[i][j] = num;
            bool subProblem = solveSudoku(mat, i, j+1);
            if(subProblem)
                return true;
        }
    }
    mat[i][j] = 0;
    return false;
}

int main() {
    int mat[][9] = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    solveSudoku(mat, 0, 0);
    return 0;
}
