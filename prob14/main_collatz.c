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
    return (iter);
}

int main(void)
{
    uint iter = 0;
    uint max = 0;
    uint longest = 0;

    for (int i = 0; i < 1000000; i++) {
        iter = collatz(i);
        if (max < iter) {
            max = iter;
            printf("New longest: %i\n", i);
            longest = i;
        }
    }
    printf("Longest chain under 1M: %i\n", longest);
    return (SUCCESS);
}
