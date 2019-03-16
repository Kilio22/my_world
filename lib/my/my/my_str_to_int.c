/*
** EPITECH PROJECT, 2019
** my_str_to_int.c
** File description:
** Goes from a char * to int
*/

#include "my.h"

int my_str_to_int(const char *str)
{
    int value = 0;

    if (my_str_isnum(str, 1) == 0)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        value *= 10;
        value += str[i] - '0';
    }
    return (value);
}
