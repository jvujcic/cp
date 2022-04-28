package leetcode;

import java.util.HashMap;

public class TwoSum {

    public int[] twoSum(int[] nums, int target) {
        var indexMap = new HashMap<Integer, Integer>();

        int firstHalfIndex = -1;
        int secondHalfIndex = -1;
        for (int i = 0; i < nums.length; i++) {
            indexMap.put(nums[i], i);
            if (target % 2 == 0 && target / 2 == nums[i]) {
                if (firstHalfIndex == -1) {
                    firstHalfIndex = i;
                } else {
                    secondHalfIndex = i;
                }
            }
        }

        if (firstHalfIndex != -1 && secondHalfIndex != -1) {
            return new int[]{firstHalfIndex, secondHalfIndex};
        }

        for (var pair : indexMap.entrySet()) {
            var num = pair.getKey();
            var firstIndex = pair.getValue();
            if (indexMap.containsKey(target - num)) {
                var secondIndex = indexMap.get(target - num);
                if (firstIndex != secondIndex) {
                    return new int[]{firstIndex, secondIndex};
                }
            }
        }

        return new int[]{};
    }
}
