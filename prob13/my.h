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

void free3(char *s1, char *s2, char *s3);
char *my_infinadd(char *n1, char *n2);
char *my_strdup(char const *src);
char *my_cut_str(char const *, int const, int const);

#endif
