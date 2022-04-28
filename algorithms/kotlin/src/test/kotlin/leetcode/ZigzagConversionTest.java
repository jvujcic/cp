package leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class ZigzagConversionTest {

    private final ZigzagConversion test = new ZigzagConversion();

    @Test
    void test01() {
        var output = test.convert("PAYPALISHIRING", 3);

        Assertions.assertEquals("PAHNAPLSIIGYIR", output);
    }

    @Test
    void test02() {
        var output = test.convert("PAYPALISHIRING", 4);

        Assertions.assertEquals("PINALSIGYAHRPI", output);
    }

    @Test
    void test03() {
        var output = test.convert("A", 1);

        Assertions.assertEquals("A", output);
    }
}