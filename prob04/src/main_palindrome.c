/*
** PERSONAL PROJECT, 2019
** summult
** File description:
** main summult
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

int is_palindrome(char const *str);

int main(void)
{
    uint res = 0;
    char *temp = NULL;

    for (uint i = 1; i < 1000; i++)
        for (uint j = 1; j < 1000; j++) {
            temp = my_utoa(i * j);
            if (res < i * j && is_palindrome(temp))
                res = i * j;
            free(temp);
        }
    printf("Biggest (2, 3) palindrome: %i\n", res);
    return (SUCCESS);
}
