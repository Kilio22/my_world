/*
** EPITECH PROJECT, 2018
** my_printf_showstr.c
** File description:
** Displays a string with non-printable characters in octal
*/

#include <stdlib.h>
#include "my.h"
#include "my_string.h"
#include "my_stdio.h"

static char *my_get_oct(int nbr)
{
    char *base = "01234567";
    int base_length = 8;
    int r;
    int result = nbr;
    char str[50] = "";
    char *return_str;

    if (nbr < 0)
        result = 256 + nbr;
    if (nbr == 0)
        str[0] = '0';
    for (int i = 0; result != 0; i++) {
        r = result % base_length;
        result = result / base_length;
        str[i] = base[r];
    }
    return_str = my_strdup(my_revstr(str));
    return (return_str);
}

static char *put_zero_if_empty(char *str)
{
    int len = my_strlen(str);

    if (len == 1)
        str = my_strcat(my_strdup("00"), str);
    else if (len == 2)
        str = my_strcat(my_strdup("0"), str);
    return (str);
}

char *my_printf_showstr(char const *str)
{
    int len = my_strlen(str);
    char *str_oct;
    char *return_str = my_strdup("\0");

    for (int i = 0; i < len; i++) {
        if (!my_char_isprintable(str[i])) {
            str_oct = my_get_oct(str[i]);
            str_oct = put_zero_if_empty(str_oct);
            str_oct = my_strcat(my_strdup("\\"), str_oct);
            return_str = my_strcat(return_str, str_oct);
        }
        else
            return_str = my_strncat(return_str, my_strdup(&str[i]), 1);
    }
    return (return_str);
}
