/*
** EPITECH PROJECT, 2019
** my_memset.c
** File description:
** Fills the memory with the given char
*/

#include "my_string.h"

void *my_memset(void *s, int c, size_t n)
{
    register char *s_ptr = (char *) s;

    while (n--)
        *s_ptr++ = c;
    return (s);
}
