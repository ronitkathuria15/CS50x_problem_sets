#include <stdio.h>
#include <cs50.h>

//declare functions
bool validity(long number);
int get_length(long number);
bool checksum(long number);
void print_brand(long number);

int main(void)
{
    long number;
    //promt user to input non-negative credit card number
    do
    {
        number = get_long("Credit Card Number: ");
    }
    while (number < 0);
    //condition to print brand using individual functions to check validity and determine brand
    if (validity(number))
    {
        print_brand(number);
    }
    else
    {
        printf("INVALID\n");
    }
}
//fucntion to check validity using length and checksum
bool validity(long number)
{
    int length = get_length(number);
    return (length == 13 || length == 15 || length == 16) && checksum(number);
}
//function that uses loop to find the number of digits in the credit card number 
int get_length(long n)
{
    int counter = 0;
    while (n > 0)
    {
        n = n / 10;
        counter++;
    }
    return counter;
}
//function that uses loop to determine whether card number meets condition of checksum
bool checksum(long num)
{
    int sum = 0;
    for (int i = 0; num > 0; i++, num = num / 10)
    {
        if (i % 2 == 0)
        {
            sum = sum + (num % 10); 
        }
        else 
        {
            int digit = (num % 10) * 2;
            //add the digits of the number rather than the number itseld
            sum = sum + (digit % 10) + (digit / 10);
        }
    }
    return (sum % 10) == 0;
}
//function to print brand name depending on length and starting numbers
void print_brand(long number)
{
    if ((number >= 34e13 && number < 35e13) || (number >= 37e13 && number < 38e13))
    {
        printf("AMEX\n");
    }
    else if (number >= 51e14 && number < 56e14)
    {
        printf("MASTERCARD\n");
    }
    else if ((number >= 4e15 && number < 5e15) || (number >= 4e12 && number < 5e12))
    {
        printf("VISA\n");
    }
    else 
    {
        printf("INVALID\n");
    }
}
