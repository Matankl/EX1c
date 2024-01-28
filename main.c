#include <stdio.h>
#include "NumClass.h"


int main() {
    int num1, num2;

    // Get two positive integers from the user
    do {
        scanf("%d %d", &num1, &num2);

    } while (num1 <= 0 || num2 <= 0);

    // Swap the numbers if the first number is greater than the second number
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    // isArmstrong number print loop
    printf("The Armstrong numbers are:");
    for (int i = num1; i <= num2; ++i) {
        if (isArmstrong(i)) {
            printf(" %d", i);
        }
    }
    printf("\n");
    // isPalindrome number print loop
    printf("The Palindromes are:");
    for (int i = num1; i <= num2; ++i) {
        if (isPalindrome(i)) {
            printf(" %d", i);
        }
    }
    printf("\n");
    // isPrime number print loop
    printf("The Prime numbers are:");
    for (int i = num1; i <= num2; ++i) {
        if (isPrime(i)) {  
            printf(" %d", i);
        }
    }
    printf("\n");
    // isStrong number print loop
    printf("The Strong numbers are:");
    for (int i = num1; i <= num2; ++i) {
        if (isStrong(i)) {
            printf(" %d", i);
        }
    }


    return 0;
}

 


 
