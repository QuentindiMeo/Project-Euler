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
    TRUE = 1,
    FALSE = 0,
    YES = 1,
    NO = 0,
    ERROR = -1,
    END_OF_FILE = -1,
    END_OF_ARGS = -1,
    CTRLD = -1,
} return_values_t;

typedef	unsigned int uint;
typedef	unsigned char uchar;

unsigned int my_strlen(const char *str);
void free_str_array(char **array);
char *my_strdup(const char *src);
char **my_arrdup2(char * const *arr, int size, char *to_add);
int my_strcmp(const char *s1, const char *s2);
char *my_cut_str(const char *s, const int idx_start, const int idx_end);

#endif /* !MY_H_ */
