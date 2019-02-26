/*
** EPITECH PROJECT, 2019
** my_linelen.c
** File description:
** Returns the length of a line
*/

#include "my_string.h"

size_t my_linelen(const char *s)
{
    register const char *char_ptr = s;

    while (*char_ptr && *char_ptr != '\n')
        char_ptr++;
    return (char_ptr - s);
}
