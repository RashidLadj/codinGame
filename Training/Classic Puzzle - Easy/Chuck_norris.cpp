/**
 * @file Chuck_Norris.cpp
 * @author Ladjouzi Rachid (RashidLadj@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-12
 * 
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <bitset>  /** std::bitset **/

using namespace std;

string solve(const string &binaryMessage);

int main(){
    string MESSAGE;
    getline(cin, MESSAGE);
    cout << solve(MESSAGE) << endl;
}

string solve(const string &Message){
    string binaryMessage = "";
    for (const auto &x : Message)
        binaryMessage += bitset<7>(x).to_string();

    string Result = "";
    char current = -1;

    for (auto const &x : binaryMessage){
        if (current != x){
            if (current != -1)
                Result += " ";
            Result += (x == '1') ?  "0 " : "00 ";
            current = x;
        }
        Result += "0";
    }
    return Result;
}