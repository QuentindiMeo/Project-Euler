/*
** PERSONAL PROJECT, 2022
** facchain
** File description:
** main
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

#define LIMIT 1000000

static uint fac(uint i)
{
    if (i == 0) return 1;
    return i * fac(i - 1);
}
static uint addfac(int tmpi, int *fax)
{
    uint res = 0;

    for (; tmpi; tmpi /= 10)
        res += fax[tmpi % 10];
    return res;
}

/* allocating one more int to check whether it repeats EXACTLY x times. */

static bool matches_pattern(uint n, uint repeat)
{
    int *stk = malloc(sizeof(int) * (repeat + 1)); uint sz = 0;
    int tmpi = n, tmpn = 0;
    int fax[10] = {fac(0), fac(1), fac(2), fac(3), fac(4), fac(5), fac(6), fac(7), fac(8), fac(9)};

    for (uint i = 0; i <= repeat; i++) stk[i] = -1;
    stk[sz++] = n;
    do {
        tmpn = addfac(tmpi, fax);
        if (my_int_isinarray(stk, tmpn, sz)) break;
        else             stk[sz++] = tmpn;
        tmpi = tmpn;
    } while (stk[repeat - 1] == -1);
    free(stk);
    return sz == repeat;
}

static int facchain(int repeat)
{
    uint res = 0;

    for (uint i = 1; i < LIMIT; i++)
        res += matches_pattern(i, repeat);
    printf("%i number%s ha%s a %i-chain under %i.\n",
            res, res > 1 ? "s" : "", res > 1 ? "ve": "s", repeat, LIMIT);
    return (res ? SUCCESS : FAILURE);
}

int main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && (my_atoi(av[1]) <= 0 || my_atoi(av[1]) >= 100))) {
        printf("USAGE\n\t%s [0 < limit < 100]\n", av[0]);
        return FAILURE;
    }
    return facchain(my_atoi(av[1]));
}
