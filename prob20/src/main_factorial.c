/*
** PERSONAL PROJECT, 2019
** factorial_computer
** File description:
** main factorial computer
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

char *my_infinmul(char *n1, char *n2);

static void facto_loop(uint limit)
{
    char *res = strdup("1");
    char *nb = NULL;
    char *nthh = NULL;
    int ress = 0;
    uint nth = 1;

    printf("%u! = %s\n", 0, res);
    for (; nth != limit + 1; nth++) {
        nthh = my_utoa(nth);
        nb = my_infinmul(res, nthh);
        free(res);
        res = strdup(nb);
        free2(nthh, nb);
        printf("%u! = %s\n", nth, res);
    }
    for (uint i = 0; i < strlen(res); i++)
        ress += (res[i] - 48);
    printf("\nSum of the digits of %u! : %i\n", nth - 1, ress);
    free(res);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        printf("USAGE\n\t./factorial [limit]\n");
        return (FAILURE);
    }
    if (my_atoi(av[1]) < 0) {
        printf("USAGE\n\t./factorial [limit]\n");
        return (FAILURE);
    }
    if (my_getnbr(av[1]) == 0)
        printf("0! = 1\n\nSum of the digits of 0! : 1\n");
    else
        facto_loop(my_getnbr(av[1]));
    return (SUCCESS);
}
