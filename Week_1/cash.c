#include <stdio.h>
#include <cs50.h>
#include <math.h>

/*
This is a small C program that asks
the user how much change is owed and 
calculates the minimum number of coins
with which that change can be made
*/

int main(void)
{
    float change = 0;
    
    do
    {
        change = get_float("Change owed:\n");
    }
    while(change < 0);
    
    int change_in_cents = round(change*100);
    
    int number_of_coins = 0;
    
    while (change_in_cents - 25 >= 0)
    {
        change_in_cents -= 25;
        number_of_coins += 1;
    }
    
    while (change_in_cents - 10 >= 0)
    {
        change_in_cents -= 10;
        number_of_coins += 1;
    }
    
    while (change_in_cents - 5 >= 0)
    {
        change_in_cents -= 5;
        number_of_coins += 1;
    }
    
    while (change_in_cents - 1 >= 0)
    {
        change_in_cents -= 1;
        number_of_coins += 1;
    }
    
    printf("%d\n", number_of_coins);
       
}

