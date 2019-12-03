/*
** PERSONAL PROJECT, 2019
** prime
** File description:
** main prime
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

int my_is_prime(int nb);

int main(void)
{
    long res = 0;

    for (int nb = 2000000; nb > 1; nb--)
        if (my_is_prime(nb))
            res += nb;
    printf("S(P(x < 2,000,000)) = %li\n", res);
    return (SUCCESS);
}
