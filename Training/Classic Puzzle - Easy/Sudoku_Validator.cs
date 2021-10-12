/**
 * @file Sudoku_Validator.cs
 * @author Ladjouzi Rachid (RashidLadj@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-11
 * 
 * @copyright Copyright (c) 2021
 */

using System;
using System.Linq;
using System.Collections.Generic;

class Solution{
    static bool solve(List<List<int>> sudokuGrid){
        List<int> perfect = new List<int>(){1, 2, 3, 4, 5, 6, 7, 8, 9};
        /** valider les lignes du sudoku **/
        for (int i = 0; i<9; ++i){
            var temp = new List<int>(sudokuGrid[i]);
            temp.Sort();
            if (!temp.SequenceEqual(perfect))
                return false;
        }

        /** Transposer la grille du sudoku **/
        var result = sudokuGrid
                    .SelectMany(inner => inner.Select((item, index) => new { item, index }))
                    .GroupBy(i => i.index, i => i.item)
                    .Select(g => g.ToList())
                    .ToList();

        /** valider les colomn du sudoku **/
        for (int i = 0; i < 9; ++i){
            var temp = new List<int>(result[i]);
            temp.Sort();
            if (!temp.SequenceEqual(perfect))
                return false;
        }

        /** valider les sous grilles du sudoku **/            
        foreach (int quadIndex in Enumerable.Range(0, 9)){ 
            List<int> quadList = new List<int>();

            int startRow = (quadIndex / 3) * 3;
            int startCol = (quadIndex % 3) * 3;

            foreach (int i in Enumerable.Range(0, 3)){
                foreach (int j in Enumerable.Range(0, 3)){
                    quadList.Add(sudokuGrid[startRow + i][startCol + j]);
                }
            }

            quadList.Sort();
            if (!quadList.SequenceEqual(perfect))
                return false;
        }

        return true;
    }

    static void Main(string[] args){
        List<List<int>> sudokuGrid = new List<List<int>>();
        for (int i = 0; i++ < 9;){
            List<int> temp = new List<int>();
            string[] inputs = Console.ReadLine().Split(' ');
            for (int j = 0; j < 9; ++j){
                int n = int.Parse(inputs[j]);
                temp.Add(n);
            }
            sudokuGrid.Add(temp);
        }

        Console.WriteLine(solve(sudokuGrid)?"true":"false");
    }
}