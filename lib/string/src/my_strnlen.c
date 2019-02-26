/*
** EPITECH PROJECT, 2019
** my_strnlen.c
** File description:
** Does the same thing as strlen, but for n max bytes
*/

#include "my_string.h"

size_t my_strnlen(const char *s, size_t maxlen)
{
    register const char *char_ptr = s;
    const char *end_ptr = s + maxlen;

    while (*char_ptr && char_ptr < end_ptr)
        char_ptr++;
    return (char_ptr - s);
}
