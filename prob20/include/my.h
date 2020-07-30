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
} return_values_t;

typedef	unsigned int uint;

void free2(char *s1, char *s2);
int my_atoi(char const *str);
char *my_strdup(char const *src);
unsigned int my_strlen(char const *str);
char *my_utoa(unsigned int nb);

#endif
