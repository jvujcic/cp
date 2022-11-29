package leetcode;

import java.util.HashMap;

public class LongestSubstringWithoutRepeatingCharacters {

    public int lengthOfLongestSubstring(String s) {
        var seenChars = new HashMap<Character, Integer>();

        int currSize = 0;
        int maxSize = 0;

        for (int i = 0; i < s.length(); i++) {
            var c = s.charAt(i);

            if (seenChars.containsKey(c)) {
                var prevIndex = seenChars.get(c);
                seenChars.entrySet().removeIf(x -> x.getValue() <= prevIndex);
                seenChars.put(c, i);
                currSize = i - prevIndex;
            } else {
                seenChars.put(c, i);
                currSize++;
            }
            if (currSize > maxSize) {
                maxSize = currSize;
            }
        }
        return maxSize;
    }

}
