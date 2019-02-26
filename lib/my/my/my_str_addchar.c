/*
** EPITECH PROJECT, 2018
** my_str_addchar.c
** File description:
** Adds a char in the given str index
*/

#include <stdlib.h>
#include "my.h"
#include "my_string.h"

char *my_str_addchar(char const *str, char const c, int index)
{
    char *new_str = my_strndup(str, index);
    char *char_str = my_strdup(" ");

    char_str[0] = c;
    new_str = my_strcat(new_str, char_str);
    new_str = my_strcat(new_str, my_strdup(&str[index]));
    free((char *)str);
    return (new_str);
}