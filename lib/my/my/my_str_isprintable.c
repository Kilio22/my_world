/*
** EPITECH PROJECT, 2018
** my_str_isprintable.c
** File description:
** Returns 1 if the whole given string is printable
*/

#include "my.h"
#include "my_string.h"

int my_str_isprintable(char const *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (!my_char_isprintable(str[i]))
            return (0);
    }
    return (1);
}