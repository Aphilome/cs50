#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

int calc_letters(string str, int len);
int calc_words(string str, int len);
int calc_sentences(string str, int len);

int main()
{
    string str = get_string("Text: ");
    int len = strlen(str);
    int count_of_letters = calc_letters(str, len);
    printf("Count of letter(s) = %i\n", count_of_letters);
    int count_of_words = calc_words(str, len);
    printf("Count of word(s) = %i\n", count_of_words);
    int count_of_sentences = calc_sentences(str, len);
    printf("Count of sentence(s) = %i\n", count_of_sentences);
    float L = count_of_letters * 100.0 / count_of_words;
    printf("L = %f\n", L);
    float S = count_of_sentences * 100.0 / count_of_words;
    printf("S = %f\n", S);
    float Coleman_Liau_index = 0.0588 * L - 0.296 * S - 15.8;
    int result_Coleman_Liau_index = round(Coleman_Liau_index);
    if (Coleman_Liau_index < 1)
        printf("Before Grade 1");
    else if (Coleman_Liau_index >= 16)
        printf("Grade 16+");
    else
        printf("Grade %i\n", result_Coleman_Liau_index);
}

int calc_letters(string str, int len)
{
    int i = 0;
    int count = 0;

    while (i < len)
    {
        if (isalnum(str[i]) != 0)
            count++;
        i++;
    }
    return (count);
}

int calc_words(string str, int len)
{
    int i = 0;
    int count = 1;

    while (i < len)
    {
        if (str[i] == ' ')
            count++;
        i++;
    }
    return (count);
}

int calc_sentences(string str, int len)
{
    int i = 0;
    int count = 0;

    while (i < len)
    {
        if (str[i] == '.' || str[i] == '?' || str[i] == '!')
            count++;
        i++;
    }
    return (count);
}
