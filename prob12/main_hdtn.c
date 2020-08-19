/*
** PERSONAL PROJECT, 2019
** hdtn
** File description:
** main hdtn
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static int get_divisors(uint triangle)
{
    uint divisors = 0;

    if (triangle < 75000000 || triangle % 4)
        return (0);
    for (long i = 1; i <= triangle; i++)
        divisors += (triangle % i == 0);
    if (divisors >= 350)
        printf("%i = %d\n", triangle, divisors);
    return (divisors);
}

static void hdtn(int limit)
{
    uint triangle = 0;

    for (uint i = 1; i && get_divisors(triangle) <= limit; i++)
        triangle += i;
    printf("1st triangle number to have %d+ divisors: %i\n", limit, triangle);
}

int main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && atoi(av[1]) < 0)) {
        printf("USAGE\n\t%s [limit > 0]\n", av[0]);
        return (FAILURE);
    }
    hdtn(atoi(av[1]));
    return (SUCCESS);
}
