/*
** EPITECH PROJECT, 2018
** CPE_solostumper_2_2018
** File description:
** palindrome main
*/

#include "../include/my.h"
#include "../include/palindrome.h"

static int is_letter(const char c)
{
    if (c >= 'A' && c <= 'Z')
        return UPPERCASE;
    if (c >= 'a' && c <= 'z')
        return LOWERCASE;
    return FALSE;
}

static int str_i_equals_its_symmetric(char c1, char c2)
{
    if (is_letter(c1) == UPPERCASE)
        c1 += 32;
    if (is_letter(c2) == UPPERCASE)
        c2 += 32;
    return (c1 == c2);
}

int is_palindrome(const char *str)
{
    uint check  = 0;
    uint cursor = my_strlen(str) - 1;

    if (!str)
        return NO;
    for (uint i = 0; str[i]; i++) {
        if (str_i_equals_its_symmetric(str[i], str[cursor]))
            check++;
        cursor--;
    }
    return (check == my_strlen(str));
}
