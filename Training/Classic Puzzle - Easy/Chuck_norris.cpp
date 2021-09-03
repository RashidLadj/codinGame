#include <iostream>
#include <bitset>         // std::bitset


using namespace std;


string solve(const string &binaryMessage);
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

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