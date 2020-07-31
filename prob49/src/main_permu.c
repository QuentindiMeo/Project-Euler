/*
** PERSONAL PROJECT, 2020
** permu
** File description:
** main 
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_is_prime(int nb);

static int eq(int *a, int *b, int size)
{
    for (int i = 0; i < size; i++)
        if (a[i] != b[i])
            return (FALSE);
    return (TRUE);
}

static int is_permu(char *n1, char *n2, char *n3)
{
    int a1[10] = {0,0,0,0,0,0,0,0,0,0};
    int a2[10] = {0,0,0,0,0,0,0,0,0,0};
    int a3[10] = {0,0,0,0,0,0,0,0,0,0};

    for (int i = 0; n1[i]; i++)
        a1[n1[i] - 48] = a1[n1[i] - 48] + 1;
    for (int i = 0; n2[i]; i++)
        a2[n2[i] - 48] = a2[n2[i] - 48] + 1;
    for (int i = 0; n3[i]; i++)
        a3[n3[i] - 48] = a3[n3[i] - 48] + 1;
    if (eq(a1, a2, 10) && eq(a1, a3, 10)) {
        free3(n1, n2, n3);
        return (TRUE);
    }
    free3(n1, n2, n3);
    return (FALSE);
}

static int condition_works(int n)
{
    for (int t = 1; n + t + t < 10000; t++)
        if (my_is_prime(n + t) && my_is_prime(n + t + t))
            if (is_permu(my_itoa(n), my_itoa(n + t), my_itoa(n + t + t)))
                return (t);
    return (FALSE);
}

static void permu(void)
{
    uint res = 1488;
    uint t;

    for (; res < 10000; res++) {
        if (!my_is_prime(res))
            continue;
        t = condition_works(res);
        if (t)
            break;
    }
    printf("Works for: %i - %i - %i, +%i\n", res, res + t, res + t + t, t);
    printf("Answer is: %i%i%i\n", res, res + t, res + t + t);
}

int main(void)
{
    permu();
    return (SUCCESS);
}
