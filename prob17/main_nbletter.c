/*
** PERSONAL PROJECT, 2019
** nbletter
** File description:
** main nbletter
*/

#include <stdio.h>
#include "my.h"

static char *get_digit(int digit)
{
    switch (digit) {
    case 1:
        return ("one");
        break;
    case 2:
        return ("two");
        break;
    case 3:
        return ("three");
        break;
    case 4:
        return ("four");
        break;
    case 5:
        return ("five");
        break;
    case 6:
        return ("six");
        break;
    case 7:
        return ("seven");
        break;
    case 8:
        return ("eight");
        break;
    case 9:
        return ("nine");
        break;
    default:
        return ("\0");
        break;
    }
}

static char *get_double_digit(int doubledig)
{
    switch (doubledig) {
    case 2:
        return ("twenty");
        break;
    case 3:
        return ("thirty");
        break;
    case 4:
        return ("forty");
        break;
    case 5:
	return ("fifty");
        break;
    case 6:
        return ("sixty");
	break;
    case 7:
        return ("seventy");
        break;
    case 8:
        return ("eighty");
        break;
    case 9:
        return ("ninety");
        break;
    default:
        return ("\0");
        break;
    }
}

static char *get_ten_digits(int number)
{
    switch (number) {
    case 11:
        return ("eleven");
        break;
    case 12:
        return ("twelve");
        break;
    case 13:
        return ("thirteen");
        break;
    case 14:
        return ("fourteen");
        break;
    case 15:
        return ("fifteen");
        break;
    case 16:
        return ("sixteen");
	break;
    case 17:
        return ("seventeen");
        break;
    case 18:
        return ("eighteen");
        break;
    case 19:
        return ("nineteen");
        break;
    default:
        return ("ten");
        break;
    }
}

static int get_nbletter(int number)
{
    int nbl = 0;

    if (number == 1000)
        return (my_strlen("one") + my_strlen("thousand"));
    if (number > 99) {
        nbl += my_strlen(get_digit(number / 100)) +
            my_strlen("hundred") +
            (number % 100 == 0 ? 0 : my_strlen("and"));
    }
    if (number / 10 % 10 == 0) {
        nbl += my_strlen(get_digit(number % 10));
    } else {
        nbl += (number / 10 % 10 != 1) ?
            my_strlen(get_double_digit(number % 100 / 10)) +
                my_strlen(get_digit(number % 10)) :
            my_strlen(get_ten_digits(number % 100));
    }
    return (nbl);
}

static int nbletter(uint limit)
{
    uint res = 0;

    for (uint i = 1; i <= limit; i++)
        res += get_nbletter(i);
    printf("Number letter count for up to %d: %u\n", limit, res);
    return (SUCCESS);
}

int main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && my_atoi(av[1]) < 0)) {
        printf("USAGE\n\t%s [0 < limit <= 1000]\n", av[0]);
        return (FAILURE);
    }
    if (my_atoi(av[1]) > 1000) {
        printf("USAGE\n\t%s [0 < limit <= 1000]\n", av[0]);
        return (FAILURE);
    }
    return (nbletter(my_atoi(av[1])));
}
