/*
** PERSONAL PROJECT, 2019
** fibonacci
** File description:
** main fibonacci
*/

#include <stdio.h>
#include "my.h"

static void fibonacci_loop(int limit)
{
    int n3 = 0;
    int n2 = 1;
    int n1 = 0;
    int res = 0;

    while (n3 < limit) {
        n3 = n2 + n1;
        n1 = n2;
        n2 = n3;
        if (n3 % 2 == 0)
            res += n3;
    }
    printf("S%d(even) = %i\n", limit, res);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        printf("USAGE\n\t./fib [limit]\n");
        return (FAILURE);
    }
    if (my_atoi(av[1]) < 0) {
        printf("USAGE\n\t./fib [limit]\n");
        return (FAILURE);
    }
    if (my_getnbr(av[1]) == 0)
        printf("S0(even) = 0\n");
    fibonacci_loop(my_atoi(av[1]));
    return (SUCCESS);
}
