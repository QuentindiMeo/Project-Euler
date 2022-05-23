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

typedef	unsigned int  uint;
typedef	unsigned long ulong;

int my_atoi(const char * const s);
char *my_renew(char *old, char *new);
int my_strcmp(const char *s1, const char *s2);
char *my_strdup(const char *src);
char *my_itoa(int nb);
char *my_infinmul(char *n1, char *n2);
char *my_infindiv(char *n1, char *n2, bool ismod);
char *my_utoa(unsigned int nb);

#endif
