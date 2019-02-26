/*
** EPITECH PROJECT, 2018
** my_arraylen.c
** File description:
** Returns the length of a char **
*/

#include "my_string.h"

size_t my_arraylen(char **array)
{
    register char **ptr = array;

    while (*ptr)
        ptr++;
    return (ptr - array);
}
