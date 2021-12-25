/**
 * @file The_Descent.java
 * @author Ladjouzi Rachid (RashidLadj@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-25
 * 
 * @copyright Copyright (c) 2021
 */
 
import java.util.*;

class Player {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        // game loop
        while (true) {
            int index = -1, maxHeight = -1;
            for (int idx = 0; idx < 8; ++idx) {
                int mountainH = in.nextInt(); // represents the height of one mountain.
                if (mountainH > maxHeight){
                    maxHeight = mountainH;
                    index = idx;
                }
            }
            System.out.println(index); // The index of the mountain to fire on.
        }
    }
}