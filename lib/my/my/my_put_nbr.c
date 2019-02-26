/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** Prints an int
*/

#include "my.h"
#include "my_string.h"
#include "my_stdio.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb / 10)
        my_put_nbr(nb / 10);
    my_putchar((nb % 10) + '0');
    return (0);
}
