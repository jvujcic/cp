package leetcode;

import java.util.ArrayList;
import java.util.List;

public class GenerateParentheses {
    public List<String> generateParenthesis(int n) {
        var solution = new ArrayList<String>();
        rec(solution, new StringBuilder(), 0, true, n - 1);
        return solution;
    }

    private void rec(List<String> solution, StringBuilder current, int numberOfOpenLeftPar, boolean isLeft, int n) {
        if (isLeft) {
            current.append('(');
            numberOfOpenLeftPar++;
        } else {
            current.append(')');
            numberOfOpenLeftPar--;
        }

        if (n == 0 && numberOfOpenLeftPar == 0) {
            solution.add(current.toString());
            current.deleteCharAt(current.length() - 1);
            return;
        }

        if (n == 0 && numberOfOpenLeftPar > 0) {
            rec(solution, current, numberOfOpenLeftPar, false, 0);
            current.deleteCharAt(current.length() - 1);
            return;
        }

        if (numberOfOpenLeftPar < 0) {
            current.deleteCharAt(current.length() - 1);
            return;
        }

        rec(solution, current, numberOfOpenLeftPar, true, n - 1);
        rec(solution, current, numberOfOpenLeftPar, false, n);

        current.deleteCharAt(current.length() - 1);
    }
}
