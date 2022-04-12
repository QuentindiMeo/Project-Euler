/*
** PERSONAL PROJECT, 2022
** lexico
** File description:
** main 
*/

#include <stdio.h>
#include "my.h"

static int is_permut(long nb, int sz)
{
    int count[10];

    for (int i = 0; i < 10; i++) count[i] = 0;
    count[0] = (sz == 9);
    for (; nb; nb /= 10) {
        if (count[nb % 10] == 0) count[nb % 10] = 1;
        else return FALSE;
    }
    for (int i = 0; i < 10; i++)
        if (count[i] == 0)
            return FALSE;
    return TRUE;
}

static long lexico(int nth)
{
    for (long i = 123456789; i < 9999999999; i += 9) {
        nth -= is_permut(i,  i > 999999999 ? 10 : 9);
        if (!nth) return i;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && (my_atoi(av[1]) < 1 || my_atoi(av[1]) > 3200000))) {
        printf("USAGE\n\t%s [0 < limit <= 3200000]\n", av[0]);
        return FAILURE;
    }
    printf("lexico(%i) = %li\n", my_atoi(av[1]), lexico(my_atoi(av[1])));
    return SUCCESS;
}
