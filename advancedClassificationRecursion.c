#include "NumClass.h"
#define FALSE 0
#define TRUE  1
int factorial(int num);
int digitCount(int num);
int getDigit(int num,int i);
int myPow(int x, int y);


/**
 * @brief Check if a number is an Armstrong number using recursion.
 *
 * @param num The number to be checked.
 * @param i The current position while iterating through digits.
 * @param sum The running sum of digits raised to the power of the number of digits.
 * @return TRUE if the number is Armstrong, FALSE otherwise.
 *
 * @remark Stopping condition: When i < 0.(no more digits to check)
 * @remark Recursion step: Calculate the sum by adding the current digit raised to the power of the
 * number of digits. Decrement i for the next iteration.
 */
int isarmstrong(int num,int i,int sum){
    if(i<0){
        return sum;
    }
    int digit=getDigit(num,i);
    sum+= myPow(digit, digitCount(num));
    i--;
    return isarmstrong(num,i,sum);
}

/**
 * @brief Wrapper function to check if a number is an Armstrong number.
 *
 * @param num The number to be checked.
 * @return TRUE if the number is Armstrong, FALSE otherwise.
 */
int isArmstrong(int num){
    if(num<0) {return false;} // negative values to be ignored
    int sum=isarmstrong(num, digitCount(num)-1,0);
    if(sum==num ){
        return TRUE;
    }
    return FALSE;
}

/**
 * @brief Check if a number is a palindrome using recursion.
 * @param num The number to be checked.
 * @param digits The number of digits in the current recursion level.
 * @return TRUE if the number is a palindrome, FALSE otherwise.
 *
 * @remark Stopping condition: When digits <= 1.
 * @remark Recursion step: Compare the first and last digits. If they are equal,
 * trim the number by removing the first and last digits for the next recursion level.
 */
int isPalindromeRec(int num, int digits){
  if(digits <= 1) { // just one digit
      return TRUE;
 }
  int msb= getDigit(num,digits-1);
  int lsb= getDigit(num,0);
  if(msb==lsb){
      //  the number without the lsb and msb
      int trimmednum = (int) ((num - myPow(10,digits-1)*msb ) ) / 10;

      return isPalindromeRec(trimmednum,digits-2);
  }
  return FALSE;
}

/**
 * @brief Wrapper function to check if a number is a palindrome.
 *
 * @param num The number to be checked.
 * @return TRUE if the number is a palindrome, FALSE otherwise.
 */
int isPalindrome(int num) {
    if (num < 0) {
        return FALSE;  // Negative numbers are not palindromes
    }

    int digits = digitCount(num);
    return isPalindromeRec(num, digits);
}



