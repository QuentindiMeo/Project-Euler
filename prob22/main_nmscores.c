/*
** PERSONAL PROJECT, 2020
** nmscores
** File description:
** main nmscores
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static int score(const char *word, const int n)
{
    int nb = 0;

    for (int i = 0; word[i]; i++)
        nb += (word[i] - 64);
    return (nb * n);
}

static void sort(char ***arr)
{
    int size = 0;

    for (; (*arr)[size]; size++);
    for (int j = 0; j <= size; j++)
        for (int i = 0; (*arr)[i + 1]; i++)
            if (my_strcmp((*arr)[i], (*arr)[i + 1]) > 0) {
                char *tmp = my_strdup((*arr)[i]);

                free((*arr)[i]);
                (*arr)[i] = my_strdup((*arr)[i + 1]);
                free((*arr)[i + 1]);
                (*arr)[i + 1] = tmp;
            }
}

static char *get_next_word(const char *words)
{
    static int cursor = 1;
    uint end = cursor;
    char *word = NULL;

    if (end >= my_strlen(words))
        return (NULL);
    for (; words[end] && words[end] != '\"'; end++);
    if (end >= my_strlen(words))
        return (NULL);
    end--;
    word = my_cut_str(words, cursor, end);
    cursor = end + 4;
    return (word);
}

static void nscores(const char *words)
{
    long res = 0;
    char *word = NULL;
    char **arr = NULL;
    char **tmp = NULL;

    for (int i = 0; 1; i++) {
        word = get_next_word(words);
        if (!word)
            break;
        tmp = arr;
        arr = my_arrdup2(tmp, i, word);
        free_array(tmp);
        free(word);
    }
    sort(&arr);
    for (int loop = 1; arr[loop - 1]; loop++)
        res += score(arr[loop - 1], loop);
    printf("Total score of the names in \"p042_names.txt\": %li\n", res);
    free_array(arr);
}

int main(void)
{
    FILE *stream = fopen("p022_names.txt", "r");
    char *words = NULL;
    size_t buf = 0;

    if (!stream) {
        printf("\"p022_names.txt\" couldn't be opened. Check you have it.\n");
        return (FAILURE);
    }
    if (getline(&words, &buf, stream) == ERROR)
        return (FAILURE);
    fclose(stream);
    nscores(words);
    free(words);
    return (SUCCESS);
}
