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
typedef	unsigned char uchar;

void free_str_array(char **array);
int my_atoi(const char *str);
char *my_infinpow(char *n1, unsigned int n2);
char *my_strdup(const char *src);
char **my_arrdup2(char * const *arr, int size, char *to_add);
bool my_str_isinarray(char * const *array, const char *s);
char *my_itoa(int nb);

#endif /* !MY_H_ */
