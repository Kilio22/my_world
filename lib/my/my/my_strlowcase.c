/*
** EPITECH PROJECT, 2018
** my_strlowcase.c
** File description:
** Puts uppercase letter in a string into lowercase
*/

#include "my.h"
#include "my_string.h"

char *my_strlowcase(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (my_char_isupper(str[i]))
            str[i] += 32;
    }
    return (str);
}