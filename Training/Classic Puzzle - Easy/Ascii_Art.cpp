
/**
 * @file Ascii_Art.cpp
 * @author Ladjouzi Rachid (RashidLadj@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-26
 * 
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int Length_, Heigth_;   cin >> Length_ >> Heigth_;  cin.ignore();
    string Input_;          getline(cin, Input_);
    
    vector<string> artASCII;
    for(int i = 0; i < Heigth_; i++){
        string row;        getline(cin, row);
        artASCII.push_back(row);
    }

    for (auto &row : artASCII){
        int idx;
        for (auto &actual_: Input_){
            if (actual_ >= 'a' and actual_ <= 'z')
                idx = int(actual_) - int('a');
            else if (actual_ >= 'A' and actual_ <= 'Z')
                idx = int(actual_) - int('A');
            else
                idx = int('z') - int('a') + 1;
        
            cout << row.substr(idx * Length_, Length_);
        }
        cout << endl;
    }

}