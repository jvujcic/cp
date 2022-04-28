package leetcode;

import java.util.EnumMap;

/*
minlen[n] = {}
minlen

1 2 3 1 4 2 3 1 2 2
0 1 2 2 3 3 4 4 4
 */
public class JumpGameII {
    public int jump(int[] nums) {
        if (nums.length == 1) return 0;

        int left = 0;
        int right = nums[0];
        int minJumps = 1;

        for (int i = 1; i < nums.length; i++) {
            if (right >= nums.length - 1) return minJumps;

            if (i > left) {
                minJumps++;
                left = right;
            }
            if (right < i + nums[i]) {
                right = i + nums[i];
            }
        }

        return minJumps;
    }
}
