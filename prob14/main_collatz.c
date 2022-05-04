/*
** PERSONAL PROJECT, 2019
** collatz
** File description:
** collatz computer main
*/

#include <stdio.h>
#include "my.h"

static uint collatz(uint n)
{
    uint iter = 0;

    for (; n > 1; iter++)
        n = (n % 2) ? 3 * n + 1 : n / 2;
    return iter;
}

static int chain(int limit)
{
    uint iter = 0, max = 0, longest = 0;

    for (int i = 0; i < limit; i++) {
        iter = collatz(i);
        if (max < iter) {
            max = iter;
            longest = i;
        }
    }
    printf("Longest chain under %i: %i\n", limit, longest);
    return SUCCESS;
}

int main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && my_atoi(av[1]) > 50000000)) {
        printf("USAGE\n\t./%s [limit <= 50000000]\n", av[0]);
	return FAILURE;
    }
    return chain(my_atoi(av[1]));
}
