/*
** PERSONAL PROJECT, 2022
** pow
** File description:
** main
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

/* 10^x cannot be solution as it will always be (n+1)--sized. */

static bool ndig_solution_exists(uint nb, uint *res)
{
    char *tmpi = NULL, *tmpn = NULL, *tmpr = NULL;

    for (uint i = 1; i < 10; i++) {
        tmpi = my_itoa(i); tmpn = my_itoa(nb);
        tmpr = my_infinpow(tmpi, tmpn);
        (*res) += (my_strlen(tmpr) == nb);
        free(tmpi); free(tmpn); free(tmpr);
    }
    return false;
}

static int power(uint limit)
{
    uint res = 0;

    for (uint i = 1; i <= limit; i++)
        ndig_solution_exists(i, &res);
    printf("Result = %i.\n", res);
    return SUCCESS;
}

/* a solution cannot be found over n=21 since (9^x)'s size grows smaller than x after n=21. */

int main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && (my_atoi(av[1]) <= 0 || my_atoi(av[1]) > 21))) {
        printf("USAGE\n\t%s [0 < limit <= 21]\n", av[0]);
        return FAILURE;
    }
    return power(my_atoi(av[1]));
}
