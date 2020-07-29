/*
** PERSONAL PROJECT, 2020
** cancelling
** File description:
** main 
*/

#include <stdio.h>
#include "my.h"

double case4(const char *s, const char *t)
{
    char *ss = my_cut_str(s, 0, my_strlen(s) - 2);
    char *ts = my_cut_str(t, 1, my_strlen(t) - 1);
    double res = (double) my_atoi(ss) / my_atoi(ts);

    free2(ss, ts);
    return (res);
}

double case3(const char *s, const char *t)
{
    char *ss = my_cut_str(s, 1, my_strlen(s) - 1);
    char *ts = my_cut_str(t, 0, my_strlen(t) - 2);
    double res = (double) my_atoi(ss) / my_atoi(ts);

    free2(ss, ts);
    return (res);
}

double case2(const char *s, const char *t)
{
    char *ss = my_cut_str(s, 0, my_strlen(s) - 2);
    char *ts = my_cut_str(t, 0, my_strlen(t) - 2);
    double res = (double) my_atoi(ss) / my_atoi(ts);

    free2(ss, ts);
    return (res);
}

double case1(const char *s, const char *t)
{
    char *ss = my_cut_str(s, 1, my_strlen(s) - 1);
    char *ts = my_cut_str(t, 1, my_strlen(t) - 1);
    double res = (double) my_atoi(ss) / my_atoi(ts);

    free2(ss, ts);
    return (res);
}
