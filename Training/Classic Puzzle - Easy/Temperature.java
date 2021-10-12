/**
 * @file Temperature.java
 * @author Ladjouzi Rachid (RashidLadj@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-11
 * 
 * @copyright Copyright (c) 2021
 */

import java.util.*;
import java.math.*;

class Solution {

    public static void main(String[] args){
        var in = new Scanner(System.in);
        int r = 5526, n = in.nextInt();

        while(in.hasNextInt()){
            int t = in.nextInt();
            if (Math.abs(r) > Math.abs(t) || (Math.abs(r) == Math.abs(t) && t > r))
                r = t;
        }

        System.out.println(n == 0 ? n : r);
    }
}