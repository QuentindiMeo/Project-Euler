/*
** EPITECH PROJECT, 2018
** CPE_solostumper_2_2018
** File description:
** palindrome main
*/

#include "my.h"
#include "palindrome.h"

static int is_letter(char const c)
{
    if (c >= 'A' && c <= 'Z')
        return (UPPERCASE);
    if (c >= 'a' && c <= 'z')
        return (LOWERCASE);
    return (FALSE);
}

static int str_i_equals_its_symmetric(char c1, char c2)
{
    if (is_letter(c1) == UPPERCASE)
        c1 += 32;
    if (is_letter(c2) == UPPERCASE)
        c2 += 32;
    if (c1 == c2)
        return (TRUE);
    return (FALSE);
}

int is_palindrome(char const *str)
{
    uint check = 0;
    uint cursor = my_strlen(str);

    cursor--;
    for (uint i = 0; str[i]; i++) {
        if (str_i_equals_its_symmetric(str[i], str[cursor]))
            check++;
        cursor--;
    }
    if (check == my_strlen(str))
        return (YES);
    return (NO);
}
