#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main (int argc, string argv[])
{
    // Read the command line argument, there should be only one
    if (argc == 2)
    {
        int arg_len = strlen(argv[1]);

        // Check if each character of the argument is decimal digit
        // by using a do while loop
        bool non_digit_flag = 0;
        int i = 0;
        do
        {
            if (isdigit(argv[1][i]) == 0)
            {
                non_digit_flag = 1;
                printf("Usage: ./caesar key\n");
                return 1;
            }

            i++;
        }
        while(i < arg_len);


        // if non digit flag is still false then continue the program
        if (non_digit_flag == 0)
        {
            int key = atoi(argv[1]);

            string plain_text = get_string("plaintext: ");

            // Getting the length of the input text in order to
            // iterate over it using a for loop
            int plain_text_len = strlen(plain_text);
            printf("ciphertext:");
            for (int j = 0; j < plain_text_len; j++)
            {
                // Check to see if the current char is a space
                // in order keep the structure of the plain text
                if (isspace(plain_text[j]) != 0)
                {
                    printf("%c", plain_text[j]);
                }

                // Check if current  character is a punctuation
                else if (isalpha(plain_text[j]) == 0)
                {
                    printf("%c", plain_text[j]);
                }

                else
                {
                    // Check if current character is uppercase
                    if (isupper(plain_text[j]) != 0)
                    {
                        // Check if current character + key exceeds the last
                        // character 'Z', if yes use modulo
                        if ((plain_text[j] + key) - 'Z' > 0)
                        {
                            int new_key = key % 26;

                            if (plain_text[j] + new_key > 'Z')
                            {
                                // If new_key + currenct character exceed 'Z'
                                // then subtract 26 to find the corresponding
                                // alpha character
                                printf("%c", plain_text[j] + new_key - 26);
                            }

                            else
                            {
                                printf("%c", plain_text[j] + new_key);
                            }

                        }

                        else
                        {
                            printf("%c", plain_text[j] + key);
                        }
                    }

                    // if current character is not uppercase than it is lowercase
                    else
                    {
                        if ((plain_text[j] + key) - 'z' > 0)
                        {
                            int new_key = key % 26;
                            if (plain_text[j] + new_key > 'z')
                            {

                                // If new_key + currenct character exceed 'z'
                                // then subtract 26 to find the corresponding
                                // alpha character
                                printf("%c", plain_text[j] + new_key - 26);
                            }

                            else
                            {
                                printf("%c", plain_text[j] + new_key);
                            }
                        }

                        else
                        {
                            printf("%c", plain_text[j] + key);
                        }
                    }

                }
            }

            printf("\n");

        }

    }

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
