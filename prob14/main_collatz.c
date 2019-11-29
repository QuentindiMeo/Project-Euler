/*
** PERSONAL PROJECT, 2019
** collatz
** File description:
** collatz computer main
*/

#include "my.h"

static uint collatz(uint n)
{
    uint iter = 0;

    for (; n > 1; iter++) {
        if (n % 2)
            n =  3 * n + 1;
        else
            n /= 2;
    }
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
            my_putstr("New longest! ");my_putnbr(i);my_putchar('\n');
            longest = i;
        }
    }
    my_putstr("Longest chain under 1M: "); my_putnbr(longest);my_putchar('\n');
    return (SUCCESS);
}
