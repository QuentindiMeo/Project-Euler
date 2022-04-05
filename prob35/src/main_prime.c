/*
** PERSONAL PROJECT, 2019
** circular primes
** File description:
** main
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

static int check_circular(int nth)
{
    char *nb = my_itoa(nth);
    char *tmp = my_strdup(nb);

    for (int i = 0; nb[i]; i++) {
        tmp = rotate_nb(tmp);
        if (!my_is_prime(my_atoi(tmp))) {
            free2(tmp, nb);
            return FALSE;
        }
    }
    free2(tmp, nb);
    printf("%i\n", nth);
    return TRUE;
}

static int is_in(int i, int n)
{
    char digit = i + 48, *num = my_itoa(n);

    for (int i = 0; num[i]; i++)
        if (num[i] == digit) {
            free(num);
            return TRUE;
        }
    free(num);
    return FALSE;
}

static int quick_filter(int nth)
{
    if (nth < 10) return TRUE;
    return (!is_in(0, nth) && !is_in(2, nth) && !is_in(4, nth) &&
            !is_in(5, nth) && !is_in(6, nth) && !is_in(8, nth) && my_is_prime(nth));
}

static void prime_loop(void)
{
    uint res = 0;
    int  nth = 2;

    for (; nth < 1000000; nth++) {
        if (quick_filter(nth) && check_circular(nth))
            res++;
        if (nth == 200000) nth = 300000;
        if (nth == 400000) nth = 700000;
        if (nth == 800000) nth = 900000;
    }
    printf("Total amount of circular primes below 1M : %i\n", res);
}

int main(void)
{
    prime_loop();
    return SUCCESS;
}
