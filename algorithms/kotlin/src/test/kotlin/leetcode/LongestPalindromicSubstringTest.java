package leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class LongestPalindromicSubstringTest {

    private final LongestPalindromicSubstring test = new LongestPalindromicSubstring();

    @Test
    void test01() {
        Assertions.assertEquals("bab", test.longestPalindrome("babad"));
    }

    @Test
    void test02() {
        Assertions.assertEquals("bb", test.longestPalindrome("cbbd"));
    }

    @Test
    void test03() {
        Assertions.assertEquals("aaaa", test.longestPalindrome("aaaa"));
    }
}