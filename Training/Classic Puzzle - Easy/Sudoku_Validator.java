/**
 * @file sudoku_Validator.java
 * @author Ladjouzi Rachid (RashidLadj@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-11
 * 
 * @copyright Copyright (c) 2021
 */

import java.util.*;
import java.util.Arrays;

class Solution {
    public static boolean solve(int[][] sudokuGrid){
        int[] perfect = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        /** valider les lignes du sudoku **/
        for ( int[] row: sudokuGrid){
            int[] row_ = row.clone();
            Arrays.sort(row_);
            if (!Arrays.equals(row_, perfect))
                return false;
        }

        /** valider les colones du sudoku **/
        for (int j = 0; j < sudokuGrid[0].length; ++j){
            int[] colomn = new int[9];
            for(int i = 0; i < sudokuGrid.length; ++i){
                colomn[i] = sudokuGrid[i][j];
            }
            Arrays.sort(colomn);
            if (!Arrays.equals(colomn, perfect))
                return false;
        }

        /** valider les sous grilles du sudoku **/ 
        for (int quadIndex = 0; quadIndex < 9; ++quadIndex){ 
            int[] quadList = new int[9];

            int startRow = (quadIndex / 3) * 3;
            int startCol = (quadIndex % 3) * 3;

            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    quadList[i * 3 + j] = sudokuGrid[startRow + i][startCol + j];
                }
            }

            Arrays.sort(quadList);
            if (!Arrays.equals(quadList, perfect))
                return false;
        }
        return true;
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int[][] sudokuGrid = new int[9][9];
        for (int i = 0; i < 9; i++) {
            int row[] = new int[9];
            for (int j = 0; j < 9; j++) {
                row[j] = in.nextInt();
            }
            sudokuGrid[i] = row;
        }

        System.out.println(solve(sudokuGrid));
    }  
}