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

void free3(char *s1, char *s2, char *s3);
char *my_itoa(int nb);
int my_c_isinstr(char const *str, char const c);

#endif
