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
    
    

    public static void main(String args[]){
        NumberFunctions numberFunctions=new NumberFunctions();
        Scanner scanner = new Scanner(System.in);
        int choice;
        do {
            System.out.println("\nChoose an option:");
            System.out.println("1. Count Digits");
            System.out.println("2. Primality Test");
            System.out.println("3. Exit");
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
                    System.out.println("Exiting the program.");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }

        } while (choice != 3);

    }


}