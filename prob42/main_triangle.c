/*
** PERSONAL PROJECT, 2019
** triangle
** File description:
** main triangle
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static int is_triangle(char *word)
{
    int wordval = 0;
    int triangle;

    if (!word)
        return (NO);
    for (int i = 0; word[i]; i++)
        wordval += (word[i] - 64);
    for (int n = 1; n < 50; n++) {
        triangle = n * (n + 1) / 2;
        if (triangle == wordval) {
            printf("%s is a triangle word.\n", word);
            return (YES);
        }
    }
    return (NO);
}

static char *get_next_word(char *words)
{
    static int cursor = 1;
    unsigned int end = cursor;
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

static void triangle(char *words)
{
    int res = 0;
    char *word = NULL;

    while (1) {
        word = get_next_word(words);
        if (!word)
            break;
        if (is_triangle(word))
            res++;
        free(word);
    }
    printf("\nNumber of triangle words in \"p042_words.txt\": %i\n", res);
}

int main(void)
{
    FILE *stream = fopen("p042_words.txt", "r");
    char *words = NULL;
    size_t buf = 0;

    if (!stream) {
        printf("\"p042_words.txt\" couldn't be opened. Check you have it.\n");
        return (FAILURE);
    }
    if (getline(&words, &buf, stream) == ERROR)
        return (FAILURE);
    fclose(stream);
    triangle(words);
    free(words);
    return (SUCCESS);
}
