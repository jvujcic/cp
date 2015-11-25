import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i = 0;
        while (sc.hasNext()) {
            String line = sc.nextLine();
            i++;
            System.out.println(Integer.toString(i) + " " + line);
        }

    }
}
