package leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class JumpGameTest {
    final private JumpGame test = new JumpGame();

    @Test
    void test01() {
        boolean output = test.canJump(new int[]{2, 3, 1, 1, 4});
        Assertions.assertTrue(output);
    }

    @Test
    void test02() {
        boolean output = test.canJump(new int[]{3, 2, 1, 0, 4});
        Assertions.assertFalse(output);
    }
}