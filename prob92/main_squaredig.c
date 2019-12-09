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
    char *number = NULL;
    int tempres = 0;

    while (tempres != 1 && tempres != 89) {
        number = my_itoa(tempres ? tempres : num);
        tempres = 0;
        for (uint i = 0; number[i]; i++)
            tempres += my_compute_power_rec(ctoi(number[i]), 2);
        free(number);
    }
    return (tempres);
}

int main(void)
{
    int res = 0;

    for (int i = 2; i < 10000000; i++)
        if (squaredig(i) == 89)
            res++;
    printf("%d numbers arrive at 89 below 10M\n", res);
    return (SUCCESS);
}
