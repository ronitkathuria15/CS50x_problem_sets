#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    //promt user to input the amount of change required
    do
    {
        dollars = get_float("Change Owed: ");
    }
    //condition to ensure non-negative input
    while (dollars < 0);
    //round the change to optimise calculations 
    int cents = round(dollars * 100);
    //initialize counter to print the number of coins needed
    int counter = 0;
                  //use of a loop to subtract the required amount from the total change and increment the counter each time
                  while (cents > 0)
    {
        if (cents >= 25)
        {
            cents = cents - 25;
            counter++;
        }
        else if (cents >= 10)
        {
            cents = cents - 10;
            counter++;
        }
        else if (cents >= 5)
        {
            cents = cents - 5;
            counter++;
        }
        else if (cents >= 1)
        {
            cents--;
            counter++;
        }
    }
    //print solely the integer value of the number of coins required
    printf("%i\n", counter);
}
