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
char *my_infinpow(char *n1, unsigned int n2);
char *my_strdup(char const *src);
unsigned int my_strlen(char const *str);
char **my_arrdup2(char **arr, int size, char *to_add);
int my_str_isinarray(char **array, char const *s);
void free_array(char **array);
char *my_itoa(int nb);

#endif
