//redy
#include <stdio.h>
#include "NumClass.h"

int Max(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

int Min(int num1, int num2) {
    return (num1 < num2) ? num1 : num2;
}

int main() {
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    // Print the Armstrong numbers
    printf("The Armstrong numbers are:");
    for (int i = Min(num1, num2); i <= Max(num1, num2); ++i) {
        if (isArmstrong(i)) {
            printf(" %d", i);
        }
    }
    printf("\n");

    // Print the Palindromes
    printf("The Palindromes are:");
    for (int i = Min(num1, num2); i <= Max(num1, num2); ++i) {
        if (isPalindrome(i)) {
            printf(" %d", i);
        }
    }
    printf("\n");

    // Print the Prime numbers
    printf("The Prime numbers are:");
    for (int i = Min(num1, num2); i <= Max(num1, num2); ++i) {
        if (isPrime(i)) {
            printf(" %d", i);
        }
    }
    printf("\n");

    // Print the Strong numbers
    printf("The Strong numbers are:");
    for (int i = Min(num1, num2); i <= Max(num1, num2); ++i) {
        if (isStrong(i)) {
            printf(" %d", i);
        }
    }
    printf("\n");
    return 0;
}