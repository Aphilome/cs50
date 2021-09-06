#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cs50.h"

string get_credit_string();
int check_str(string s);
int find_sum_mult_digits(string s);
int find_sums(string s);

int main(void)
{
    string s;
    int is_exist_hyphen;
    do
    {
        s = get_credit_string();
        is_exist_hyphen = check_str(s);
    } while (is_exist_hyphen == 1);

    int sum1 = find_sum_mult_digits(s);
    int sum2 = find_sums(s);
    int sum = sum1 + sum2;
    int len = strlen(s);

    if (sum % 10 == 0)
    {
        if (s[0] == '3' && (s[1] == '4' || s[1] == '7') && len == 15)
        {
            printf("American Express");
        }

        if (s[0] == '5' && (s[1] == '1' || s[1] == '2' || s[1] == '3' || s[1] == '4' || s[1] == '5') && len == 16)
        {
            printf("MasterCard");
        }

        if (s[0] == '4' && (len == 13 || len == 14 || len == 15 || len == 16))
        {
            printf("Visa");
        }
    }
    else
    {
        printf("INVALID");
        exit(0);
    }
}

string get_credit_string()
{
    string s;
    int l;

    s = get_string("NUMBER: ");
    l = strlen(s);
    return s;
}

int check_str(string s)
{
    int i = 0;

    while (s[i] != 0)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            return 1;
        }
        i++;
    }
    return 0;
}

int find_sum_mult_digits(string s)
{
    int l = strlen(s);
    int sum = 0;
    int i = l / 2;

    while (i > 0)
    {
        char c = s[l - 2];
        int n = c - '0';
        n *= 2;
        if (n > 9)
        {
            sum = sum + (n / 10 + n % 10);
        }
        else
            sum = sum + n;
        l -= 2;
        i--;
    }
    return sum;
}

int find_sums(string s)
{
    int l = strlen(s);
    int sum = 0;
    int i = l / 2;

    while (l > 0)
    {
        char c = s[l - 1];
        int n = c - '0';
        sum = sum + n;
        l -= 2;
        i--;
    }
    return sum;
}
