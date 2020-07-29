/*
** PERSONAL PROJECT, 2020
** pythagoras
** File description:
** main 
*/

#include <math.h>
#include <stdio.h>
#include "my.h"

static int get_solutions(int n)
{
    int sol = 0;

    for (int j = 1; j < n; j++)
        for (int i = 1; i < j; i++)
            if (i + j + sqrt(i * i + j * j) == n)
                sol++;
    return (sol);
}

static void pythagoras(int limit)
{
    int max = 0;
    int sol = 0;

    for (int i = 1; i < limit; i++)
        if (sol < get_solutions(i)) {
            sol = get_solutions(i);
            max = i;
            printf("Maximum is now %d with %d solutions\n", max, sol);
        }
}

int main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && my_atoi(av[1]) <= 0)) {
        printf("USAGE\n\t%s [0 < limit < 1]\n", av[0]);
        return (FAILURE);
    }
    pythagoras(my_atoi(av[1]));
    return (SUCCESS);
}
