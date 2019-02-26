/*
** EPITECH PROJECT, 2018
** my_printf_fieldwidth.c
** File description:
** Field width management for the my_printf function
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "my_printf.h"
#include "my_string.h"
#include "my_stdio.h"

static char *manage_fieldwidth(char *str, char const *flags, char *fieldwidth)
{
    int len = my_strlen(str);
    int fieldwidth_len;

    if (fieldwidth == NULL)
        return (str);
    fieldwidth_len = my_getnbr(fieldwidth);
    if (my_char_isin('-', flags)) {
        while (fieldwidth_len > len) {
            str = my_strcat(str, my_strdup(" "));
            len++;
        }
    } else {
        while (fieldwidth_len > len) {
            str = my_strcat(my_strdup(" "), str);
            len++;
        }
    }
    return (str);
}

char *analyse_fieldwidth(char *str, char const *src, char const *flags)
{
    int src_len = my_strlen(src);
    char *fieldwidth = 0;
    int begin = 0;
    int end = 0;

    for (int i = 0; i < src_len; i++) {
        if (my_char_isnum(src[i]) && src[i] != '0' && !begin)
            begin = i;
        if (src[i] == '.' || my_char_isin(src[i], conversion_specifiers))
            end = (!end) ? i : end;
    }
    if (begin && end && begin < end)
        fieldwidth = my_strndup(&src[begin], end - begin);
    str = manage_fieldwidth(str, flags, fieldwidth);
    if (fieldwidth != 0)
        free(fieldwidth);
    return (str);
}