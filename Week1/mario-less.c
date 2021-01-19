// hashes.c

// header files
#include <cs50.h>
#include <stdio.h>

// function declaraion
int get_number(void);

int main(void)
{

    //int number = get_number(); // get_int("number: ");
    int number;

    do
    {
        number = get_int("Height: ");
    }
    while (number < 1 || number > 8);

    // loop through for specified number of times - creating 'rows'
    for (int i = 0; i < number; i++)
    {

        // on each line
        for (int j = 0; j < (number - i - 1); j++)
        {
            printf(" ");
        }

        // deal with the hashes
        for (int k = 0; k < (i + 1); k++)
        {
            printf("#");
        }

        printf("\n");
    }
    return 0;
}

int get_number(void)
{
    int max_number = 8;

    int n = get_int("enter a number between 1 and 8: ");
    if (n < 1 || n > max_number)
    {
        get_int("enter a number between 1 and 8: ");
    }

    return n;
}