/*
** PERSONAL PROJECT, 2022
** quadratic
** File description:
** main 
*/

#include <stdio.h>
#include "my.h"

static int my_is_prime(int nb)
{
    if (nb < 2) return FALSE;

    int nbb = 2;

    for (; nbb < nb && nb % nbb != 0; nbb++);
    return nbb == nb;
}

static int quadratic(int limit)
{
    int max = 0, res = 0;
    int resa, resb;

    for (int i = limit * (-1); i < limit; i++)
        for (int j = limit * (-1); j <= limit; j++, res = 0) {
            for (uint x = 0; my_is_prime(x * x + i * x + j); x++, res++);
            if (max < res) { max = res; resa = i; resb = j; }
        }
    printf("Longest chain is for a=%i and b=%i: %i\n", resa, resb, max);
    printf("a * b = %i * %i = %i\n", resa, resb, resa * resb);
    return max;
}

int main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && my_atoi(av[1]) >= 4242)) {
        printf("USAGE\n\t%s [0 < limit < 4242]\n", av[0]);
        return FAILURE;
    }
    quadratic(my_atoi(av[1]));
    return SUCCESS;
}
