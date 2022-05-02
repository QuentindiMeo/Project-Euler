/*
** EPITECH PROJECT, 2018
** CPool_Day05_2018
** File description:
** my_is_prime
*/

#include "my.h"

int my_is_prime(int nb)
{
    int nbb = 2, max = my_sqrt(nb);

    for (; nbb <= max && nb % nbb != 0; nbb++);
    return --nbb == max;
}
