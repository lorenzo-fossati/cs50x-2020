#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    /* Collect user input: */
    float change_in_dollars;
    do
    {
        change_in_dollars = get_float("How much change, in dollars, do you owe the customer? ");
    }
    while (change_in_dollars <= 0); 
    
    /* Convert user input: */
    int change_in_cents = round(change_in_dollars * 100);
    printf("  Change owed: %i cents\n", change_in_cents);
    
    /* Declare required variables: */
    int still_owed = change_in_cents; 
    int used_25 = 0, used_10 = 0, used_5 = 0, used_1 = 0; 
    int used_coins = 0; 

    /* Calculate how much coins of each type are used: */
    while (still_owed > 0)
    {
        if (still_owed - 25 >= 0)
        {
            still_owed = still_owed - 25; 
            used_25++;
        }
        else if (still_owed - 10 >= 0)
        {
            still_owed = still_owed - 10; 
            used_10++;
        }
        else if (still_owed - 5 >= 0)
        {
            still_owed = still_owed - 5; 
            used_5++;
        }
        else if (still_owed - 1 >= 0)
        {
            still_owed = still_owed - 1; 
            used_1++;
        }
        else
        {
            printf("...have I made a mistake? 😕\n");
        }
        used_coins++;
    }

    /* Print an intermediate check: */
    printf("  Coins to return: ");
    printf("%i x 25 cents + ", used_25);
    printf("%i x 10 cents + ", used_10);
    printf("%i x 5 cents + ", used_5);
    printf("%i x 1 cents\n", used_1);

    /* Print the output: */
    printf("Total coins used: \n");
    printf("%i\n", used_coins);
}
