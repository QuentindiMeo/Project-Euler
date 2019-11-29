/*
** EPITECH PROJECT, 2018
** CPool_Day05_2018
** File description:
** my_compute_factorial_rec
*/

int my_compute_factorial_rec(int nb)
{
    if (nb < 0 || nb > 12)
        return (0);
    if (nb == 0)
        return (1);
    nb = nb * my_compute_factorial_rec(nb - 1);
    return (nb);
}
