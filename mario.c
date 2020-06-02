#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int size;
    //prompt user for input
    do
    {
        size = get_int("Height: ");
    }
    while (size < 1 || size > 8);
    //for loop to print hashes in one line after another
    for (int i = 0; i < size; i++)
    {
        //nested loop with conditions for right aligned pyramid 
        for (int j = 0; j < size; j++)
        {
            if (i + j < size - 1)
            {
                printf(" ");
            }
            else 
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
