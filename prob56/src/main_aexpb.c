/*
** PERSONAL PROJECT, 2019
** factorial_computer
** File description:
** main factorial computer
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

char *my_infinmul(char *n1, char *n2);

static char *my_infinpow(uint a, uint b)
{
    char *tempa = my_utoa(a);
    char *tempres = NULL;
    char *res = NULL;

//    printf("Calculating %i^%i\n", a, b);
    for (uint i = 0; i < b; i++) {
        tempres = my_infinmul(i ? res : tempa, tempa);
//        printf("%s*%u=%s\n", i ? res : tempa, b, tempres);
        free(res ? res : NULL);
        res = my_strdup(tempres);
        free(tempres ? tempres : NULL);
    }
//    printf("%i^%i=%s\n", a, b, res);
    free(tempa);
    return (res);
}

static void aexp_loop(uint limit)
{
    int max = 0;
    int tempmax = 0;
    char *res = NULL;

    for (uint i = 1; i < limit; i++)
        for (uint j = 1; j < 100; j++) {
            free(res ? res : NULL);
            res = my_infinpow(i, j);
            for (uint k = 0; res[k]; k++)
                tempmax += ctoi(res[k]);
            if (max < tempmax) {
                printf("New record! S(%u^%u) = %i\n", i, j, tempmax);
                max = tempmax;
            }
            tempmax = 0;
        }
    for (uint i = 0; res[i]; i++)
        tempmax += ctoi(res[i]);
    free(res ? res : NULL);
    if (max < tempmax)
        max = tempmax;
    printf("Result = %i\n", max);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        printf("USAGE\n\t./aexpb [limit > 1]\n");
        return (FAILURE);
    }
    if (my_atoi(av[1]) < 2) {
        printf("USAGE\n\t./aexpb [limit > 1]\n");
        return (FAILURE);
    }
    if (my_getnbr(av[1]) == 0)
        printf("0! = 1\n\nSum of the digits of 0! : 1\n");
    else
        aexp_loop(my_getnbr(av[1]));
    return (SUCCESS);
}
