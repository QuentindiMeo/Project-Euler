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
    if (!(n % 20) && !(n % 19) && !(n % 18) && !(n % 17) && !(n % 16) &&
        !(n % 15) && !(n % 14) && !(n % 13) && !(n % 12) && !(n % 11))
            return (TRUE);
    return (FALSE);
}

int main(void)
{
    int i = 20;

    for (; 1; i += 20)
        if (mod_is_zero(i))
            break;
    printf("Smallest multiple: %i\n", i);
    return (SUCCESS);
}
