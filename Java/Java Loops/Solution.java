import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numberOfTests = sc.nextInt();

        for (int i = 0; i < numberOfTests; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int n = sc.nextInt();
            int pow2 = 1;
            int x = a;
            for (int j = 0; j < n; j++) {
                x = x + (pow2 << j) * b;
                System.out.printf("%d ", x);
            }
            System.out.println();
        }
    }
}
