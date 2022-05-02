/*
** PERSONAL PROJECT, 2019
** prime
** File description:
** main prime
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int my_is_prime(int nb);

int summation(int limit)
{
    long res = 2;

    for (int nb = (limit % 2 ? limit : limit - 1); nb > 1; nb -= 2)
        res += (nb * (my_is_prime(nb)));
    printf("S(P(x < 2,000,000)) = %li\n", res);
    return SUCCESS;
}

int main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && (atoi(av[1]) < 11 || atoi(av[1]) > 9999999))) {
        printf("USAGE\n\t%s [10 < limit <= 9999999]\n", av[0]);
        return FAILURE;
    }
    return summation(atoi(av[1]));
}
