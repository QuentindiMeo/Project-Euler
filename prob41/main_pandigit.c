/*
** PERSONAL PROJECT, 2022
** pandigit
** File description:
** main 
*/

#include <stdio.h>
#include "my.h"

static int is_pandigit(int nb, int sz)
{
    int count[sz];

    for (int i = 0; i < sz; i++) count[i] = 0;
    for (; nb; nb /= 10) {
        if (nb % 10 > sz) return false;
        if (count[nb % 10 - 1] == 0) count[nb % 10 - 1] = 1;
        else return false;
    }
    for (int i = 0; i < sz; i++)
        if (count[i] == 0)
            return false;
    return true;
}

static int get_size(int nb)
{
    int size = 0;

    for (; nb; nb /= 10, size++);
    return size;
}

static int pandigit(void)
{
    int max = 0;

    for (int i = 12345; i < 10000000; i += 2)
        if (is_pandigit(i, get_size(i)) && my_is_prime(i))
            max = i;
    return max;
}

int main(void)
{
    printf("Largest n-digit pandigital prime: %i\n", pandigit());
    return (SUCCESS);
}
