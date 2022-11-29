package leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class LongestSubstringWithoutRepeatingCharactersTest {

    private final LongestSubstringWithoutRepeatingCharacters test = new LongestSubstringWithoutRepeatingCharacters();

    @Test
    void test01() {
        Assertions.assertEquals(3, test.lengthOfLongestSubstring("abcabcbb"));
    }

    @Test
    void test02() {
        Assertions.assertEquals(1, test.lengthOfLongestSubstring("bbbbb"));
    }

    @Test
    void test03() {
        Assertions.assertEquals(3, test.lengthOfLongestSubstring("pwwkew"));
    }

}