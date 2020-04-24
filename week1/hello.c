#include <cs50.h>
#include <stdio.h>

int main(void)
{
    /* Collect input from the user: */
    string username = get_string("What is your name? ");

    /* Construct and print the output: */
    printf("Hello, %s!\n", username);
}
