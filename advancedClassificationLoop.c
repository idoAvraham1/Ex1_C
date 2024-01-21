#include "NumClass.h"
#define FALSE 0
#define TRUE 1

int factorial(int num);
int digitCount(int num);
int getDigit(int num,int i);
int myPow(int x, int y);


// check if num is armstrong number
int isArmstrong(int num){
    int sum=0;
    int digitsNum= digitCount(num);

    for (int i = 0; i < digitsNum ; i++) {
        sum+=(int ) myPow( getDigit(num,i) , digitsNum) ;
    }
    if(sum==num){
        return TRUE;
    }
    return FALSE;
}


// check if num is a palindrome
int isPalindrome(int num){
    int numOfDigits= digitCount(num);
    int reverse=0;
    int Power=0;
    for (int i = numOfDigits-1; i >=0 ; i--) {
        reverse+= getDigit(num,i) * (int) myPow(10,Power);
        Power++;
    }
    if(reverse==num){
        return TRUE;
    }
    return FALSE;
}
