#include <cs50.h>
#include <stdio.h>

int main(void)
{
    /* Declare the required variables: */
    int height;
    int i, j, k;

    /* Collect and validate the input from the user: */
    do
    {
        height = get_int("How tall should the obstacle be?\n Enter a value between 1 and 8 included: ");
    }
    while ((height < 1) || (height > 8));

    /* Print spaces and hashes according to the user input: */
    for (i = 0;  i < height; i++)
    {
        /* Update row count: */ 
        int row_index = i + 1;

        /* Print enough spaces: */ 
        for (j = 0;  j < height - row_index; j++)
        {
            printf(" ");
        }

        /* Print enough hashes: */ 
        for (k = 0;  k < row_index; k++)
        {
            printf("#");
        }

        /* Print a newline: */ 
        printf("\n");
    }
}
