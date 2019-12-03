/*
** PERSONAL PROJECT, 2019
** smallest
** File description:
** main smallest
*/

#include <stdio.h>
#include "my.h"

static int mod_is_zero(int n)
{
    if (n % 20 == 0 && n % 19 == 0 && n % 18 == 0 && n % 17 == 0 && n % 16 == 0
        && n % 15 == 0 && n % 14 == 0 && n % 13 == 0 && n % 12 == 0 &&
        n % 11 == 0 && n % 10 == 0)
        return (TRUE);
    return (FALSE);
}

int main(void)
{
    uint i = 20;

    for (; 1; i += 10)
        if (mod_is_zero(i))
            break;
    printf("Smallest multiple: %i\n", i);
    return (SUCCESS);
}
