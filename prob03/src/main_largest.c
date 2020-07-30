/*
** PERSONAL PROJECT, 2019
** largest
** File description:
** main largest
*/

#include <stdio.h>
#include "my.h"

int my_is_prime(long nb);

static void largest(void)
{
    long large;

    for (long i = 1; i < 600851475143; i++) {
        large = 600851475143 / i;
        if (600851475143 % large == 0 && my_is_prime(large))
            break;
    }
    printf("Largest prime factor of %li: %li\n", 600851475143, large);
}

int main(void)
{
    largest();
    return (SUCCESS);
}
