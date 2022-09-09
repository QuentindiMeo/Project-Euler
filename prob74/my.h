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

void free_str_array(char **array);
bool my_int_isinarray(const int *array, const int n, uint size);
bool my_str_isinarray(char * const *array, const char *s);
char *my_infinadd(char *n1, char *n2);
char *my_strdup(const char *src);
char *my_infinfac(char *nb);
char *my_itoa(int nb);
int my_atoi(const char *s);

#endif
