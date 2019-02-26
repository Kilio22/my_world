/*
** EPITECH PROJECT, 2018
** my_showstr.c
** File description:
** Displays a string with non-printable characters in hexadecimal
*/

#include "my.h"
#include "my_string.h"
#include "my_stdio.h"

static char *my_get_hexa(int nbr)
{
    int base_length = 16;
    int r;
    char str[50] = "";
    char *base = "0123456789ABCDEF";
    int i;

    if (nbr == 0)
        str[0] = '0';
    for (i = 0; nbr != 0; i++) {
        r = nbr % base_length;
        nbr = nbr / base_length;
        str[i] = base[r];
    }
    str[i] = '\0';
    return (my_revstr(str));
}

static char *lowercase_ize(char *str)
{
    int length = my_strlen(str);

    for (int i = 0; i < length; i++) {
        if (my_char_isupper(str[i]))
            str[i] += 32;
    }
    return (str);
}

static void put_zero_if_empty(char *str)
{
    if (my_strlen(str) == 1)
        my_putchar('0');
}

int my_showstr(char const *str)
{
    int length = my_strlen(str);

    for (int i = 0; i < length; i++) {
        if (!my_char_isprintable(str[i])) {
            char *str_hex = my_get_hexa(str[i]);
            char *str_hex_toprint = lowercase_ize(str_hex);
            my_putchar('\\');
            put_zero_if_empty(str_hex_toprint);
            my_putstr(str_hex_toprint);
        }
        else
            my_putchar(str[i]);
    }
    return (0);
}
