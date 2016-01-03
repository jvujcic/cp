import java.util.Arrays;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str_1 = sc.next().toLowerCase();
        String str_2 = sc.next().toLowerCase();
        char[] str_1_array = str_1.toCharArray();
        char[] str_2_array = str_2.toCharArray();
        Arrays.sort(str_1_array);
        Arrays.sort(str_2_array);
        if (Arrays.equals(str_1_array, str_2_array)) {
            System.out.println("Anagrams");
        } else {
            System.out.println("Not Anagrams");
        }
    }
}
