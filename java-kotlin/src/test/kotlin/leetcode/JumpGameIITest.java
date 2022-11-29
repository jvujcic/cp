package leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class JumpGameIITest {

    private final JumpGameII test = new JumpGameII();

    @Test
    void test01() {
        int output = test.jump(new int[]{2, 3, 1, 1, 4});
        Assertions.assertEquals(2, output);
    }

    @Test
    void test02() {
        int output = test.jump(new int[]{2, 3, 0, 1, 4});
        Assertions.assertEquals(2, output);
    }

    @Test
    void test03() {
        int output = test.jump(new int[]{7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3});
        Assertions.assertEquals(2, output);
    }
}