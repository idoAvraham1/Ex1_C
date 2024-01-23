#include "NumClass.h"
#define FALSE 0
#define TRUE 1

int factorial(int num);
int digitCount(int num);
int getDigit(int num,int i);
int myPow(int x, int y);

/**
 * @brief Check if a number is a strong number.
 *  This function iterates through each digit,
 * calculates its factorial, and checks if the sum equals the original number.
 *
 * @param num The number to be checked.
 * @return TRUE if the number is strong, FALSE otherwise.
 */
int isStrong(int num){
    if(num<0)  // strong number not defined for negative values
    {
        return FALSE;
    }
    int numOfDigits= digitCount(num); 
    int SumOfDigits=0;
    for (int i = numOfDigits - 1; i >= 0; i--) { 
        // get the digit in the i's place in num
        int digit= getDigit(num,i);
        //calc the sum of the facotrial of each digit in num
        SumOfDigits+= factorial(digit);
    }
    // Check if the sum of factorials equals the original number
    if(num==SumOfDigits){
        return TRUE;
    }
   return FALSE;
}


/**
 * @brief Check if a number is a prime number.
 * This function checks for factors in the range
 * from 2 to the square root of the number to determine if it is prime.
 *
 * @param num The number to be checked.
 * @return TRUE if the number is prime, FALSE otherwise.
 */
int isPrime(int num){
    if(num < 1) {
        return FALSE;
    }
    for ( int i = 2; i*i <=num ; i++) { // iterate the all the number
        if(num % i ==0) {
            return FALSE;
        }
    }
    return TRUE;
}

/**
 * @brief Count the number of digits in an integer.
 *
 * @param num The integer for which digit count needs to be calculated.
 * @return The number of digits in the given integer.
 */
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

/**
 * @brief Calculate the factorial of a given number.
 *
 * @param num The number for which factorial needs to be calculated.
 * @return The factorial of the given number.
 */
int factorial(int num) {
    if(num<0) {return 0;} // return 0 if num is negative
    if(num==0 || num==1){
        return 1;
    }
    int fact=1;
    for (int i =2; i <=num ; ++i) {
        fact=fact*i;
    }
    return fact;
}

/**
 * @brief Get the digit at a specified position in a given number.
 *
 * This function extracts the digit at the specified position (i) in the given number (num).
 * It uses the formula (num / (int)myPow(10, i)) % 10 to isolate the desired digit.
 *
 * @param num The number from which to extract the digit.
 * @param i The position of the digit to be extracted.
 * @return The digit at the specified position.
 */
int getDigit(int num,int i){
   return (num / (int)myPow(10, i)) % 10;
}

/**
 * @brief Calculate x raised to the power of y.
 *
 * @param x The base.
 * @param y The exponent.
 * @return x raised to the power of y.
 */
int myPow(int x, int y) {
    int tmp=y;
    int ans=1;
    while(tmp>0) {
        ans*=x;
        tmp--;
    }
    return ans;
}