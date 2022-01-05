#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define BETWEEN(value, min, max) (value < max && value > min)

int main(int argc, char *argv[])
{
    char *key = argv[1];
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int i = 0;
    while (isdigit(argv[1][i]))
    {
        i++;
    }

    if (argv[1][i] != '\0')
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        string text = get_string("plaintext:  ");  // Prompt user for a plain text
        int keys = atoi(key);
        
    // Cipher plain text
    printf("ciphertext: ");
    for (int j = 0; j < strlen(text); j++)
    {
        int a;
        a = (int)text[j];
        
        if(BETWEEN(a, 64, 91))
        {
            a = a + keys;
            while(a > 90)
            {
                a = a - 26;
            }
            printf("%c", (char)a);
        }
        else if(BETWEEN(a, 96, 123))
        {
            a = a + keys;
            while(a > 122)
            {
                a = a - 26;
            }
            printf("%c", (char)a);
        }
        else
        {
            printf("%c", (char)a);
        }
    }
    printf("\n");
    }
}
