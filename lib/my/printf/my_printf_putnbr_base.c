/*
** EPITECH PROJECT, 2018
** my_printf_putnbr_base.c
** File description:
** Puts an int in a given base
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"
#include "my_string.h"
#include "my_stdio.h"

char *printf_putnbr_oct(va_list list)
{
    char *base = "01234567";
    int nbr = va_arg(list, int);
    int base_length = 8;
    int r;
    unsigned int result;
    char str[50] = "";

    if (nbr < 0)
        result = 4294967296 + nbr;
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

char *printf_putnbr_dec(va_list list)
{
    char *base = "0123456789";
    int nbr = va_arg(list, int);
    int base_length = 10;
    int r;
    unsigned int result;
    char str[50] = "";

    if (nbr < 0)
        result = 4294967296 + nbr;
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

char *printf_putnbr_hexlower(va_list list)
{
    char *base = "0123456789abcdef";
    int nbr = va_arg(list, int);
    int base_length = 16;
    int r;
    unsigned int result;
    char str[50] = "";

    if (nbr < 0)
        result = 4294967296 + nbr;
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

char *printf_putnbr_hexupper(va_list list)
{
    char *base = "0123456789ABCDEF";
    int nbr = va_arg(list, int);
    int base_length = 16;
    int r;
    unsigned int result;
    char str[50] = "";

    if (nbr < 0)
        result = 4294967296 + nbr;
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

char *printf_putnbr_bin(va_list list)
{
    char *base = "01";
    int nbr = va_arg(list, int);
    int base_length = 2;
    int r;
    unsigned int result;
    char str[50] = "";

    if (nbr < 0)
        result = 4294967296 + nbr;
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