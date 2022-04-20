/*
** PERSONAL PROJECT, 2022
** sundays
** File description:
** main sundays
*/

#include <stdio.h>
#include "my.h"

static int is_leap(int year)
{
    if (year % 100 == 0 && year % 400 != 0) return FALSE;
    return (year % 4 == 0);
}

static int get_month(int year, int month)
{
    switch (month) {
    case 2: //february
        return 31; break;
    case 3: //march
        return get_month(year, month - 1) + (is_leap(year) ? 29 : 28); break;
    case 4: //april
        return get_month(year, month - 1) + 31; break;
    case 5: //may
        return get_month(year, month - 1) + 30; break;
    case 6: //june
        return get_month(year, month - 1) + 31; break;
    case 7: //july
        return get_month(year, month - 1) + 30; break;
    case 8: //august
        return get_month(year, month - 1) + 31; break;
    case 9: //september
        return get_month(year, month - 1) + 31; break;
    case 10: //october
        return get_month(year, month - 1) + 30; break;
    case 11: //november
        return get_month(year, month - 1) + 31; break;
    case 12: //december
        return get_month(year, month - 1) + 30; break;
    default:
        return 0; break;
    }
}

static int get_first(int year, int month)
{
    int day = 1;

    for (int i = 1900; i < year; i++)
        day += is_leap(i) ? 366 : 365;
    day += get_month(year, month);
    return (day % 7 ? day % 7 : 7);
}

int main(int ac, char **av)
{
    int sundays = 0;

    if (ac != 2 || (ac == 2 && (my_atoi(av[1]) <= 1900 || my_atoi(av[1]) >= 9999))) {
	printf("USAGE\n\t%s [1900 < limit <= 9999]\n", av[0]);
        return FAILURE;
    }
    for (int year = 1901; year <= my_atoi(av[1]); year++)
        for (int month = 1; month <= 12; month++)
            sundays += (get_first(year, month) == 7);
/*            if (get_first(year, month) == 7) {
                printf("1st of %s%d/%d is sunday\n", month > 9 ? "" : "0", month, year);
                sundays++;
            }
*/    printf("N(sundays, 1): %d\n", sundays);
    return SUCCESS;
}
