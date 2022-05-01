/*
** PERSONAL PROJECT, 2020
** cancelling
** File description:
** main 
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

double case4(const char *s, const char *t);
double case3(const char *s, const char *t);
double case2(const char *s, const char *t);
double case1(const char *s, const char *t);

#define NUMER 0
#define DENOM 1

static int simplify(int i, int j)
{
    static int state = FALSE;
    int n = i;

    for (; n > 1 && (i % n || j % n); n--);
    state = !state;
    return (state ? i / n : j / n);
}

static void print_res(int numer, int denom)
{
    int snum = simplify(numer, denom);
    int sden = simplify(numer, denom);

    printf("\nSimplified product of these 4 fractions: %d/%d\n", snum, sden);
}

static int cancellable(int i, int j)
{
    char *s = my_itoa(i);
    char *t = my_itoa(j);

    if (s[0] == t[0] && case1(s, t) == (double) i / j) {
        free(s); free(t); return TRUE;
    }
    if (s[my_strlen(s) - 1] == t[my_strlen(t) - 1] &&
        s[my_strlen(s) - 1] != '0' && case2(s, t) == (double) i / j) {
        free(s); free(t); return TRUE;
    }
    if (s[0] == t[my_strlen(t) - 1] && case3(s, t) == (double) i / j) {
        free(s); free(t); return TRUE;
    }
    if (s[my_strlen(s) - 1] == t[0] && case4(s, t) == (double) i / j) {
        free(s); free(t); return TRUE;
    }
    free(s); free(t); return FALSE;
}

static return_values_t cancelling(void)
{
    int idx = 0;
    int a[4][2] = {{0,0},{0,0},{0,0},{0,0}};

    for (int j = 2; j < 100; j++)
        for (int i = 1; i < j; i++)
            if (i > 9 && cancellable(i, j)) {
                printf("Found %d/%d\n", i, j);
                a[idx][NUMER] = i;
                a[idx][DENOM] = j;
                idx++;
            }
    print_res(a[0][NUMER] * a[1][NUMER] * a[2][NUMER] * a[3][NUMER],
              a[0][DENOM] * a[1][DENOM] * a[2][DENOM] * a[3][DENOM]);
    return SUCCESS;
}

int main(void)
{
    return cancelling();
}
