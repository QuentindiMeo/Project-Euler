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

static int fac(int i)
{
    if (i == 0) return 1;
    return i * fac(i - 1);
}
static void push(char **stk, char *n)
{
    if (!stk[0]) {
        stk[0] = my_strdup(n);
        return;
    }
    for (uint i = 0; stk[i]; i++)
        if (stk[i + 1] == NULL) {
            stk[i + 1] = my_strdup(n);
            return;
        }
}

static char *addfac(char *tmpi, int *fax)
{
    uint res = 0;

    for (uint i = 0; tmpi[i]; i++)
        res += fax[tmpi[i] - '0'];
    return my_itoa(res);
}

static bool matches_pattern(uint n, uint repeat)
{
    char **stk = malloc(sizeof(char *) * (repeat + 2));
    char *tmpi = my_itoa(n), *tmpn = NULL;
    int fax[10] = {fac(0), fac(1), fac(2), fac(3), fac(4), fac(5), fac(6), fac(7), fac(8), fac(9)};
    bool res;

    for (uint i = 0; i <= repeat + 1; i++) stk[i] = NULL;
    push(stk, tmpi);
    do {
        tmpn = addfac(tmpi, fax);
        if (my_str_isinarray(stk, tmpn)) { free(tmpn); break; }
        else            push(stk, tmpn);
        free(tmpi); tmpi = my_strdup(tmpn); free(tmpn);
    } while (!stk[repeat]);
    free(tmpi);
    res = (stk[repeat - 1] && !stk[repeat]);
    free_str_array(stk);
    return res;
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
