/*
** EPITECH PROJECT, 2018
** my_str_isin.c
** File description:
** Returns one if the given char is inside the given string
*/

#include "my.h"
#include "my_string.h"

int my_char_isin(char const c, char const *src)
{
    int len = my_strlen(src);

    for (int i = 0; i < len; i++) {
        if (c == src[i])
            return (i + 1);
    }
    return (0);
}