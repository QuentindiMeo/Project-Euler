/*
** PERSONAL PROJECT, 2020
** goldbach
** File description:
** main 
*/

#include <stdio.h>
#include "my.h"

int get_prime(int restart);
int my_is_prime(int nb);

static int conjecture_works(int n)
{
    for (int j = get_prime(1); j < n; j = get_prime(0))
        for (int i = 1; j + 2 * i * i <= n; i++)
            if (j + 2 * i * i == n)
                return (TRUE);
    return (FALSE);
}

static void goldbach(void)
{
    uint res = 3;

    for (; 1; res += 2) {
        if (my_is_prime(res))
            continue;
        if (!conjecture_works(res))
            break;
    }
    printf("Smallest odd composite to not fit the conjecture: %d\n", res);
}

int main(void)
{
    goldbach();
    return (SUCCESS);
}
