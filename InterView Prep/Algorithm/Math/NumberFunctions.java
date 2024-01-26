import java.util.*;
import java.util.Scanner;
class NumberFunctions{
    int countDigits(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number:");
        int number = scanner.nextInt();
        number = Math.abs(number);
        if(number == 0){
            return 0;
        }
        return (int)Math.floor(Math.log10(number) + 1);
    }
    boolean isPrime(int number){
        if(number == 1){
            return false;
        }
        if(number == 2 || number == 3){
            return true;
        }
        if(number % 2 == 0 || number % 3 == 0){
            return false;
        }
        for(int i = 5; i * i <= number; i = i + 6){
            if(number % i == 0 || number % (i + 2) == 0){
                return false;
            }
        }
        return true;
    }
    boolean isPalindrome(int number){
        int reverse = 0;
        int temp = number;
        while(temp != 0){
            reverse = reverse * 10 + temp % 10;
            temp = temp / 10;
        }
        return reverse == number;
    }
    int factorial(int number){
        if(number == 0){
            return 1;
        }
        return number * factorial(number - 1);
    }
    int gcd(int a, int b){
        if(b == 0){
            return a;
        }
        return gcd(b, a % b);
    }
    int trailingZerosOfFactorial(int x){
        int count=0;
        while(x>=5){
            count+=x/5;
            x/=5;
        }   
        return count;
    }

    
    

    public static void main(String args[]){
        NumberFunctions numberFunctions=new NumberFunctions();
        Scanner scanner = new Scanner(System.in);
        int choice;
        do {
            System.out.println("\nChoose an option:");
            System.out.println("1. Count Digits");
            System.out.println("2. Primality Test");
            System.out.println("3. Palindrome Test");
            System.out.println("4. Factorial");
            System.out.println("5. GCD");
            System.out.println("6. LCM");
            System.out.println("7. Trailing Zeros of Factorial");
            System.out.println("8. Exit");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    int digits=numberFunctions.countDigits();
                    System.out.println("Number of digits in the number is: "+digits);
                    break;
                case 2:
                    int number;
                    System.out.println("Enter the number:");
                    number = scanner.nextInt();
                    System.out.println("Is the number prime? "+numberFunctions.isPrime(number));
                    break;
                case 3:
                    System.out.println("Enter the number:");
                    number = scanner.nextInt();
                    //palindrome checking
                    System.out.println("Is the number palindrome? "+numberFunctions.isPalindrome(number));
                    break;
                case 4:
                    System.out.println("Enter the number:");
                    number = scanner.nextInt();
                    //factorial  
                    System.out.println("Factorial of the number is: "+numberFunctions.factorial(number));             
                    break;
                case 5:
                    System.out.println("Enter the two numbers:");
                    int a = scanner.nextInt();
                    int b = scanner.nextInt();
                    //gcd
                    System.out.println("GCD of the numbers is: "+numberFunctions.gcd(a, b));
                    break;
                case 6:
                    System.out.println("Enter the two numbers:");
                    a = scanner.nextInt();
                    b = scanner.nextInt();
                    //lcm
                    System.out.println("LCM of the numbers is: "+(a * b) / numberFunctions.gcd(a, b));
                    break;
                case 7:
                    System.out.println("Enter the number:");
                    number = scanner.nextInt();
                    //trailing zeros of factorial
                    System.out.println("Trailing zeros of factorial of the number is: "+numberFunctions.trailingZerosOfFactorial(number));
                    break;
                case 8:
                    System.out.println("Exiting the program.");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }

        } while (choice != 8);

    }


}