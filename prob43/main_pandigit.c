/*
** PERSONAL PROJECT, 2022
** divisible
** File description:
** main 
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static int rule17(long nb) { return ((nb % 1000)     % 17 == 0); }
static int rule13(long nb) { return ((nb / 10 % 1000) % 13 == 0); }
static int rule11(long nb) { return ((nb / 100 % 1000) % 11 == 0); }
static int rule7( long nb) { return ((nb / 1000 % 1000) % 7  == 0); }
static int rule5( long nb) { return ((nb / 10000 % 1000) % 5  == 0); }
static int rule3( long nb) { return ((nb / 100000 % 1000) % 3  == 0); }
static int rule2( long nb) { return ((nb / 1000000 % 1000) % 2  == 0); }

static int is_pandig(long nb)
{
    int count[10] = {0,0,0,0,0,0,0,0,0,0};

    count[0] = (nb <= 999999999);
    for (; nb; nb /= 10) {
        if (count[nb % 10] == 0) count[nb % 10] = 1;
        else return FALSE;
    }
    for (int i = 0; i < 10; i++)
        if (count[i] == 0)
            return FALSE;
    return TRUE;
}

static long divisible(void)
{
    long res = 0;

    for (long i = 123456789; i < 9876543210; i++) {
        if ( i / 1000000 % 2)         i +=  999999;
        if ((i / 100000  % 1000) % 3) i +=   99999;
        if ((i / 10000   % 1000) % 5) i +=    9999;
        if (rule17(i) && rule13(i) && rule11(i) && rule7(i) &&
            rule5(i) && rule3(i)  && rule2(i) && is_pandig(i))
            res += i;
    }
    return res;
}

int main(void)
{
    printf("S(pandig) with the property: %li\n", divisible());
    return SUCCESS;
}
