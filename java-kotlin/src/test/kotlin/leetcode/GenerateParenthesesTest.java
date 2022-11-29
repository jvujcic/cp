package leetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashSet;
import java.util.Set;
import java.util.stream.Collectors;

import static org.junit.jupiter.api.Assertions.*;

class GenerateParenthesesTest {
    private final GenerateParentheses test = new GenerateParentheses();

    @Test
    void test01() {

        var output = test.generateParenthesis(3);

        var expected = Set.of("((()))", "(()())", "(())()", "()(())", "()()()");

        Assertions.assertTrue(expected.equals(new HashSet<>(output)));
    }
}