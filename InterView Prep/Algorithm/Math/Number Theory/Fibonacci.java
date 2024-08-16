import java.util.Scanner;

public class Fibonacci {
    long Mod = 1000000007;

    public long fib(int N) {
        if (N == 0)
            return 0;
        if (N == 1)
            return 1;
        long a = 0;
        long b = 1;
        long c = 0;
        for (int i = 2; i <= N; i++) {
            c = (a % Mod + b % Mod) % Mod; // Take modulus after adding a and b
            a = b;
            b = c;
        }
        return c;
    }
    long fibRecursion(int N) {
        if (N == 0)
            return 0;
        if (N == 1)
            return 1;
        return fibRecursion(N - 1) + fibRecursion(N - 2);
    }
    long fibUsingMatrix(int N) {
        long[][] F = new long[][] { { 1, 1 }, { 1, 0 } };
        if (N == 0)
            return 0;
        power(F, N - 1);
        return F[0][0];
    }
    void multiply(long[][] F, long[][] M) {
        long x = (F[0][0] * M[0][0] % Mod + F[0][1] * M[1][0] % Mod) % Mod;
        long y = (F[0][0] * M[0][1] % Mod + F[0][1] * M[1][1] % Mod) % Mod;
        long z = (F[1][0] * M[0][0] % Mod + F[1][1] * M[1][0] % Mod) % Mod;
        long w = (F[1][0] * M[0][1] % Mod + F[1][1] * M[1][1] % Mod) % Mod;
        F[0][0] = x;
        F[0][1] = y;
        F[1][0] = z;
        F[1][1] = w;
    }
    void power(long[][] F, int N) {
        if (N == 0 || N == 1)
            return;
        long[][] M = new long[][] { { 1, 1 }, { 1, 0 } };
        power(F, N / 2);
        multiply(F, F);
        if (N % 2 != 0)
            multiply(F, M);
    }

    public static void main(String args[]) {
        Fibonacci f = new Fibonacci();
        Scanner scanner = new Scanner(System.in);
        int choice;
        do {
            System.out.println("\nChoose an option:");
            System.out.println("1. Find nth Fibonacci number");
            System.out.println("2. Find nth Fibonacci number (using recursion)");
            System.out.println("2. Exit");
            choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    System.out.println("Enter the value of n:");
                    int n = scanner.nextInt();
                    System.out.println("The nth Fibonacci number is: " + f.fibRecursion(n));
                    break;
                case 2:
                    System.out.println("Enter the value of n:");
                    int n1 = scanner.nextInt();
                    System.out.println("The nth Fibonacci number is: " + f.fib(n1));
                    break;
                case 3:
                    System.out.println("Enter the value of n:");
                    int n2 = scanner.nextInt();
                    System.out.println("The nth Fibonacci number is: " + f.fibUsingMatrix(n2));
                    break;
                case 4:
                    System.out.println("Exiting...");
                    break;
                default:
                 System.out.println("Invalid choice. Please enter a valid option.");
            }
        } while (choice != 4);
    }
}
