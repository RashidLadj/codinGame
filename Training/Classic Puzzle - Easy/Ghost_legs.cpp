/**
 * @file Ghost_Legs.cpp
 * @author Ladjouzi Rachid (RashidLadj@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-11
 * 
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int W, H;
    cin >> W >> H; cin.ignore();

    vector<vector<char>> myMatrix;
    for (int i = 0; i < H; i++) {
        string line;
        getline(cin, line);

        vector<char> tempLine;
        for (auto const &c: line)
            tempLine.push_back(c);
        myMatrix.push_back(tempLine);
    }

    for (size_t j = 0; j < W ; j+=3){
        size_t actualCol = j;
        size_t actualLine = 0;

        while (actualLine != H - 1){
            
            if(actualCol >= 3 && myMatrix[actualLine][actualCol-1] == '-')
                actualCol -= 3;

            else if(actualCol <= W-3 && myMatrix[actualLine][actualCol+1] == '-')
                actualCol += 3;

            actualLine += 1;
        }

        cout << myMatrix[0][j] << myMatrix[actualLine][actualCol] << endl;
    }
}