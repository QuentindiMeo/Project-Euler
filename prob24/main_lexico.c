
/*
** PERSONAL PROJECT, 2022
** lexico
** File description:
** main 
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static long power(long n, int p) {long res=1;for(int i=0;i<p;i++)res*=n;return res;}
static char *ltos(long n)
{
    char *s = NULL;
    int len = 1, i = 0;

    for (long tmp = n; tmp; tmp /= 10) len++;
    len--;
    s = malloc(sizeof(char) * (len + 1));
    for (int p = len - 2; p >= -1; p--) {
        s[i] = n / power(10, p + 1) + 48;
//        printf("%li / %li -> '%c'\n", n, power(10, p + 1), s[i]);
        n %= power(10, p + 1);
        i++;
    }
    s[len] = 0;
    return s;
}

static int result(int res, char *s) {if (res == TRUE) {free(s); return TRUE;} free(s); return FALSE;}
static int is_permut(long i)
{
    char *s = ltos(i);
//    printf("examining :%s: (%li)\n", s, i);
    int n[10] = {0,0,0,0,0,0,0,0,0,0};

    for (int i = 0; s[i]; i++) {n[0] += (s[i] == '0');}
    for (int i = 0; s[i]; i++) {n[1] += (s[i] == '1');}
    for (int i = 0; s[i]; i++) {n[2] += (s[i] == '2');}
    for (int i = 0; s[i]; i++) {n[3] += (s[i] == '3');}
    for (int i = 0; s[i]; i++) {n[4] += (s[i] == '4');}
    for (int i = 0; s[i]; i++) {n[5] += (s[i] == '5');}
    for (int i = 0; s[i]; i++) {n[6] += (s[i] == '6');}
    for (int i = 0; s[i]; i++) {n[7] += (s[i] == '7');}
    for (int i = 0; s[i]; i++) {n[8] += (s[i] == '8');}
    for (int i = 0; s[i]; i++) {n[9] += (s[i] == '9');}
    return result((n[0] < 2 && n[1] == 1 && n[2] == 1 && n[3] == 1 && n[4] == 1 && n[5] == 1 &&
                   n[6] == 1 && n[7] == 1 && n[8] == 1 && n[9] == 1), s);
}
#include <unistd.h>
static long lexico(int nth)
{
    for (long i = 123456789; 1; i += 9) {
        if (is_permut(i)) {
//            printf("%li\n", i);
//            usleep(50000);
            nth--;
        }
        if (!nth)         return i;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && (my_atoi(av[1]) < 1 || my_atoi(av[1]) > 10000000))) {
        printf("USAGE\n\t%s [0 < limit <= 10000000]\n", av[0]);
        return (FAILURE);
    }
    printf("Sl(%i) = %li\n", my_atoi(av[1]), lexico(my_atoi(av[1])));
    return (SUCCESS);
}
