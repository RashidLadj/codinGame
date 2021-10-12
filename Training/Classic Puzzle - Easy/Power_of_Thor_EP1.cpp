/**
 * @file Power_of_Thor_EP1.cpp
 * @author Ladjouzi Rachid (RashidLadj@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-11
 * 
 * @copyright Copyright (c) 2021
 */

#include <iostream> /** std::cout **/
#include <limits>   /** std::numeric_limits<double>::quiet_NaN() **/
#include <cmath>    /** std::isnan **/

using namespace std;

int main(){
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();

    double deltaX = std::numeric_limits<double>::quiet_NaN();
    double deltaY = std::numeric_limits<double>::quiet_NaN();

    /** Game loop **/
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();
    
        if (std::isnan(deltaX)){
            deltaX = lightX - initialTX;
            deltaY = lightY - initialTY;
        }

        string result = "";

        if (deltaY > 0){
            result += "S";
            deltaY -= 1;
        }
        else if (deltaY < 0){
            result += "N";
            deltaY += 1;
        }
        
        if (deltaX > 0){
            result += "E";  
            deltaX -= 1;
        }
        else if (deltaX < 0){
            result += "W";
            deltaX += 1;
        }

        // A single line providing the move to be made: N NE E SE S SW W or NW
        cout << result << endl;
    }
}