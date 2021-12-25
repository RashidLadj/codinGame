/**
 * @file The_Descent.c
 * @author Ladjouzi Rachid (RashidLadj@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-25
 * 
 * @copyright Copyright (c) 2021
 */
 
#include <stdio.h>

int main(){
    // game loop
    while (1) {
        int index = -1, maxHeight = -1;
        for (int idx = 0; idx < 8; ++idx) {
            // represents the height of one mountain.
            int mountain_h;
            scanf("%d", &mountain_h);
            if (mountain_h > maxHeight) {
                maxHeight = mountain_h;
                index = idx;
            }
        }

        printf("%d\n", index); // The index of the mountain to fire on.
    }
    return 0;
}