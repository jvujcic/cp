package leetcode;

public class JumpGame {
    public boolean canJump(int[] nums) {
        boolean[] canReach = new boolean[nums.length];
        int maxReachable = 0;

        for (int i = 0; i < nums.length; i++) {
            if (i > maxReachable) return false;
            maxReachable = Math.max(maxReachable, i + nums[i]);
        }

        return true;
    }
}
