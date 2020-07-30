/*
** PERSONAL PROJECT, 2019
** amicable
** File description:
** main amicable
*/

#include <stdio.h>
#include "my.h"

static int get_sum_prop_div(int nb)
{
    uint res = 0;

    for (int i = 1; i < nb; i++)
        if (nb % i == 0)
            res += i;
    return (res);
}

static void amicable(int limit)
{
    uint res = 0;

    for (int nb = 1; nb < limit; nb++)
        if (nb == get_sum_prop_div(get_sum_prop_div(nb)))
            if (nb != get_sum_prop_div(nb)) {
                printf("Works for %d (%d)\n", nb, get_sum_prop_div(nb));
                res += nb;
            }
    printf("S(A(n)) for n < %d: %i\n", limit, res);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        printf("USAGE\n\t%s [0 < limit <= 10000]\n", av[0]);
        return (FAILURE);
    }
    if (my_atoi(av[1]) < 0 || my_atoi(av[1]) >= 100000) {
        printf("USAGE\n\t%s [0 < limit <= 10000]\n", av[0]);
        return (FAILURE);
    }
    amicable(my_atoi(av[1]));
    return (SUCCESS);
}
