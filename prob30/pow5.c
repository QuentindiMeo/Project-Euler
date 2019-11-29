#include <stdio.h>
#include "my.h"

static int sum_of_all_digits_pow_5(int i)
{
    int res = 0;

    for (; i; i /= 10)
        res += my_compute_power_rec(i % 10, 5);
    return (res);
}

int main(void)
{
    int res = 0;

    for (int i = 2; i < 500000; i++) {
        if (i == sum_of_all_digits_pow_5(i)) {
            printf("Works for %i\n", i);
            res += i;
        }
    }
    printf("\nresult = %i\n", res);
    return (0);
}