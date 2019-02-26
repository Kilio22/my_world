/*
** EPITECH PROJECT, 2018
** my_printf_zeropadding.c
** File description:
** Only is useful if the 0 flag is effective
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "my_printf.h"
#include "my_string.h"
#include "my_stdio.h"

static int get_index(char *str, char const *src)
{
    int index = 0;

    if (str[0] == '-')
        index = 1;
    if (my_char_isin('p', src))
        index = 2;
    return (index);
}

static int get_zero_nb(char *str, char const *src, char const *flags,
                            char const *fieldwidth)
{
    int len = my_strlen(str);
    int src_len = my_strlen(src);
    int fieldwidth_len = my_getnbr(fieldwidth);
    int zero_nb = fieldwidth_len - len;

    if (my_char_isin('+', flags) || my_char_isin(' ', flags)) {
        zero_nb -= 1;
        if (str[0] == '-' && my_char_isin(src[src_len - 1], signed_conversions))
            zero_nb += 1;
        if (!my_char_isin(src[src_len - 1], signed_conversions))
            zero_nb += 1;
    }
    if (my_char_isin('#', flags) && !my_char_isin('p', src)) {
        zero_nb -= 2;
        if (src[src_len - 1] == 'o')
            zero_nb += 1;
    }
    return (zero_nb);
}

static char *manage_zeros(char *str, char const *src, char const *flags,
                            char const *fieldwidth)
{
    int zero_nb;
    int index = get_index(str, src);

    if (fieldwidth == 0)
        return (str);
    zero_nb = get_zero_nb(str, src, flags, fieldwidth);
    while (zero_nb > 0) {
        str = my_str_addchar(str, '0', index);
        zero_nb--;
    }
    return (str);
}

char *analyse_zeros(char *str, char const *src, char const *flags)
{
    int src_len = my_strlen(src);
    int begin = 0;
    int end = 0;
    char *fieldwidth = 0;

    if (my_char_isin('.', src) || my_char_isin('-', flags))
        return (str);
    for (int i = 0; i < src_len; i++) {
        if (my_char_isnum(src[i]) && src[i] != '0' && !begin)
            begin = i;
        if (src[i] == '.' || my_char_isin(src[i], conversion_specifiers))
            end = (!end) ? i : end;
    }
    if (begin && end && begin < end)
        fieldwidth = my_strndup(&src[begin], end - begin);
    str = manage_zeros(str, src, flags, fieldwidth);
    if (fieldwidth != 0)
        free(fieldwidth);
    return (str);
}