#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int N;   cin >> N;   cin.ignore();

    vector<int> mySet;
    
    for (size_t i = 0; i < N; i++) {
        int Pi; cin >> Pi; cin.ignore();
        mySet.push_back(Pi);
    }

    std::sort(mySet.begin(), mySet.end());

    int diff = -1;
    for (size_t i = 1; i < mySet.size(); ++i){
        int d = abs(mySet[i] - mySet[i-1]);
        if (d < diff || diff == -1)
            diff = d;
    }

    cout << diff << endl;
}