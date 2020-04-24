#include <cs50.h>
#include <stdio.h>
#include <math.h>

/* For testing: 
https://developer.paypal.com/docs/payflow/payflow-pro/payflow-pro-testing/#credit-card-numbers-for-testing */

int main(void)
{
    /* Collect user input: */
    long cc_number;
    do
    {
        cc_number = get_long("Credit card number: ");
    }
    while (cc_number <= 0);
    
    /* Declare required variables: */
    long temp = cc_number;
    int previous_digit, current_digit;
    int sum_even = 0, sum_odd = 0;
    int i = 0, is_valid = 0;

    /* Go through the card number and add the digits for the checksum: */
    while (temp > 0)
    {
        previous_digit = current_digit;
        current_digit = temp % 10;
        temp = roundl(temp / 10);

        /* Handle even and odd digits: */ 
        if (i % 2 == 0)
        {
            sum_even = sum_even + current_digit;
        }
        else if (current_digit < 5)
        {
            sum_odd = sum_odd + current_digit * 2; 
        }
        else
        {
            sum_odd = sum_odd + (current_digit * 2 - 10 + 1); 
        }

        i++; 
    }

    /* Wrapping up the validation: */
    int first_digit = current_digit; 
    int second_digit = previous_digit; 
    int checksum = sum_odd + sum_even; 

    /* CHECKSUM: */
    if (checksum % 10 == 0)
    {
        is_valid = 1; 
    }
    else 
    {
        is_valid = 0;
    }

    /*Print preliminary results: */
    printf("  1st digit: %i\n", first_digit);
    printf("  2nd digit: %i\n", second_digit);
    printf("  Number of digits: %i\n", i);
    printf("  Sum even: %i\n", sum_even);
    printf("  Sum odd: %i\n", sum_odd);
    printf("  Checksum: %i\n\n", checksum);

    /*Print card type: */
    if (i < 13 || is_valid == 0)
    {
        printf("INVALID\n");
    }
    else if ((i == 13 || i == 16) && (first_digit == 4))
    {
        printf("VISA\n");
    }
    else if ((i == 16) && (first_digit = 5) && (second_digit > 0) && (second_digit < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((i == 15) && (first_digit == 3) && (second_digit == 4 || second_digit == 7))
    {
        printf("AMEX\n");
    }
    else 
    {
        printf("INVALID\n");
    }
}
