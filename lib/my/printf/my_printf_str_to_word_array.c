/*
** EPITECH PROJECT, 2018
** my_printf_str_to_word_array.c
** File description:
** Goes from a string to an array splited by '%'
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "my_printf.h"
#include "my_string.h"
#include "my_stdio.h"

static int my_bool_split(char const c, char const begin, int *i)
{
    if (c == '\0')
        return (1);
    if (begin == '%' && *i) {
        if (my_char_isin(c, conversion_specifiers)) {
            (*i)++;
            return (1);
        }
        if (!my_char_isin(c, whole_flags))
            return (1);
        return (0);
    }
    if (c == '%')
        return (1);
    return (0);
}

static int my_count_nb_in_string(char const *str)
{
    int nb_count = 0;
    char begin = str[0];
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (!nb_count)
            nb_count++;
        if (my_bool_split(str[i], begin, &i)) {
            nb_count++;
            begin = str[i];
        }
    }
    return (nb_count);
}

char **my_str_to_printf_array(char const *str)
{
    int nb_count = my_count_nb_in_string(str);
    char **nb_array = malloc(sizeof(char *) * (nb_count + 1));
    int pos1 = 0;
    int pos2 = 0;
    int nbers_copied = 0;

    while (str[pos2] != '\0') {
        while (my_bool_split(str[pos1], str[pos2], &pos1) == 0)
            pos1++;
        nb_array[nbers_copied] = my_strndup(&str[pos2], (pos1 - pos2));
        pos2 = pos1++;
        nbers_copied++;
    }
    nb_array[nbers_copied] = 0;
    return (nb_array);
}