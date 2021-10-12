/**
 * @file Temperature.cpp
 * @author Ladjouzi Rachid (RashidLadj@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-11
 * 
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;cin>>n;
    map<double,int> m;
    int i =0;

    while (i<n){
        int t; 
        cin>>t;
        m[abs(t-.1)]=t;
        ++i;
        }

    cout << m.begin()->second;
}