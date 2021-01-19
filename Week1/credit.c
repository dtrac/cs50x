#include <stdio.h>
#include <cs50.h>


int main()
{
    string card_type;
    int non_multipliers = 0;
    int multipliers = 0;
    int last_digit;
    int second_last_digit;
    int digit1;
    int digit2;
    int product;
    int total;

    long number;

    number = get_long("Enter CC number: ");


    // basic check for amex
    if ((number >= 340000000000000 && number <= 349999999999999) || (number >= 370000000000000 && number <= 379999999999999))
    {
        //printf("could be a amex!");
        card_type = "AMEX";

    }  // basic check for mastercard
    else if (number >= 5100000000000000 && number <= 5599999999999999)
    {
        //printf("could be a mcard!");
        card_type = "MASTERCARD";
    }  // basic check for visa
    else if ((number >= 4000000000000 && number <= 4999999999999) || (number >= 4000000000000000 && number <= 4999999999999999))
    {
        //printf("could be a visa!");
        card_type = "VISA";
    }
    else
    {
        //printf("invalid!");
        card_type = "INVALID";
    }
    //printf("%s", card_type);

    do
    {
        // remove last digit and add to non multipliers
        last_digit = number % 10;
        non_multipliers += last_digit;

        // update number
        number = number / 10;

        // remove second to last digit
        second_last_digit = number % 10;

        // update number
        number = number / 10;

        // times last digit by two
        second_last_digit = second_last_digit * 2;

        // last digit
        digit1 = second_last_digit % 10;

        // second last digit
        digit2 = second_last_digit / 10;

        // get the product of those two...
        product = digit1 + digit2;

        multipliers = multipliers + product;
    }
    while (number > 0);
    total = multipliers + non_multipliers;

    //printf("last_digit %i\n", last_digit);
    //printf("number %li\n", number);
    //printf("non_multipliers %i\n", non_multipliers);

    if (total % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        printf("%s\n", card_type);
    }
}