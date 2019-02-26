/*
** EPITECH PROJECT, 2018
** my_printf_flags.c
** File description:
** Flag management with the printf stuff
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "my_printf.h"
#include "my_string.h"
#include "my_stdio.h"

static char *handle_hashtag(char *str, char const *src, char const *flags)
{
    int src_len = my_strlen(src);

    if (my_char_isin('#', flags) && src[src_len - 1] == 'x')
        str = my_strcat(my_strdup("x"), str);
    if (my_char_isin('#', flags) && src[src_len - 1] == 'X')
        str = my_strcat(my_strdup("X"), str);
    if (my_char_isin('#', flags))
        str = my_strcat(my_strdup("0"), str);
    return (str);
}

static char *manage_flags(char *str, char const *src, char const *flags)
{
    int src_len = my_strlen(src);

    if (my_char_isin(src[src_len - 1], signed_conversions) && str[0] != '-') {
        if (my_char_isin('+', flags))
            str = my_strcat(my_strdup("+"), str);
        else if (my_char_isin(' ', flags))
            str = my_strcat(my_strdup(" "), str);
    }
    if (my_char_isin(src[src_len - 1], alternate_forms))
        str = handle_hashtag(str, src, flags);
    return (str);
}

static char *free_and_return(char *str, char const *src, char const *flags)
{
    str = analyse_fieldwidth(str, src, flags);
    free((char *)flags);
    return (str);
}

char *analyse_flags(char *str, char const *src)
{
    int len = my_strlen(src);
    int i;
    int j = 0;
    char *flags;

    if (src[len - 1] == '%')
        return (str);
    flags = my_stralloc(5, '\0');
    for (i = 1; my_char_isin(src[i], flag_chars) == 1; i++) {
        if (my_char_isin(src[i], flag_chars) && !my_char_isin(src[i], flags))
            flags[j++] = src[i];
    }
    if (!(my_char_isin('p', src) && my_strcmp(str, "(nil)") == 0)) {
        str = analyse_precision(str, src);
        if (my_char_isin('0', flags))
            str = analyse_zeros(str, src, flags);
        str = manage_flags(str, src, flags);
    }
    return (free_and_return(str, src, flags));
}