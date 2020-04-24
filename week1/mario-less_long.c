#include <cs50.h>
#include <stdio.h>

int collect_user_input(int min_height, int max_height);
void print_pyramid(int target_height);
int main(void)
{
    /* Hopefully self-explanatory: */ 
    int min = 1;
    int max = 8;
    int input_height = collect_user_input(min, max);
    print_pyramid(input_height);
}

int collect_user_input(min_height, max_height)
{
    /* Declare the required variables: */
    int target_height;

    /* Collect and validate the input from the user: */
    do
    {
        target_height = get_int("How tall should the obstacle be?\n Enter a value between %i and %i included: ", min_height, min_height);
    }
    while ((target_height < min_height) || (target_height > max_height));
    
    /* Return a validated integer: */
    return (target_height);
}

void print_pyramid(int target_height)
{
    /* Declare the required variables: */
    int i, j, k;

    /* Print spaces and hashes according to the user input: */
    for (i = 0;  i < target_height; i++)
    {
        /* Update row index: */ 
        int row_index = i + 1;

        /* Print enough spaces: */ 
        for (j = 0;  j < target_height - row_index; j++)
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
