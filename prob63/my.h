/*
11;rgb:1e1e/1e1e/1e1e** EPITECH PROJECT, 2018
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

unsigned int my_strlen(const char *str);
char *my_infinpow(char *n1, char *n2);
char *my_itoa(int nb);
int my_atoi(const char *s);

#endif
