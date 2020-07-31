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
typedef	unsigned char uchar;

char *my_strdup(char const *src);
char *my_utoa(unsigned int nb);
int my_atoi(char const *str);
int ctoi(char const c);

#endif
