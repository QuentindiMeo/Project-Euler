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

int my_putchar(const char c);
int my_putchar_err(const char c);
int my_putstr(const char *str);
int my_puterr(const char *str);
int my_putarr(char * const *tab, const char c);
unsigned int my_strlen(const char *str);
void free3(char *s1, char *s2, char *s3);
void free2(char *s1, char *s2);
void ofree(void *p1, void *p2, void *p3, void *p4);
void free_str_array(char **array);
void free_int_array(int **array, unsigned int size);
char *my_str_memset(char *p, int val, int n);
int *my_int_memset(int *p, int val, int n);
unsigned int my_atou(const char *str);
int my_getnbr(const char *str);
int my_atoi(const char *str);
int my_putnbr_err(int);
int my_putnbr(int nb);
char *my_infinadd(char *n1, char *n2);
char *my_infinmul(char *n1, char *n2);
char *my_infinpow(char *n1, unsigned int n2);
void my_charcat(char *str, const char c);
char *my_strdup(const char *src);
char *my_strdup2(const char *src, const char to_add);
char *my_strdup3(const char *src, const char *to_add);
char *my_nstrdup(const char *src, unsigned int start);
char **my_arrdup(char * const *arr, int size);
char **my_arrdup2(char * const *arr, int size, char *to_add);
int my_isneg(const int nb);
int my_swap(int *a, int *b);
char *my_evil_str(const char *str);
unsigned int my_compute_power_rec(int nb, int p);
char *my_nstrcpy(char *dest, const char *src, unsigned int n);
char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, unsigned int n);
char *my_revstr(char *str);
char *my_strncat(char *dest, const char *src, unsigned int n);
char *my_strcat(char *dest, const char *src);
char *my_nstrcat(char *dest, const char *src, unsigned int n);
int my_strcmp(const char *s1, const char *s2);
int my_strcmpu(const char *s1, const char *s2);
int my_strcmpi(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, unsigned int n);
int my_c_isalpha(const char c);
bool my_c_isblank(const char c);
bool my_c_isnum(const char c);
bool my_c_islower(const char c);
bool my_c_isupper(const char c);
bool my_c_isprintable(const char c);
bool my_str_isalpha(const char *str);
bool my_str_isblank(const char *str);
bool my_str_isnum(const char *str);
bool my_str_islower(const char *str);
bool my_str_isupper(const char *str);
bool my_str_isprintable(const char *str);
bool my_str_isneg(const char *str);
char *my_strstr(const char *str, const char *to_find);
char *my_substr(const char *str, const int start, const unsigned int len);
char *my_cut_str(const char *s, const int idx_start, const int idx_end);
char *my_cut_word_n_from_str(const char *s, int n);
char **my_cut_word_array(char * const *array, const int start, const int end);
char **my_str_to_word_array(const char *str);
bool my_int_isinarray(const int *array, int nb, unsigned int size);
bool my_c_isinstr(const char *str, const char c);
bool my_str_isinarray(char * const *array, const char *s);
bool my_str_startswith(const char *s1, const char *s2);
bool my_str_endswith(const char *s1, const char *s2);
bool my_str_isequal_insensitive(const char *s1, const char *s2);
bool my_str_isinarray_insensitive(char * const *array, const char *s);
bool my_word_array_isequal(char * const *arr1, char * const *arr2);
bool my_word_array_isequal_insensitive(char * const *arr1, char * const *arr2);

int my_qurt(const unsigned int nb);
int my_cbrt(const unsigned int nb);
int my_sqrt(const unsigned int nb);

char *my_utoa(unsigned int nb);
char *my_itoa(int nb);
int ctoi(const char c);
char itoc(const int i);
char *ctos(const char c);
char stoc(const char *s);

#endif /* !MY_H_ */
