#include "NumClass.h"
#define FALSE 0
#define TRUE 1

int factorial(int num);
int digitCount(int num);
int getDigit(int num,int i);
int myPow(int x, int y);

/**
 * @brief Check if a number is an Armstrong number using loops.
 *
 * @param num The number to be checked.
 * @return TRUE if the number is Armstrong, FALSE otherwise.
 *
 * @remark Loop-based implementation: Calculate the sum by iterating through each digit,
 * raising it to the power of the number of digits, and adding to the sum.
 * Compare the sum with the original number to determine if it's an Armstrong number.
 */
int isArmstrong(int num){
    if(num<0) {return FALSE;}
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


/**
 * @brief Check if a number is a palindrome using loops.
 *
 * @param num The number to be checked.
 * @return TRUE if the number is a palindrome, FALSE otherwise.
 *
 * @remark Loop-based implementation: Calculate the reverse of the number by iterating
 * through each digit in reverse order and reconstructing the number.
 * Compare the reversed number with the original to determine if it's a palindrome.
 */
int isPalindrome(int num){
    if(num<0) {return FALSE;}
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
