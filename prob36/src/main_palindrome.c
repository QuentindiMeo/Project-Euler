/*
** PERSONAL PROJECT, 2019
** palindrome
** File description:
** main palindrome
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int is_palindrome(char const *str);

static char *dec_to_bin(unsigned int dec)
{
    char *bin = malloc(sizeof(char) * (dec / 2 + 2));
    unsigned short temp = 0;
    unsigned int ten_pow = 0;

    if (!bin)
        return (my_strdup("0\0"));
    for (; dec > 0; ten_pow++) {
        temp = dec % 2;
        dec /= 2;
        bin[ten_pow] = itoc(temp);
    }
    bin[ten_pow] = 0;
    my_revstr(bin);
    return (bin);
}

static void palindrome(uint limit)
{
    uint res = 0;
    char *tempdec = NULL;
    char *tempbin = NULL;

    for (uint i = 1; i < limit; i++) {
        tempdec = my_itoa(i);
        if (is_palindrome(tempdec)) {
            tempbin = dec_to_bin(i);
            if (is_palindrome(tempbin)) {
                printf("works for %i:%c\t%s\n",
                       i, i < 10000 ? '\t' : '\0', tempbin);
                res += i;
            }
            free(tempbin);
        }
        free(tempdec);
    }
    printf("%cS(palindrome(n, 10, 2)) with n < %d: %d\n",
           res ? '\n' : '\0', limit, res);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        printf("USAGE\n\t%s [0 < limit <= 1000000000]\n", av[0]);
        return (FAILURE);
    }
    if (my_atoi(av[1]) <= 0 || my_atoi(av[1]) > 1000000000) {
        printf("USAGE\n\t%s [0 < limit <= 1000000000]\n", av[0]);
        return (FAILURE);
    }
    palindrome(my_atoi(av[1]));
    return (SUCCESS);
}
