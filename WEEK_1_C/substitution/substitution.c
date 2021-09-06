#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int input_check_of_alphabet(string alphabet);
string transform_plaintext_to_ciphertext(string plaintext, string alphabet);

int main(int argc, string argv[])
{
    string plaintext;
    int check_return;

    if (argc == 2)
    {
        string alphabet = argv[1];
        if (input_check_of_alphabet(alphabet) != 1)
            return (0);
        plaintext = get_string("plaintext: ");
        printf("ciphertext: %s\n", transform_plaintext_to_ciphertext(plaintext, alphabet));
    }
    else
        printf("Usage: ./substitution key\n");
}

int input_check_of_alphabet(string alphabet)
{
    int len_of_alphabet = strlen(alphabet);
    if (len_of_alphabet != 26)
    {
        printf("Key must contain 26 characters.\n");
        return(0);
    }
    int i = 0;
    while (i < len_of_alphabet)
    {
        if (isalpha(alphabet[i]) == 0)
            return(0);
        i++;
    }

    int j = 0;
    int k = 1;

    while (j < len_of_alphabet)
    {
        k = j + 1;
        while (k < len_of_alphabet)
        {
            if (toupper(alphabet[j]) == toupper(alphabet[k]))
                return(0);
            k++;
        }
        j++;
    }
    return(1);
}

string transform_plaintext_to_ciphertext(string plaintext, string alphabet)
{
    int len_of_plaintext = strlen(plaintext);
    int len_of_alphabet = strlen(alphabet);
    int i = 0;
    int is_alfa = isalpha(plaintext[i]);
    string ciphertext = plaintext;

    while (i < len_of_plaintext)
    {
        if (isalpha(plaintext[i]) == 0)
            ciphertext[i] = plaintext[i];
        else if (isupper(plaintext[i]) == 0) //not upper
        {
            int a = plaintext[i] - 'a';
            ciphertext[i] = alphabet[a];
        }
        else // upper
        {
            int a = plaintext[i] - 'A';
            ciphertext[i] = alphabet[a];
        }
        i++;
    }
    return(ciphertext);
}
