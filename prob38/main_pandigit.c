/*
** PERSONAL PROJECT, 2022
** pandigit
** File description:
** main 
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static int is_pandig(int *prods, int sz)
{
    int count[9];

    for (int i = 0; i < 9; i++) count[i] = 0;
    for (int i = 0; i < sz; i++) {
        for (; prods[i]; prods[i] /= 10) {
            if (prods[i] % 10 == 0) return FALSE;
            if (count[prods[i] % 10 - 1] == 0) count[prods[i] % 10 - 1] = 1;
            else return FALSE;
        }
    }
    for (int i = 0; i < 9; i++)
        if (count[i] == 0)
            return FALSE;
    return TRUE;
}

static int *push_back(int *a, int sz, int val)
{
    int *new = NULL;

    if (!sz) {
        new = malloc(sizeof(int));
        new[0] = val;
        return new;
    }
    new = malloc(sizeof(int) * (sz + 1));
    for (int i = 0; i < sz; i++) new[i] = a[i];
    new[sz] = val;
    free(a);
    return new;
}

static int get_size(int nb)
{
    int size = 0;

    for (; nb; nb /= 10, size++);
    return size;
}

static int pandigital(void)
{
    int max = 0;
    int sz = 0, len = 0;
    int *prods = NULL;

    for (int i = 9; i < 50000; i++) {
        for (int a = 1; len < 9; a++) {
            prods = push_back(prods, sz, i * a);
            len  += get_size(i * a); sz++;
        }
        max = (len == 9 && is_pandig(prods, sz) ? i : max);
        len = 0; sz = 0;
        free(prods);
    }
    printf("Largest 1->9 pandig is ");
    for (int a = 1; len < 9; a++) {
        prods = push_back(prods, sz, max * a);
        len  += get_size(max * a); sz++;
    }
    for (int i = 0; i < sz; i++)
        printf("%i", prods[i]);
    free(prods);
    return max;
}

int main(void)
{
    printf(" (for iteration #%i)\n", pandigital());
    return SUCCESS;
}
