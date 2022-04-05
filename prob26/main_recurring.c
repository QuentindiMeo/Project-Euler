/*
** PERSONAL PROJECT, 2022
** recurring
** File description:
** main 
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_strlen(const char *);
char *my_itoa(int);
char *my_strcpy(char *, const char *);
char *my_strcat(char *, const char *);
char *my_strdup(const char *);
char *my_cut_str(const char *, const int, const int);

typedef struct cycle_s {
    int     val;
    char *cycle;
} cycle;

static char *extend(char *s, char *e)
{
    int   len = my_strlen(s) + my_strlen(e);
    char *new = malloc(sizeof(char) * (len + 1));

    my_strcpy(new, s ? s : ""); my_strcat(new, e);
    free(s); free(e);
    return new;
}

static cycle new_cycle(int num, int denum)
{
    cycle  new = {0, NULL};
    int     *a = malloc(sizeof(int) * denum);
    char *deci = NULL;
    int    rem = num % denum;

    for (int i = 0; i < denum; i++) a[i] = 0;
    for (; rem && !a[rem]; rem %= denum) {
        a[rem] = my_strlen(deci);
        rem *= 10;
        deci = extend(deci, my_itoa((int) rem / denum));
    }
    if (!rem) { free(deci); free(a); return new; }
    new = (cycle) {denum, my_cut_str(deci, a[rem], my_strlen(deci) - a[rem])};
    free(deci); free(a);
    return new;
}

static int recurring(int limit)
{
    cycle max = {0, NULL}, tmp = {0, NULL};

    for (int i = 2; i < limit; i++) {
        tmp = new_cycle(1, i);
        if (my_strlen(max.cycle) < my_strlen(tmp.cycle)) {
            free(max.cycle);
            max = (cycle) {tmp.val, my_strdup(tmp.cycle)};
        }
        free(tmp.cycle);
    }
    printf("Longest cycle: %s", max.cycle);
    free(max.cycle);
    return max.val;
}

int main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && (my_atoi(av[1]) < 2 || my_atoi(av[1]) > 6400))) {
        printf("USAGE\n\t%s [1 < limit <= 6400]\n", av[0]);
        return (FAILURE);
    }
    printf(" is for 1/%i\n", recurring(my_atoi(av[1])));
    return (SUCCESS);
}
