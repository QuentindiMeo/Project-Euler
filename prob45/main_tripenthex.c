/*
** PERSONAL PROJECT, 2019
** tripenthex
** File description:
** main tripenthex
*/

#include <stdio.h>
#include "my.h"

static int print_res(long i, long j, long k, long hexa)
{
    printf("Condition is verified for: "
           "T%li = P%li = H%li = %li\n", i, j, k, hexa);
    return (SUCCESS);
}

static int tripenthex(void)
{
    long tria = 0;
    long pent = 0;
    long hexa = 0;

    for (long i = 286; i < 64000; i++, pent = 0) {
        tria = i * (i + 1) / 2;
        for (long j = i * 0.55; pent <= tria; j++, hexa = 0) {
            pent = j * (3 * j - 1) / 2;
            for (long k = i * 0.48; hexa <= pent; k++) {
                hexa = k * (2 * k - 1);
                if (tria == pent && pent == hexa)
                    return (print_res(i, j, k, hexa));
            }
        }
    }
    return (FAILURE);
}

int main(void)
{
    return (tripenthex());
}
