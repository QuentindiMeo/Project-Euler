/*
** PERSONAL PROJECT, 2019
** distinct
** File description:
** main distinct
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static char **my_arrdup2(char **arr, int size, char *added)
{
    char **dup = NULL;
    int j = 0;

    dup = malloc(sizeof(char *) * (size + 2));
    for (; j < size; j++)
        dup[j] = my_strdup(arr[j]);
    dup[j] = my_strdup(added);
    dup[j + 1] = NULL;
    return (dup);
}

static char **add_result(char **results, char *result)
{
    char **newresults = NULL;
    int size = 0;

    if (!results) {
        results = malloc(sizeof(char *) * 2);
        results[0] = my_strdup(result);
        results[1] = NULL;
        return (results);
    }
    if (!my_str_isinarray(results, result)) {
        for (; results[size]; size++);
        newresults = my_arrdup2(results, size, result);
        free_array(results);
        return (newresults);
    }
    return (results);
}

static void distinct(int a_max, int b_max)
{
    int res = 0;
    char **results = NULL;
    char *tempa = NULL;
    char *tempres = NULL;

    for (int a = 2; a <= a_max; a++) {
        tempa = my_itoa(a);
        for (int b = 2; b <= b_max; b++) {
            tempres = my_infinpow(tempa, b);
            results = add_result(results, tempres);
            free(tempres);
        }
        free(tempa);
    }
    for (; results[res]; res++);
    printf("Distinct terms: %d\n", res);
    free_array(results);
}

int main(int ac, char **av)
{
    if (ac != 3) {
        printf("USAGE\n\t%s [a_max > 1] [b_max > 1]\n", av[0]);
        return (FAILURE);
    }
    if (my_atoi(av[1]) < 2 || my_atoi(av[2]) < 2) {
        printf("USAGE\n\t%s [a_max > 1] [b_max > 1]\n", av[0]);
        return (FAILURE);
    }
    distinct(my_atoi(av[1]), my_atoi(av[2]));
    return (SUCCESS);
}
