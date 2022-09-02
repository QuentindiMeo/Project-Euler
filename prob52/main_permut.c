/*
** PERSONAL PROJECT, 2022
** permut
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static int *get_digits(char *nb)
{
    int *res = malloc(sizeof(int) * 10);

    for (int i = 0; i < 10; i++)
        res[i] = 0;
    for (int i = 0; nb[i]; i++)
        res[ctoi(nb[i])]++;
    free(nb);
    return res;
}

static int try_number(int nb, int multi)
{
    int *ref = get_digits(my_itoa(nb)), *tmp = NULL;

    for (int i = 2; i <= multi; i++, free(tmp)) {
        tmp = get_digits(my_itoa(nb * i));
        for (int j = 0; j < 10; j++)
            if (tmp[j] != ref[j]) {
                free(ref); free(tmp);
                return FAILURE;
            }
    }
    free(ref);
    printf("Found %d:", nb);
    for (int i = 0; i < multi; i++)
        printf(" %d", nb * (i + 1));
    printf("\n");
    return SUCCESS;
}

static int permut(int multi)
{
    for (int i = 123456; i < 111111111; i++)
        if (!try_number(i, multi))
            return SUCCESS;
    printf("No solution found\n");
    return FAILURE;
}

int main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && (my_atoi(av[1]) <= 1 && my_atoi(av[1]) > 9))) {
        printf("USAGE\n\t%s [1 < multi < 10]\n", av[0]);
        return FAILURE;
    }
    return permut(my_atoi(av[1]));
}
