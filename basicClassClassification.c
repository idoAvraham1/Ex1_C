#include "NumClass.h"
#define FALSE 0
#define TRUE 1

int factorial(int num);
int digitCount(int num);
int getDigit(int num,int i);
int myPow(int x, int y);

// check if num is strong
int isStrong(int num){
    int numOfDigits= digitCount(num);
    int SumOfDigits=0;
    for (int i = numOfDigits - 1; i >= 0; i--) {
        // get the digit in the i's place in num
        int digit= getDigit(num,i);
        //calc the sum of the facotrial of each digit in num
        SumOfDigits+= factorial(digit);
    }
    if(num==SumOfDigits){
        return TRUE;
    }
   return FALSE;
}


//check if num is prime
int isPrime(int num){
    if(num <= 1) {
        return FALSE;
    }
    for ( int i = 2; i < num ; ++i) {
        if(num % i ==0) {
            return FALSE;
        }
    }
    return TRUE;
}

// return the number of digits in integer
int digitCount(int num){
    // Count the number of digits in the given number
    int temp = num;
    int digitCount = 0;
    while (temp != 0) {
        temp /= 10;
        digitCount++;
    }
    return digitCount;
}
// return the num!
int factorial(int num) {
    if(num==0 || num==1){
        return 1;
    }
    int fact=1;
    for (int i =2; i <=num ; ++i) {
        fact=fact*i;
    }
    return fact;
}

// return the i't digits in num
int getDigit(int num,int i){
   return (num / (int)myPow(10, i)) % 10;
}
//return x^y
int myPow(int x, int y) {
    int tmp=y;
    int ans=1;
    while(tmp>0) {
        ans*=x;
        tmp--;
    }
    return ans;
}