/*
** PERSONAL PROJECT, 2019
** champernowne
** File description:
** main champernowne
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int main(void)
{
    int res = 1;
    int cursor = 0;
    int i = 1;

    for (; i < 10; i++)
        cursor += 1;
    for (; i < 100; i++) {
        if (cursor == 10 || cursor == 11)
            res *= (cursor == 11 ? i / 10 : i % 10);
        if (cursor == 100 || cursor == 101 || cursor == 102) {
            if (cursor == 100)
                res *= (i / 100);
            else if (cursor == 101 || cursor == 102)
                res *= (cursor == 102 ? i / 100 : i % 100 / 10);
        }
        cursor += 2;
    }
    for (; i < 1000; i++) {
        if (cursor == 1000 || cursor == 1001 || cursor == 1002) {
            if (cursor == 1000)
                res *= (i / 1000);
            else if (cursor == 1001 || cursor == 1002)
                res *= (cursor == 1002 ? i % 1000 / 100 : i % 100 / 10);
        }
        cursor += 3;
    }
    for (; i < 10000; i++) {
        if (cursor >= 10000 && cursor <= 10003) {
            if (cursor == 10000 || cursor == 10003)
                res *= (cursor == 10000) ? (i / 10000) : (i / 1000);
            else if (cursor == 10001 || cursor == 10002)
                res *= (cursor == 1002 ? i % 10000 / 1000 : i % 1000 / 100);
        }
        cursor += 4;
    }
    for (; i < 100000; i++) {
        if (cursor >= 100000 && cursor <= 100004) {
            if (cursor == 100000 || cursor == 100003)
                res *= (cursor == 100000) ? (i / 100000) : (i / 10000);
            else if (cursor == 100001 || cursor == 100002)
                res *=
                    (cursor == 10002 ? i % 100000 / 10000 : i % 10000 / 1000);
            else if (cursor == 100004)
                res *= (i / 10000);
        }
        cursor += 5;
    }
    for (; i < 10000000; i++) {
        if (cursor >= 1000000 && cursor <= 1000005) {
            if (cursor == 1000000 || cursor == 1000003)
                res *= (cursor == 1000000) ? (i / 1000000) : (i / 100000);
            else if (cursor == 1000001 || cursor == 1000002)
                res *=
                (cursor == 100002 ? i % 1000000 / 100000 : i % 100000 / 10000);
            else if (cursor == 1000004 || cursor == 1000005)
                res *=
                (cursor == 1000005) ? (i / 100000) : (i / 10000);
        }
        cursor += 6;
    }
    printf("Result: %d\n", res);
    return (SUCCESS);
}
