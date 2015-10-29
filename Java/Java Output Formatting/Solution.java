import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("================================");
        for(int i = 0; i < 3; i++) {
            String str = sc.next();
            int x = sc.nextInt();
            System.out.printf("%-15s", str);
            System.out.printf("%03d%n", x );
        }
        System.out.println("================================");
    }
}
