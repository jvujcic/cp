package leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class TwoSumTest {

    private final TwoSum twoSum = new TwoSum();

    @Test
    void test01() {
        var output = twoSum.twoSum(new int[]{2, 7, 11, 15}, 9);
        var expected = new int[]{0, 1};
        Assertions.assertArrayEquals(expected, output);
    }

    @Test
    void test02() {
        var output = twoSum.twoSum(new int[]{3, 2, 4}, 6);
        var expected = new int[]{1, 2};
        Assertions.assertArrayEquals(expected, output);
    }

    @Test
    void test03() {
        var output = twoSum.twoSum(new int[]{3, 3}, 6);
        var expected = new int[]{0, 1};
        Assertions.assertArrayEquals(expected, output);
    }
}