#include "NumClass.h"
#define FALSE 0
#define TRUE  1
int factorial(int num);
int digitCount(int num);
int getDigit(int num,int i);
int myPow(int x, int y);

int isarmstrong(int num,int i,int sum){
    if(i<0){
        return sum;
    }
    int digit=getDigit(num,i);
    sum+= myPow(digit, digitCount(num));
    i--;
    return isarmstrong(num,i,sum);
}

int isArmstrong(int num){
    int sum=isarmstrong(num, digitCount(num)-1,0);
    if(sum==num ){
        return TRUE;
    }
    return FALSE;
}


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

int isPalindrome(int num) {
    if (num < 0) {
        return 0;  // Negative numbers are not palindromes
    }

    int digits = digitCount(num);
    return isPalindromeRec(num, digits);
}



