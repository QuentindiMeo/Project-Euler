/*
** PERSONAL PROJECT, 2019
** pythagorean
** File description:
** main pythagorean
*/

#include <stdio.h>
#include "my.h"

int main(void)
{
    for (uint a = 1; a < 333; a++)
        for (uint b = 2; b < 666; b++)
            for (uint c = 3; a + b + c <= 1000; c++)
                if (a * a + b * b == c * c && a + b + c == 1000) {
                    printf("Triplet: %u, %u, %u\nResult : %u\n",
                           a, b, c, a * b * c);
                    return (SUCCESS);
                }
    return (FAILURE);
}
