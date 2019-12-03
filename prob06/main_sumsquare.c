/*
** PERSONAL PROJECT, 2019
** sumsquare
** File description:
** main sumsquare
*/

#include <stdio.h>
#include "my.h"

static int get_res(uint natural)
{
    int sum = 0;
    int tempsum = 0;
    int square = 0;

    for (uint i = 1; i <= natural; i++)
        sum += my_compute_power_rec(i, 2);
    for (uint i = 1; i <= natural; i++)
        tempsum += i;
    square = my_compute_power_rec(tempsum, 2);
    return (square - sum);
}

int main(int ac, char **av)
{
    int i;
    int res;

    if (ac != 2) {
        printf("USAGE\n\t./sumsquare [x natural numbers]\n");
        return (FAILURE);
    }
    if (my_atoi(av[1]) < 0) {
        printf("USAGE\n\t./sumsquare [x natural numbers]\n");
        return (FAILURE);
    }
    i = my_atoi(av[1]);
    res = get_res(i);
    printf("Difference for first %d natural numbers: %i\n", i, res);
    return (SUCCESS);
}
