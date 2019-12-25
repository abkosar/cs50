#include <stdio.h>
#include <cs50.h>
#include <math.h>

/*
This is a small C program that identifies
if a credit card number is valid or not using Luhn's 
algorithm. It is only implemented for limited credit card types
since it's just an assigment for CS50 class
*/

int main(void)
{
    long card_number = get_long("Number:");
    long card_number_copy = card_number;
    // Digit count is to keep track of which digit 
    // I am currently on
    long digit_count = 0;
    
    // even_sum and odd_sum are the sums for even digits
    // and odd digits
    long even_sum = 0;
    long odd_sum = 0;
    
    while (card_number_copy >= 1)
    { 
        long remainder = card_number_copy % 10;
        card_number_copy = card_number_copy / 10;
        
        // If digit count is even then add it to the even_sum
        if  (digit_count % 2 == 0)
        {
            even_sum += remainder;
        }
        
        // If digit count is odd, multiply the digit by 2
        // check if it is a single or double digit number
        // if single add it to the odd_sum, if not first 
        // seperate it to its digits.
        else 
        {
            long multiplied = remainder * 2;
            
            if (multiplied >= 10) 
            {
                long digit_sum = (multiplied / 10) + (multiplied % 10);
                odd_sum += digit_sum;
            }
            
            else 
            {
                odd_sum += multiplied;
            }
        }
        
        digit_count += 1; 
    }
    
    // Finding the total sum of digits
    long total_sum = even_sum + odd_sum;
    
    // Find the first and second digits 
    long first_digit_power = pow(10, digit_count-1);
    long first_digit = (card_number / first_digit_power) % 10;
    
    long second_digit_power = pow(10, digit_count-2);
    long second_digit = (card_number / second_digit_power) % 10;
    
    long first_two_digits = first_digit * 10 + second_digit;
    
    if (total_sum % 10 == 0) 
    {
        if (first_two_digits == 34 || first_two_digits == 37) 
        {
            printf("AMERICAN EXPRESS\n");
        }
        else if (first_digit == 4) 
        {
            printf("VISA\n");
        }
        else if (first_two_digits >= 51 || first_two_digits <= 55)  
        {
            printf("MASTERCARD\n");
        }
        
    }
    else 
    {
        printf("INVALID\n");
    }
    
}
