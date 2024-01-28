#include "NumClass.h"

int countDigits(int);
int power(int, int);

// is armstrong number loop version
int isArmstrong (int num){
    int originalNum = num;
    int digitCount = countDigits(num);
    int sum = 0;

    // Calculate the sum of nth power of each digit, stops if sum exceeds the original number
    while (num != 0) {
        int digit = num % 10;
        sum += power(digit, digitCount);
        num /= 10;
    }

    // Check if the sum is equal to the original number
    return sum == originalNum
    }
    return 0;
}


// is palindrome number loop version
int isPalindrome(int num){
    int originalNum = num;
    int reversedNum = 0;

    // Reverse the number
    while (num != 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    // Check if the reversed number is equal to the original number
    if (reversedNum == originalNum) {
        return 1;
    }
    return 0;
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

