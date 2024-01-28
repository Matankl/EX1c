#include "NumClass.h"

int factorial(int n);


int isPrime(int num){
    // If the number is less than or equal to 1, it's not prime
    if (num <= 1) {
        return 0;
    }

    // Check divisibility from 2 up to the square root of the number
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

//is stong number
    int isStrong(int num){
        int originalNum = num;
        int sum = 0;

        // Calculate the sum of the factorial of each digit
        while (num != 0) {
            int digit = num % 10;
            sum += factorial(digit);
            num /= 10;
        }

        // Check if the sum is equal to the original number
        if (sum == originalNum) {
            return 1;
        }
        return 0;
    }


// support methods 


// factorial function for isStrong
int factorial(int n){
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}



