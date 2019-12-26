/*
This is a small C program written for the Week 2 assignment of CS50
It computes the approximate grade level needed to comprehend some text.
*/


#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);
float calculate_index(float L, float S);

int main(void)
{
    string text = get_string("Text: ");

    int letter_count = count_letters(text);
    int word_count = count_words(text);
    int sentence_count = count_sentences(text);

    // Calculate letters per 100 words and sentence per 100 words
    float L = (letter_count * 100) / word_count;
    float S = (sentence_count * 100) / word_count;

    float index = calculate_index(L, S);

    printf("Grade %.0f\n", index);



}

// Count the letters in a given string
int count_letters(string s)
{
    int letter_count = 0;
    int length_of_s = strlen(s);
    for (int i = 0; i < length_of_s; i ++)
    {
        // If s[i] is a char increase the letter count
        if (isalpha(s[i]) != 0)
        {
            letter_count+= 1;
        }
    }
    return letter_count;
}


// Count the words in a given string
int count_words(string s)
{
    int word_count = 0;
    int length_of_s = strlen(s);

    for (int i = 0; i < length_of_s; i++)
    {
        // If s[i] is a space it means that we just passed a word
        // so increase the word count
        if (isspace(s[i]) != 0)
        {
            word_count += 1;
        }
    }

    // Add an extra one for the last word before the text ends.
    word_count += 1;
    return word_count;
}

// Count the sentences in a given string
int count_sentences(string s)
{
    int sentence_count = 0;
    int length_of_s = strlen(s);

    // If a sequence ends with '.', '!' or '?' then we increase sentence count
    for (int i = 0; i < length_of_s; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentence_count += 1;
        }
    }

    return sentence_count;
}

// Calculate The Coleman-Liau index
float calculate_index(float L, float S)
{
    float index = 0.0588 * L - 0.296 * S - 15.8;
    float rounded_index = round(index);
    return rounded_index;
}
