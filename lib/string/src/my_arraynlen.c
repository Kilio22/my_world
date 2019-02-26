/*
** EPITECH PROJECT, 2018
** my_arraylen.c
** File description:
** Returns the length of a char **
*/

#include "my_string.h"

size_t my_arraynlen(char **array, size_t maxlen)
{
    register char **ptr = array;
    register char **end_ptr = array + maxlen;

    while (*ptr && ptr < end_ptr)
        ptr++;
    return (ptr - array);
}
