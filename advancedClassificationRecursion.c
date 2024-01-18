#include "NumClass.h"
#include <math.h>
#define FALSE 0
#define TRUE  1
int factorial(int num);
int digitCount(int num);
int getDigit(int num,int i);
int isarmstrong(int num,int i,int sum);

int isArmstrong(int num){
    int sum=isarmstrong(num, digitCount(num)-1,0);
    if(sum==num ){
        return TRUE;
    }
    return FALSE;
}

int isarmstrong(int num,int i,int sum){
    if(i<0){
        return sum;
    }
    int digit=getDigit(num,i);
    sum+= pow(digit, digitCount(num));
    i--;
    return isarmstrong(num,i,sum);
}

int isPalindrome(int num){
  if(num/10==0 ) { // just one digit
      return TRUE;
 }
  int d= digitCount(num);
  int msb= getDigit(num,0);
  int lsb= getDigit(num,d-1);
  if(msb==lsb){
      // return the number without the lsb and msb
      int trimmednum = (int) (num - pow(10,d-1)*msb ) / 10;
      return isPalindrome(trimmednum);
  }
  return FALSE;
}

