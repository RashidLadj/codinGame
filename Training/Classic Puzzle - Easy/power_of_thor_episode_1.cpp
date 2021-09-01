#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();

    double deltaX = std::numeric_limits<double>::quiet_NaN();
    double deltaY = std::numeric_limits<double>::quiet_NaN();


    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
    
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