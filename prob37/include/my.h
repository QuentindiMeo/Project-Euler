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
    TRUE = 1,
    FALSE = 0,
} return_values_t;

typedef	unsigned int uint;

void free2(char *s1, char *s2);
char *my_strdup(char const *src);
unsigned int my_strlen(char const *str);
char *my_cut_str(char const *, int const, int const);
char *my_itoa(int nb);
int my_atoi(char const *str);

#endif
