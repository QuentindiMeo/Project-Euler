/*
** PERSONAL PROJECT, 2019
** concealedsquare
** File description:
** main concealedsquare
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

#define MIN_VAL 1010101030
#define MAX_VAL 1389026630

static int my_str_isequal_form(const char *s)
{
    return (s[0]  == '1' && s[2]  == '2' && s[4]  == '3' && s[6]  == '4' &&
            s[8]  == '5' && s[10] == '6' && s[12] == '7' && s[14] == '8' && s[16] == '9');
}

static int concealed(void)
{
    char *tmp = NULL, *res = NULL;

    for (int i = MAX_VAL; i >= MIN_VAL; i -= 100) {
        tmp = my_itoa(i);
        res = my_infinpow(tmp, 2);
        if (my_str_isequal_form(res)) {
            printf("Works for %i: %s\n", i, res);
            break;
        }
        free(tmp); free(res);
        tmp = my_itoa(i + 40);
        res = my_infinpow(tmp, 2);
        if (my_str_isequal_form(res)) {
            printf("Works for %i: %s\n", i + 40, res);
            break;
        }
        free(tmp); free(res);
    }
    free(tmp); free(res);
    return SUCCESS;
}

int main(void)
{
    return concealed();
}
