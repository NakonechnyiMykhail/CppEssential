#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// int main(int argc, char* argv[])
int main(int argc, string argv[])
{
    /*
    Usage: 
    ./caesar 4
    plaintext:\t 
    ciphertext:\t
    */
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // get argument as key from command-line and move to integer
    int k = atoi(argv[1]); // ascii to integer
    if (k < 0 || k < 1000) // 1000 -> length of alphabet
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (argv[1][i] > 57 || argv[1][i] < 48)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    string text = get_string("plaintext:\t");
    char ciphertext[strlen(text)];
    printf("ciphertext:\t");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isupper(text[i]))
        {
            text[i] = text[i] - 65;
            ciphertext[i] = (text[i] + k) % 26 + 65;
            printf("%c", ciphertext[i]);
        }
        else if (islower(text[i]))
        {
            text[i] -= 97;
            ciphertext[i] = (text[i] + k) % 26 + 97;
            printf("%c", ciphertext[i]);
        }
        else if (isdigit(text[i]))
        {
            text[i] -= 48;
            ciphertext[i] = (text[i] + k) % 10 + 48;
            printf("%c", ciphertext[i]);
        }
        else 
        {
            ciphertext[i] = text[i];
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");

    return 0;
}