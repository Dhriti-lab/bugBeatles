#include<bits/stdc++.h>
using namespace std;

bool isSafe(int mat[][9], int i, int j, int no, int n){

    // check for row and column
    for (int k = 0; k<n; k++){
        if(mat[i][k]==no or mat[k][j]==no){
            return false;
        }
    }

    // check for the subgrid
    int sx = (i / 3) * 3;
    int sy = (j / 3) * 3;

    for (int x = sx; x < sx + 3; x++){
        for (int y = sy; y < sy + 3; y++){
            if(mat[x][y]==no)
                return false;
        }
    }

    return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n){
    // base case
    if( i == 9){
        // print the solution
        for(int k=0; k<9; k++){
            for (int l = 0; l < 9; l++){
                cout << mat[k][l] << " ";
            }
            cout << endl;
        }
        cout << endl;

        return true;
    }

    // recusrsive case
    if(j == 9){
        return solveSudoku(mat, i + 1, 0, n);
    }

    // skip the prefilled cell
if(mat[i][j] != 0){
    return solveSudoku(mat, i, j + 1, n);
}

// cell to be filled
// try out all possibilities
for (int no = 1; no <= 9; no++){
    // whether it is safe to place to number or not 
    if(isSafe(mat, i, j, no, n)){
        mat[i][j] = no;
        bool solveSubProblem = solveSudoku(mat, i, j + 1, n);
        if(solveSubProblem)
            return true;
    }
}

    // if no option work
    mat[i][j] = 0;
    return false;
}

int main(){
    int n = 9;
    // int mat[9][9] = {
    //     {5, 3, 0, 0, 7, 0, 0, 0, 0},
    //     {6, 0, 0, 1, 9, 5, 0, 0, 0},
    //     {0, 9, 8, 0, 0, 0, 0, 6, 0},
    //     {8, 0, 0, 0, 6, 0, 0, 0, 3},
    //     {4, 0, 0, 8, 0, 3, 0, 0, 1},
    //     {7, 0, 0, 0, 2, 0, 0, 0, 6},
    //     {0, 6, 0, 0, 0, 0, 2, 8, 0},
    //     {0, 0, 0, 4, 1, 9, 0, 0, 5},
    //     {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    int mat[9][9] = {0};
    cout << "enter sudoku problem in 9X9 matrix form, put zero at positons that need to be solved" << endl;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cin >> mat[i][j];
        }
    }

        if (!solveSudoku(mat, 0, 0, n))
        {
            cout << "no solution exist" << endl;
        }

        return 0;
}