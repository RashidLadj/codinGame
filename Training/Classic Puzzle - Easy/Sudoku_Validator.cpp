/**
 * @file Sudoku_Validator.cpp
 * @author Ladjouzi Rachid (RashidLadj@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-11
 * 
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

bool solve(const array<array<int, 9>, 9> &sudokuGrid);

int main(){
    array<array<int, 9>, 9> sudokuGrid;
    for (int i = 0; i < 9; i++) {
        array<int, 9> temp;
        for (int j = 0; j < 9; j++) {
            int n; cin >> n; cin.ignore();
            temp[j] = n;
        }
        sudokuGrid[i] = temp;
    }
    
    cout << (solve(sudokuGrid) ? "true" : "false") << endl;
}

bool solve(const array<array<int, 9>, 9> &sudokuGrid){
    array<int, 9> perfect = {1, 2, 3, 4, 5, 6, 7, 8, 9};

     /** valider les lignes du sudoku **/
    for (auto row: sudokuGrid){
        std::sort(row.begin(), row.end());
        if (row != perfect)
            return false;
    }
    
    /** valider les colones du sudoku **/
    for (size_t j = 0; j < sudokuGrid[0].size(); ++j){
        array<int, 9> colomn;
        for(size_t i = 0; i < sudokuGrid.size(); ++i){
            colomn[i] = sudokuGrid[i][j];
        }
        std::sort(colomn.begin(), colomn.end());
        if (colomn != perfect)
            return false;
    }

    /** valider les sous grilles du sudoku **/ 
    for (size_t quadIndex = 0; quadIndex < 9; ++quadIndex){ 
        array<int, 9> quadList;

        int startRow = (quadIndex / 3) * 3;
        int startCol = (quadIndex % 3) * 3;

        for(size_t i = 0; i < 3; ++i){
           for(size_t j = 0; j < 3; ++j){
                quadList[i * 3 + j] = sudokuGrid[startRow + i][startCol + j];
            }
        }

        std::sort(quadList.begin(), quadList.end());
        if (quadList != perfect)
            return false;
    }

    return true;
}