/*
** EPITECH PROJECT, 2018
** CPool_Day09_2018
** File description:
** my library headers
*/

#ifndef MY_H_
#define MY_H_

typedef enum {
    SUCCESS = 0,
    FAILURE = 84,
    ERROR = -1,
} return_values_t;

typedef	unsigned int uint;

int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
char **my_arrdup2(char **arr, int size, char *to_add);
unsigned int my_strlen(char const *str);
char *my_cut_str(char const *s, int const idx_start, int const idx_end);
void free_array(char **array);

#endif
