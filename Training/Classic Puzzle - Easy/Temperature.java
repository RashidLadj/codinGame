import java.util.*;
import java.math.*;

class Solution {
    public static void main(String[] args){
        var in = new Scanner(System.in);
        int r=5526,t,n = in.nextInt();
        while(in.hasNextInt()){
            t = in.nextInt();
            if (Math.abs(r) > Math.abs(t) || (Math.abs(r) == Math.abs(t) && t>r))
                r = t;
        }
        System.out.println(n==0?n:r);
    }
}