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

typedef struct inta {
    int *a;
    int sz;
} inta;
typedef struct sievecell_s {
    bool achieved;
    int chainlen;
    int starting;
} sievecell;

static void push_back(inta *s, int n)
{
    int *new = NULL;
    int i = 0;

    if (s->a   == NULL) {
        s->a    = malloc(sizeof(int));
        s->a[0] = n;
        s->sz += 1;
        return;
    }
    new = malloc(sizeof(int) * (s->sz + 1));
    for (; i < s->sz; i++)
        new[i] = s->a[i];
    new[i] = n;
    free(s->a);
    s->a = new;
    s->sz += 1;
}

static bool my_is_prime(int nb)
{
    int nbb = 2, max = my_sqrt(nb);

    if (nb < 2) return false;
    for (; nb % nbb && nbb <= max; nbb++);
    return (nbb == max + 1);
}

static bool is_in(inta s, int n)
{
    int i = 0;

    for (; i < s.sz; i++)
        if (s.a[i] == n)
            return true;
    return false;
}

static void try_chains(inta primes, int *max, int *start)
{
    sievecell *seive = malloc(sizeof(sievecell) * (primes.a[primes.sz - 1]));

    for (int i = 0; i < primes.a[primes.sz - 1]; i++)
        seive[i] = (sievecell) {false, 0, -1};
    for (int starting = 0; starting < 16; starting++) {
        for (int i = starting, sum = 0; i < primes.sz; i++) { // try_chain()
            sum += primes.a[i];
            if (sum >= primes.a[primes.sz - 1]) break;
            if (is_in(primes, sum) && seive[sum].achieved == false)
                seive[sum] = (sievecell) {true, i - starting + 1, starting};
        }
    }
    for (int i = primes.a[primes.sz - 1] - 1; i; i--) {
        if (seive[i].achieved && seive[i].chainlen > *max) {
            *max   = seive[i].chainlen;
            *start = seive[i].starting;
        }
    }
    free(seive);
}

static int consecutive(int limit)
{
    inta primes = {NULL, 0};
    int max = 0, startidx = 0, sum = 0;

    push_back(&primes, 2);
    for (int i = 3; i < limit / 2; i += 2)
        if (my_is_prime(i))
            push_back(&primes, i);
    printf("generated %d primes.\n", primes.sz);
    try_chains(primes, &max, &startidx);
    for (int i = startidx; i < max + startidx; i++)
        sum += primes.a[i];
    free(primes.a);
    printf("max: %i (at idx %i, sum = %i)\n", max, startidx, sum);
    return SUCCESS;
}

int main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && my_atoi(av[1]) >= 2000001)) {
        printf("USAGE\n\t%s [0 < limit <= 2000000]\n", av[0]);
        return FAILURE;
    }
    return consecutive(my_atoi(av[1]));
}
