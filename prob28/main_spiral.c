/*
** PERSONAL PROJECT, 2019
** spiral
** File description:
** main spiral
*/

#include <stdio.h>
#include "my.h"

static int spiral(int size)
{
    int res = 1;

    for (int i = 1; i < size; i++) {
        for (int counter = 1; counter <= 4; counter++) {
            res += my_compute_power_rec(i * 2 - 1, 2);
//            printf("%d + ", my_compute_power_rec(i * 2 - 1, 2));
            res += (2 * i * counter);
//            printf("%d\n", 2 * i * counter);
        }
    }
    return (res);
}

int main(int ac, char **av)
{
    int size;

    if (ac != 2) {
        printf("USAGE\n\t%s [0 < size < 1000]\n", av[0]);
        printf("\t'size' gives a spiral of side length 'size * 2 - 1'\n");
        return (FAILURE);
    }
    if (my_atoi(av[1]) <= 0 || my_atoi(av[1]) > 1000) {
        printf("USAGE\n\t%s [0 < size <= 1000]\n", av[0]);
        printf("\t'size' gives a spiral of side length 'size * 2 - 1'\n");
        return (FAILURE);
    }
    size = my_atoi(av[1]) * 2 - 1;
    printf("S(diag) for a %d*%d spiral: %i\n",
           size, size, spiral(my_atoi(av[1])));
    return (SUCCESS);
}
