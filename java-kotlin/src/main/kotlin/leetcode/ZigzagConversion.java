package leetcode;

public class ZigzagConversion {
    public String convert(String s, int numRows) {
        if (numRows == 1) return s;

        var solution = new StringBuilder(s.length());
        int step = (numRows - 1) * 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; ; j++) {
                int index1 = i + j * step;
                if (index1 >= s.length()) break;
                solution.append(s.charAt(index1));

                if (i != 0 && i != numRows - 1) {
                    int index2 = (j + 1) * step - i;
                    if (index2 < s.length())
                        solution.append(s.charAt(index2));
                }
            }
        }
        
        return solution.toString();
    }
}
