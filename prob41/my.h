/*
** EPITECH PROJECT, 2018
** CPool_Day09_2018
** File description:
** my library headers
*/

#ifndef MY_H_
#define MY_H_

#include <stdbool.h>

typedef enum {
    SUCCESS = 0,
    FAILURE = 84,
} return_values_t;

typedef	unsigned int uint;

bool my_is_prime(const int n);
int my_atoi(const char * const s);

#endif
