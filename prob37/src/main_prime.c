/*
** PERSONAL PROJECT, 2019
** prime_computer
** File description:
** main prime computer
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

int my_is_prime(int nb);

static int check_right(uint nth)
{
    char *nb = my_itoa(nth);
    char *tmp = my_strdup(nb);

    for (uint i = 0; nb[i]; i++) {
        tmp = my_cut_str(nb, 0, my_strlen(nb) - i - 1);
        if (!my_is_prime(my_atoi(tmp))) {
            free2(tmp ? tmp : NULL, nb ? nb : NULL);
            return (FALSE);
        }
    }
    free2(tmp ? tmp : NULL, nb ? nb : NULL);
    return (TRUE);
}

static int check_left(uint nth)
{
    char *nb = my_itoa(nth);
    char *tmp = my_strdup(nb);

    for (uint i = 0; nb[i]; i++) {
        tmp = my_cut_str(nb, i, my_strlen(nb) - 1);
        if (!my_is_prime(my_atoi(tmp))) {
            free2(tmp ? tmp : NULL, nb ? nb : NULL);
            return (FALSE);
        }
    }
    free2(tmp ? tmp : NULL, nb ? nb : NULL);
    return (TRUE);
}

static void prime_loop(void)
{
    int count = 0;
    int res = 0;
    uint nth = 10;

    for (; count < 11 && nth < 4000000000; nth++) {
        if (my_is_prime(nth)) {
            if (check_left(nth) && check_right(nth)) {
                printf("Works for %u\n", nth);
                count++;
                res += nth;
            }
        }
        if (nth == 100000)
            nth = 700000;
    }
    printf("\nResult : %i\n", res);
}

int main(void)
{
    prime_loop();
    return (SUCCESS);
}
