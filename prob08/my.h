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
    YES = 1,
    NO = 0,
    ERROR = -1,
    END_OF_FILE = -1,
    END_OF_ARGS = -1,
    CTRLD = -1,
} return_values_t;

typedef	unsigned int uint;
typedef	unsigned char uchar;

int my_atoi(char const *str);
int my_strcmpi(char const *s1, char const *s2);
char *my_infinmul(char *n1, char *n2);
char *my_strdup(char const *src);
char *my_cut_str(char const *, int const, int const);
char *ctos(char const c);

#endif
