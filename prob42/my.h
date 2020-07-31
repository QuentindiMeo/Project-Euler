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
    YES = 1,
    NO = 0,
    ERROR = -1,
} return_values_t;

typedef	unsigned int uint;

unsigned int my_strlen(char const *str);
char *my_cut_str(char const *s, int const idx_start, int const idx_end);

#endif
