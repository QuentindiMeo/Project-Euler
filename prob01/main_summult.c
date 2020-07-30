/*
** PERSONAL PROJECT, 2019
** summult
** File description:
** main summult
*/

#include <stdio.h>
#include "my.h"

static void summult_loop(uint limit)
{
    int res = 0;

    for (uint i = 0; i < limit; i++)
        if (i % 3 == 0 || i % 5 == 0)
            res += i;
    printf("S%d(3, 5) = %i\n", limit, res);
}

int main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && my_atoi(av[1]) < 0)) {
        printf("USAGE\n\t./summult [limit]\n");
        return (FAILURE);
    }
    if (my_atoi(av[1]) == 0)
        printf("S0(3, 5) = 1\n");
    else
        summult_loop(my_atoi(av[1]));
    return (SUCCESS);
}
