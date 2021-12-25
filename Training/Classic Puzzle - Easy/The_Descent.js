/**
 * @file The_Descent.js
 * @author Ladjouzi Rachid (RashidLadj@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-25
 * 
 * @copyright Copyright (c) 2021
 */

// game loop
while (true) {
    let index = -1, maxHeight = -1;
    for (let i = 0; i < 8; i++) {
        const mountainH = parseInt(readline()); // represents the height of one mountain.
        if (mountainH > maxHeight){
            maxHeight = mountainH;
            index = i;
        }
    }

    console.log(index);     // The index of the mountain to fire on.
}
