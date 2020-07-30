/*
** EPITECH PROJECT, 2018
** CPool_Day05_2018
** File description:
** my_is_prime
*/

int get_prime(int restart)
{
    static int res = 1;
    int nbb = 1;
    int div = 0;

    if (restart)
        res = 1;
    res++;
    while (nbb <= res) {
        if (res % nbb == 0)
            div++;
        if (div > 2)
            return (get_prime(0));
        nbb++;
    }
    return (res);
}

int my_is_prime(int nb)
{
    int nbb = 1;
    int div = 0;

    while (nbb <= nb) {
        if (nb % nbb == 0)
            div++;
        if (div > 2)
            return (0);
        nbb++;
    }
    return (1);
}
