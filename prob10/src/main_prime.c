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

int main(void)
{
    long res = 2;

    printf("This solution takes around 9 minutes...\n");
    for (int nb = 1999999; nb > 1; nb -= 2)
        if (my_is_prime(nb))
            res += nb;
    printf("S(P(x < 2,000,000)) = %li\n", res);
    return (SUCCESS);
}
