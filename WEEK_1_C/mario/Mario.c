#include <stdio.h>
#include "../../cs50.h"

int get_needed_int();
void print_n_symbols(int n, char c);


//void print_spaces(int c_sp);
//void print_sharp(int l);
//void print_two_spaces();
//void print_next_line();

int main(void)
{
    int l = 1;
    int h = get_needed_int();
    while (l <= h)
    {
        print_n_symbols(h - l, ' ');
        print_n_symbols(l, '#');
        print_n_symbols(2, ' ');
        print_n_symbols(l, '#');
        print_n_symbols(1, '\n');

        // print_spaces(h - l);
        // print_sharp(l);


        // print_two_spaces();


        //  print_sharp(l);


        //  print_next_line();
        l++;
    }
}

int get_needed_int(void)
{
    int h;

    do
    {
        h = get_int("HEIGHT: ");
    } while (h < 1 || h > 8);
    return h;
}

void print_n_symbols(int n, char c)
{
    while (n > 0)
    {
        printf("%c", c);
        n--;
    }
}

/*
void print_spaces(int c_sp)
{
    char sp = ' ';

    while (c_sp > 0)
    {
        printf("%c", sp);
        c_sp--;
    }
}

void print_sharp(int l)
{
    char sh = '#';

    while (l >= 1)
    {
        printf("%c", sh);
        l--;
    }
}

void print_two_spaces()
{
    printf("%s", "  ");
}

void print_next_line()
{
    printf("%s", "\n");
}
*/
