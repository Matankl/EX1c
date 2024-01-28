#include "NumClass.h"

int countDigits(int);
int power(int, int);
int calcArmstrongRecursive(int, int);
int isPalindromeRecursive(int, int);

// is armstrong number recursion version
// Wrapper function to initiate the recursive check
int isArmstrong(int num) {
    int n = countDigits(num);
    if (num == calcArmstrongRecursive(num, n)) {
        return 1;
    }
    return 0;
}


// Recursive function to check if a number is an Armstrong number
int calcArmstrongRecursive(int number, int numberofdigits) {
    if (number < 10) {
        return power(number, numberofdigits);
    }
    return power(number % 10, numberofdigits) + calcArmstrongRecursive(number / 10, numberofdigits);
}


    


// is palindrome number recursion version
int isPalindrome(int num){
    int digits = countDigits(num);
    return isPalindromeRecursive(num, digits);
}



int isPalindromeRecursive(int num, int digits){
    // Base case returns 1 if the number is a single digit or 0
    if (digits <= 1) {
        return 1;
    }
    int firstDigit = num / power(10, digits - 1);
    int lastDigit = num % 10;
    // Check if the first and last digits are equal
    if (firstDigit != lastDigit) {
        return 0;
    }
    // Recursive call to check the inner digits
    return isPalindromeRecursive((num % power(10, digits - 1)) / 10, digits - 2);
}


// support methods 

// Function to calculate the power of a number
int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else {
        return base * power(base, exponent - 1);
    }
}

// Function to count the number of digits in a number
int countDigits(int num) {
    if (num == 0) {
        return 0;
    } else {
        return 1 + countDigits(num / 10);
    }
}