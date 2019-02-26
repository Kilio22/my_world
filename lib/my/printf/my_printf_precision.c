/*
** EPITECH PROJECT, 2018
** my_printf_precision.c
** File description:
** Precision management for the my_printf function
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "my_printf.h"
#include "my_string.h"
#include "my_stdio.h"

static int get_index(char const *src)
{
    int index = 0;

    if (my_char_isin('p', src))
        index = 2;
    return (index);
}

static char *manage_precision(char *str, char const *src, char const *precision)
{
    int len = (my_char_isin('p', src)) ? my_strlen(str) - 2 : my_strlen(str);
    int src_len = my_strlen(src);
    int precision_len;

    if (precision == NULL)
        return (str);
    precision_len = my_getnbr(precision);
    if (my_char_isin(src[src_len - 1], integer_conversions)) {
        while (precision_len > len) {
            str = my_str_addchar(str, '0', get_index(src));
            len++;
        }
    }
    if (src[src_len - 1] == 's' || src[src_len - 1] == 'S') {
        while (len > precision_len) {
            str[len - 1] = '\0';
            len--;
        }
    }
    return (str);
}

char *analyse_precision(char *str, char const *src)
{
    int src_len = my_strlen(src);
    char *precision = 0;
    int begin_num = 0;
    int begin_dot = 0;

    for (int i = src_len - 1; i > 0; i--) {
        if (my_char_isnum(src[i]) && !begin_num)
            begin_num = i;
        if (src[i] == '.')
            begin_dot = i;
    }
    if (begin_dot && begin_num)
        precision = my_strndup(&src[begin_dot + 1], begin_num - begin_dot);
    else if (begin_dot && !begin_num)
        precision = my_strdup("0");
    str = manage_precision(str, src, precision);
    if (precision != 0)
        free(precision);
    return (str);
}