/**
 * @file The_Descent.cs
 * @author Ladjouzi Rachid (RashidLadj@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-25
 * 
 * @copyright Copyright (c) 2021
 */

using System;
using System.Linq;

class Player{
    static void Main(string[] args){
        // game loop
        while (true){
            int index = -1;
            int maxHeight = -1;
            foreach (int idx in Enumerable.Range(0, 8)){           
                int mountain_h = int.Parse(Console.ReadLine()); // represents the height of one mountain.
                if (mountain_h > maxHeight){ 
                    maxHeight = mountain_h;
                    index = idx;
                }
            }
            Console.WriteLine(index); // The index of the mountain to fire on.
        }
    }
}