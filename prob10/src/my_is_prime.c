/*
** EPITECH PROJECT, 2018
** CPool_Day05_2018
** File description:
** my_is_prime
*/

int my_is_prime(int nb)
{
    int div = 0;

    if (nb <= 1)
        return (0);
    for (int nbb = 1; nbb <= nb; nbb++) {
        if (nb % nbb == 0)
            div++;
        if (div > 2)
            return (0);
    }
    return (1);
}
