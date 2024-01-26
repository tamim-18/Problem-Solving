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
    void printPrimeFactor(int n){
        if(n<=1){
            return;
        }
        for(int i=2;i*i<=n;i++){
            while(n%i==0){
                System.out.print(i+" ");
                n/=i;
            }
        }
        if(n>1){
            System.out.print(n);
        }
        //time complexity: O(sqrt(n))
    }
    void printPrimeFactorEfficent(int n){
        if(n<=1){
            return;
        }
        while(n%2==0){
            System.out.print(2+" ");
            n/=2;
        }
        while(n%3==0){
            System.out.print(3+" ");
            n/=3;
        }
        for(int i=5;i*i<=n;i+=6){
            while(n%i==0){
                System.out.print(i+" ");
                n/=i;
            }
            while(n%(i+2)==0){
                System.out.print((i+2)+" ");
                n/=(i+2);
            }
        }
        if(n>3){
            System.out.print(n);
        }
        //time complexity: O(sqrt(n))
    }
    void printAllDivisors(int n){
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                System.out.print(i+" ");
                if(i!=n/i){
                    System.out.print((n/i)+" ");
                }
            }
        }
        //time complexity: O(sqrt(n))
    }
    void printAllDivisorSorted(int n){
        ArrayList<Integer> list=new ArrayList<>();
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                System.out.print(i+" ");
                if(i!=n/i){
                    list.add(n/i);
                }
            }
        }
        for(int i=list.size()-1;i>=0;i--){
            System.out.print(list.get(i)+" ");
        }
        //time complexity: O(sqrt(n)
    }
    void sieve(int n){
        boolean[] prime=new boolean[n+1];
        Arrays.fill(prime,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=false;
                }
            }
        }
        for(int i=0;i<=n;i++){
            if(prime[i]){
                System.out.print(i+" ");
            }
        }
        //time complexity: O(nlog(log(n))
    }
    void segmentedSieve(int n){
        int limit=(int)Math.floor(Math.sqrt(n))+1;
        sieve(limit);
        int low=limit;
        int high=2*limit;
        while(low<n){
            if(high>=n){
                high=n;
            }
            boolean[] prime=new boolean[limit+1];
            Arrays.fill(prime,true);
            for(int i=0;i<prime.length;i++){
                if(prime[i]){
                    for(int j=low;j<high;j++){
                        if(j%i==0){
                            prime[j-low]=false;
                        }
                    }
                }
            }
            for(int i=low;i<high;i++){
                if(prime[i-low]){
                    System.out.print(i+" ");
                }
            }
            low+=limit;
            high+=limit;
        }
        //time complexity: O(nlog(log(n))
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
            System.out.println("8. Print Prime Factor");
            System.out.println("9. Print Prime Factor Efficent");
            System.out.println("10. Print All Divisors");
            System.out.println("11. Print All Divisors Sorted");
            System.out.println("12. Sieve of Eratosthenes");
            System.out.println("13. Exit");
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
                    System.out.println("Enter the number:");
                    number = scanner.nextInt();
                    //print prime factor
                    System.out.println("Prime factors of the number are: ");
                    numberFunctions.printPrimeFactor(number);
                    break;
                case 9:
                    System.out.println("Enter the number:");
                    number = scanner.nextInt();
                    //print prime factor
                    System.out.println("Prime factors of the number are: ");
                    numberFunctions.printPrimeFactorEfficent(number);
                    break;
                case 10:
                    System.out.println("Enter the number:");
                    number = scanner.nextInt();
                    //print all divisors
                    System.out.println("All divisors of the number are: ");
                    numberFunctions.printAllDivisors(number);
                    break;
                case 11:
                    System.out.println("Enter the number:");
                    number = scanner.nextInt();
                    //print all divisors
                    System.out.println("All divisors of the number are: ");
                    numberFunctions.printAllDivisorSorted(number);
                    break;
                case 12:
                    System.out.println("Enter the number:");
                    number = scanner.nextInt();
                    //sieve of eratosthenes
                    System.out.println("All prime numbers upto the number are: ");
                    numberFunctions.sieve(number);
                    break;

                case 13:
                    System.out.println("Exiting the program.");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }

        } while (choice != 14);

    }


}