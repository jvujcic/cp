import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numberOfTests = sc.nextInt();
        for (int i = 0; i < numberOfTests; i++) {
            try {
                long x = sc.nextLong();
                System.out.println(x + " can be fitted in:");
                if (x >= -(1 << 7) && x <= ((1 << 7) - 1)) System.out.println("*byte");
                if (x >= -(1 << 15) && x <= ((1 << 15) - 1)) System.out.println("*short");
                if (x >= -(1 << 31) && x <= ((1 << 31) - 1)) System.out.println("*int");
                System.out.println("*long");
            } catch (Exception e) {
                System.out.println(sc.next() + " can't be fitted anywhere.");
            }
        }
    }
}
