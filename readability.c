#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define BETWEEN(value, min, max) (value < max && value > min)

int countletters(string text);
int countwords(string text);
int countsentence(string text);

int main(void)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;


    string text = get_string("Text: ");

    // Turns string to an uppercase
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        text[i] = text[i] - 32;
    }
    // Count all the variables
    letters = countletters(text);
    words = countwords(text);
    sentences = countsentence(text);

    // Count Index
    int L = (letters * 100) / words;
    int S = (sentences * 100) / words;
    
    float index = 0.0588 * L - 0.296 * S - 15.84;
    index = round(index);
    int a = (int)index;
    
    if (index < 1)
    printf("Before Grade 1\n");
    else if (index < 16)
    printf("Grade %i\n", a);
    else
    printf("Grade 16+\n");
}

// Count the letters
int countletters(string text)
{
    int b = 0;
    for (int s = 0; s <strlen(text); s++)
    {
        int a = text[s];
        if (BETWEEN(a, 64, 91) && a != 32)
        b = b + 1;
    }
    return b;
}

// Count the words
int countwords(string text)
{
    int b = 1;
    for (int s = 0; s <strlen(text); s++)
    {
        if (text[s] == ' ' && text[s-1] != ' ')
        b = b + 1;
    }
    return b;
}

// Count the sentences
int countsentence(string text)
{
    int b = 0;
    for (int s = 0; s <strlen(text); s++)
    {
        int a = text[s];
        if (a == 33 || a == 63 || a == 46)
        b = b + 1;
    }
    return b;
}

