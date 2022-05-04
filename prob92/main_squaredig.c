/*
** PERSONAL PROJECT, 2019
** squaredig
** File description:
** main squaredig
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static int squaredig(int num)
{
    int tempres = 0;

    for (char *number = NULL; tempres != 1 && tempres != 89; free(number)) {
        number = my_itoa(tempres ? tempres : num);
        tempres = 0;
        for (uint i = 0; number[i]; i++)
            tempres += my_compute_power_rec(ctoi(number[i]), 2);
    }
    return tempres;
}

int main(void)
{
    uint res = 0;

    for (uint i = 2; i < 10000000; i++)
        res += (squaredig(i) == 89);
    printf("%i numbers arrive at 89 below 10M.\n", res);
    return (SUCCESS);
}
