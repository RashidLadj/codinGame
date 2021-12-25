/**
 * @file The_Descent.cpp
 * @author Ladjouzi Rachid (RashidLadj@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-25
 * 
 * @copyright Copyright (c) 2021
 */

#include <iostream>

using namespace std;

int main(){
    // game loop
    while (1) {
        int index = -1, maxHeight = -1;
        for (int idx = 0; idx < 8; ++idx) {
            int mountain_h; // represents the height of one mountain.
            cin >> mountain_h; cin.ignore();

            if (mountain_h > maxHeight) {
                maxHeight = mountain_h;
                index = idx;
            }
        }
        cout << index << endl; // The index of the mountain to fire on.
    }
}