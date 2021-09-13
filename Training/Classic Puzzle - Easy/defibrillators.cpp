#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "cmath"

using namespace std;

vector<string> split (const string &s, const string &delimiter);

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main(){
    string LON, LAT;    cin >> LON; cin.ignore();   cin >> LAT; cin.ignore();

    std::replace( LON.begin(), LON.end(), ',', '.');
    std::replace( LAT.begin(), LAT.end(), ',', '.');

    double lon = stod(LON), lat = stod(LAT);

    int N;  cin >> N; cin.ignore();

    vector<vector<string>> data;

    double distance = -1;
    double pos = -1;

    for (int i = 0; i < N; i++) {
        string DEFIB;   getline(cin, DEFIB);
        data.push_back(split(DEFIB, ";"));

        std::replace( data[i][4].begin(), data[i][4].end(), ',', '.');
        std::replace( data[i][5].begin(), data[i][5].end(), ',', '.');

        double x = (lon - stod(data[i][4])) * cos((lat + stod(data[i][5])) / 2);
        double y = lat - stod(data[i][5]);
        double d = sqrt(pow(x, 2) + pow(y, 2)) * 6371;
       
        if (distance > d || distance == -1){
            distance = d;
            pos = i;
        }
    }

    cout << data[pos][1] << endl;
}

vector<string> split (const string &s, const string &delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string item;
    vector<string> items;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        item = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        items.push_back (item);
    }

    items.push_back (s.substr (pos_start));
    return items;
}