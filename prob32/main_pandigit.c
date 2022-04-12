/*
** PERSONAL PROJECT, 2022
** pandigit
** File description:
** main 
*/

#include <stdio.h>
#include <stdbool.h>
#include "my.h"

static int is_pandig(int n1, int n2, int n3)
{
    int count[9];

    for (int i = 0; i < 9; i++) count[i] = 0;
    for (; n1; n1 /= 10) {
        if (n1 % 10 == 0) return FALSE;
        if (count[n1 % 10 - 1] == 0) count[n1 % 10 - 1] = 1;
        else return FALSE;
    }
    for (; n2; n2 /= 10) {
        if (n2 % 10 == 0) return FALSE;
        if (count[n2 % 10 - 1] == 0) count[n2 % 10 - 1] = 1;
        else return FALSE;
    }
    for (; n3; n3 /= 10) {
        if (n3 % 10 == 0) return FALSE;
        if (count[n3 % 10 - 1] == 0) count[n3 % 10 - 1] = 1;
        else return FALSE;
    }
    for (int i = 0; i < 9; i++)
        if (count[i] == 0)
            return FALSE;
    return TRUE;
}

static int pandigit(void)
{
    int  res  = 0;
    bool done = false;

    for (int i = 1000; i < 9999; i++) {
        for (int j = 2; j < i / 2 && !done; j++) {
            if (i % j == 0 && is_pandig(i, j, i / j)) {
                printf("Works for: %d * %d = %d\n", i / j, j, i);
                res += i;
                done = true;
            }
        }
        done = false;
    }
    return res;
}

int main(void)
{
    printf("S(products) = %i\n", pandigit());
    return SUCCESS;
}
