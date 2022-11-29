package leetcode;

public class LongestPalindromicSubstring {

    public String longestPalindrome(String s) {
        String maxPal = "";
        for (int i = 0; i < s.length(); i++) {
            var pal1 = maxPal1(i, s);
            if (pal1.length() > maxPal.length()) {
                maxPal = pal1;
            }

            var pal2 = maxPal2(i, s);
            if (pal2.length() > maxPal.length()) {
                maxPal = pal2;
            }
        }

        return maxPal;
    }

    private String maxPal1(int index, String s) {
        int maxMove = Math.min(index, s.length() - index - 1);
        var str = String.valueOf(s.charAt(index));

        for (int i = 1; i <= maxMove; i++) {
            if (s.charAt(index - i) == s.charAt(index + i)) {
                str = s.charAt(index - i) + str + s.charAt(index + i);
            } else {
                break;
            }
        }
        return str;
    }

    private String maxPal2(int index, String s) {
        if (index + 1 >= s.length()) {
            return "";
        }

        var str = s.substring(index, index + 2);

        if (str.charAt(0) != str.charAt(1)) {
            return "";
        }

        int maxMove = Math.min(index, s.length() - index - 2);

        for (int i = 1; i <= maxMove; i++) {
            if (s.charAt(index - i) == s.charAt(index + i + 1)) {
                str = s.charAt(index - i) + str + s.charAt(index + i + 1);
            } else {
                break;
            }
        }
        return str;
    }

}
