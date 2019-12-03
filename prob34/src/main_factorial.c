/*
** PERSONAL PROJECT, 2019
** factorial_computer
** File description:
** main factorial computer
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

int my_compute_factorial_rec(int nb);

static int is_digit_facto(int nth)
{
    char *nb = my_itoa(nth);
    int tmp = 0;

    for (int i = 0; nb[i]; i++)
        tmp += my_compute_factorial_rec(ctoi(nb[i]));
    free(nb);
    if (tmp == nth) {
        printf("Works for %i\n", nth);
        return (YES);
    }
    return (NO);
}

static int facto_loop(uint limit)
{
    int res = 0;
    uint nth = 3;

    if (limit < 2) {
        printf(" USAGE\n\t./factorial [max n to compute; n > 1]\n");
        return (FAILURE);
    }
    for (; nth != limit + 1; nth++) {
        if (is_digit_facto(nth))
            res += nth;
    }
    printf("%cResult : %i\n", res ? '\n' : '\0', res);
    return (SUCCESS);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        printf(" USAGE\n\t./factorial [max n to compute; n > 1]\n");
        return (FAILURE);
    }
    return (facto_loop(my_atoi(av[1])));
}
