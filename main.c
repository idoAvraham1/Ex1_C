#include <stdio.h>
#include "NumClass.h"


int Max1(int num1, int num2){
    if(num1>num2){
        return num1;
    }
    return num2;
}
int min(int num1,int num2) {
    if(num1<num2){
        return num1;
    }
    return num2;
}

int main() {
    int num1;
    int num2;
    scanf("%d %d",&num1, &num2);


    //print the armstrong
    printf("The Armstrong numbers are:");
    for (int i = min(num1,num2); i <= Max1(num1,num2) ; ++i) {
        if(isArmstrong(i)) {
            printf("%d ",i);
        }
    }
    printf("\n");



    //print the palindromes
    printf("The Palindrome are: ");
    for (int i = min(num1,num2); i <= Max(num1,num2) ; ++i) {
        ;
        if(isPalindrome(i)) {
            printf("%d ",i);
        }
    }
    printf("\n");


    // print the primes
    printf("The Prime numbers are: ");
    for (int i = min(num1,num2); i <= Max(num1,num2) ; ++i) {;
        if(isPrime(i)) {
            printf("%d ",i);
        }
    }

    printf("\n");

    //print the strong numbers
    printf("The Strong numbers are: ");
    for (int i = min(num1,num2); i <= Max(num1,num2) ; ++i) {
        if(isStrong(i)) {
            printf("%d ",i);
        }
    }
    printf("\n");
    return 0;
}