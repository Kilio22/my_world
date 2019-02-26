/*
** EPITECH PROJECT, 2018
** my_printf_put_nbr.c
** File description:
** Printf function about returning a string from an int
*/

#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include "my.h"
#include "my_string.h"
#include "my_stdio.h"

static char *get_returnstr(char *str, int isneg)
{
    char *return_str = my_strdup(my_revstr(str));

    if (isneg == 1)
        return_str = my_strcat(my_strdup("-"), return_str);
    return (return_str);
}

char *printf_put_nbr(va_list list)
{
    char *base = "0123456789";
    int result = va_arg(list, int);
    int base_length = 10;
    int r;
    char str[50] = "";
    int isneg = 0;

    if (result < 0) {
        isneg = 1;
        result = -result;
    }
    str[0] = '0';
    for (int i = 0; result != 0; i++) {
        r = result % base_length;
        result = result / base_length;
        str[i] = base[r];
    }
    return (get_returnstr(str, isneg));
}

char *printf_putnbr_pointer(long int nbr)
{
    char *base = "0123456789abcdef";
    int base_length = 16;
    int r;
    long unsigned int result;
    char str[50] = "";

    if (nbr < 0)
        result = ULONG_MAX + nbr;
    else
        result = nbr;
    if (nbr == 0)
        str[0] = '0';
    for (int i = 0; result != 0; i++) {
        r = result % base_length;
        result = result / base_length;
        str[i] = base[r];
    }
    return (my_strdup(my_revstr(str)));
}