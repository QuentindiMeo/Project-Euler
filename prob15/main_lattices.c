/*
** PERSONAL PROJECT, 2022
** lattices
** File description:
** main 
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static char *calcfac(uint s, uint e)
{
    char *res = NULL, *str = NULL, *tmpres = my_strdup("1");

    for (uint i = s; i <= e; i++) {
        str = my_renew(str, my_itoa(i));
        res = my_renew(res, my_infinmul(tmpres, str));
        if (i == e) break;
        tmpres = my_renew(tmpres, my_strdup(res));
    }
    free(str); free(tmpres);
    return res;
}

static char *k_in_n(uint k, uint n)
{
    char *nomin = calcfac(k + 1, n), *denom = calcfac(1, k);
    char *res = my_infindiv(nomin, denom, false);

    free(nomin); free(denom);
    return res; // simplified calculation because n = 2k
}

static int lattices(int limit)
{
    char *res = k_in_n(limit, limit * 2);

    printf("Routes through a %i*%i grid: %s\n", limit, limit, res);
    free(res);
    return SUCCESS;
}

int main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && (my_atoi(av[1]) < 1 || my_atoi(av[1]) > 600))) {
        printf("USAGE\n\t%s [0 < limit <= 600]\n", av[0]);
        return FAILURE;
    }
    return lattices(my_atoi(av[1]));
}
