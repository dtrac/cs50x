// cash.c

// header files
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // accept user input in dollars
    float dollars_owed;
    do
    {
        dollars_owed = get_float("Changed owed: ");
    }
    while (dollars_owed < 0);

    // now covert to cents and round
    int cents_owed = round(dollars_owed * 100);

    int coins = 0;

    // loop through available coin types

    const int num_coins = 4;
    int coins_available[] = {25, 10, 5, 1};

    for (int i = 0; i < num_coins; i++)
    {

        if (cents_owed >= coins_available[i])
        {
            do
            {
                cents_owed = cents_owed - coins_available[i];
                coins++;
                //printf("25c removed\n");
            }
            while (cents_owed >= coins_available[i]);
        }

    }

    // print the result
    printf("%i\n", coins);

}