/*
** PERSONAL PROJECT, 2022
** consecutive
** File description:
** main
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

typedef struct sievecell_s {
    bool achieved;
    int chainlen;
    int starting;
} sievecell;

static bool my_is_prime(int nb)
{
    int nbb = 2, max = my_sqrt(nb);

    if (nb < 2) return false;
    for (; nb % nbb && nbb <= max; nbb++);
    return (nbb == max + 1);
}

static bool is_in(int *a, int sz, int n)
{
    int i = 0;

    for (; i < sz; i++)
        if (a[i] == n)
            return true;
    return false;
}

static void try_chains(int *primes, const int sz, int *max, int *start)
{
    sievecell *seive = malloc(sizeof(sievecell) * (primes[sz - 1]));

    for (int i = 0; i < primes[sz - 1]; i++)
        seive[i] = (sievecell) {false, 0, -1};
    for (int starting = 0; starting < 8; starting++) {
        for (int i = starting, sum = 0; i < sz; i++) { // try_chain()
            sum += primes[i];
            if (sum >= primes[sz - 1]) break;
            if (is_in(primes, sz, sum) && seive[sum].achieved == false)
                seive[sum] = (sievecell) {true, i - starting + 1, starting};
        }
    }
    for (int i = primes[sz - 1] - 1; i; i--) {
        if (seive[i].achieved && seive[i].chainlen > *max) {
            *max   = seive[i].chainlen;
            *start = seive[i].starting;
        }
    }
    free(seive);
}

static int consecutive(int limit)
{
    int primes[limit / 2], size = 0;
    int max = 0, startidx = 0, sum = 0;

    for (int i = 0; i < limit / 2; i++) primes[i] = 0;
    primes[0] = 2;
    for (int i = 3; i < limit; i += 2)
        if (my_is_prime(i))
            primes[size++] = i;
    try_chains(primes, size, &max, &startidx);
    for (int i = startidx; i < max + startidx; i++)
        sum += primes[i];
    printf("max: %i (at idx %i, sum = %i)\n", max, startidx, sum);
    return SUCCESS;
}

int main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && my_atoi(av[1]) >= 4200001)) {
        printf("USAGE\n\t%s [0 < limit <= 4200000]\n", av[0]);
        return FAILURE;
    }
    return consecutive(my_atoi(av[1]));
}
