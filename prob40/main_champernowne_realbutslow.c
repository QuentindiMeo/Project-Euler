/*
** PERSONAL PROJECT, 2019
** champernowne
** File description:
** main champernowne
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static char *add_nb(char *champ, int new)
{
    int size = 0;
    char *newchamp = NULL;
    char *temp = my_itoa(new);

    for (int nb = new; nb > 0; nb /= 10)
        size++;
    newchamp = malloc(sizeof(char) * (my_strlen(champ) + size + 1));
    my_strcpy(newchamp, champ);
    my_strcat(newchamp, temp);
    free(temp);
    free(champ);
    return (newchamp);
}

int main(void)
{
    char *champ = NULL;
    int res = 1;

    champ = my_strdup("0.\0");
    for (uint i = 1; i < 100001; i++)
            champ = add_nb(champ, i);
//    printf("%s\n\n", champ);
    for (uint i = 1; i <= 100000; i *= 10)
        res *= ctoi(champ[i + 1]);
    free(champ);
    printf("d1(C) * d10(C) * d100(C) * d1000(C) * d10000(C) * d100000(C) * ");
    printf("d1000000(C) =\n");
    for (uint i = 1; i <= 100000; i *= 10)
        printf("%d * ", ctoi(champ[i + 1]));
    printf("1 =\n%d\n", res);
    return (SUCCESS);
}
