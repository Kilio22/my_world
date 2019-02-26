/*
** EPITECH PROJECT, 2018
** my_strstr.c
** File description:
** Finds the first occurence of a string inside another
*/

#include "my.h"
#include "my_string.h"

static int compare_str(char *str, char const *to_find, int i, int len)
{
    for (int j = 0; j < len; j++) {
        if (str[i] == to_find[j])
            i++;
        else
            return (0);
    }
    return (i);
}

char *my_strstr(char *str, char const *to_find)
{
    int len = my_strlen(str);
    int to_find_len = my_strlen(to_find);

    for (int i = 0; i < len; i++) {
        if (compare_str(str, to_find, i, to_find_len) != 0)
            return (&str[i]);
    }
    return ('\0');
}