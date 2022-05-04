/*
** PERSONAL PROJECT, 2019
** factorial_computer
** File description:
** main factorial computer
*/

//#include <unistd.h>
//#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static void aexp_loop(uint limit)
{
    int max = 0, tempmax = 0;
    char *res = NULL, *tmp = NULL;

    for (uint i = 1; i < limit; i++) {
        if (i % 10 == 0) continue;
        tmp = my_utoa(i);
        for (uint j = 1; j < limit; j++, tempmax = 0) {
            res = my_infinpow(tmp, j);
            for (uint k = 0; res[k]; k++)
                tempmax += ctoi(res[k]);
            if (max < tempmax) {
                printf("New record: S(%u^%u) = %i\n", i, j, tempmax);
                max = tempmax;
            }
            if (i + 1 != limit && j + 1 != limit)
                free(res);
        }
        free(tmp);
    }
    for (uint i = 0; res[i]; i++)
        tempmax += ctoi(res[i]);
    free(res);
    if (max < tempmax)
        max = tempmax;
    printf("Result = %i\n", max);
}

int main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && my_atoi(av[1]) < 2)) {
        printf("USAGE\n\t./aexpb [limit > 1]\n");
        return (FAILURE);
    }
    if (my_atoi(av[1]) == 0)
        printf("0! = 1\n\nSum of the digits of 0! : 1\n");
    else
        aexp_loop(my_atoi(av[1]));
    return SUCCESS;
}
