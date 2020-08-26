/*
** PERSONAL PROJECT, 2019
** prime_computer
** File description:
** main prime computer
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int my_is_prime(int nb);

static char *rotate_nb(char *nb)
{
    char *tmp = my_strdup(nb);
    char temp = nb[0];
    uint i = 0;

    for (; nb[i + 1]; i++)
        tmp[i] = nb[i + 1];
    tmp[i] = temp;
    free(nb);
    return (tmp);
}

static int check_circular(uint nth)
{
    char *nb = my_itoa(nth);
    char *tmp = my_strdup(nb);

    for (uint i = 0; nb[i]; i++) {
        tmp = rotate_nb(tmp);
        if (!my_is_prime(my_atoi(tmp))) {
            free2(tmp, nb);
            return (FALSE);
        }
    }
    free2(tmp, nb);
    printf("%u is \033[1mcircular\033[0m\n", nth);
    return (TRUE);
}

static void prime_loop(void)
{
    uint res = 0;
    int nth = 2;

    for (; nth < 1000000; nth++) {
        if (nth % 2 && my_is_prime(nth) && check_circular(nth))
            res++;
        if (nth == 200000)
            nth = 300000;
        if (nth == 400000)
            nth = 900000;
    }
    printf("\nTotal amount of circular primes below 1M : %i\n", res);
}

int main(void)
{
    prime_loop();
    return (SUCCESS);
}
