/*
** EPITECH PROJECT, 2019
** my_memcpy.c
** File description:
** Copies memory from one given pointer to another
*/

#include "my_string.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    register char *d = (char *) dest;

    while (n--)
        *d++ = *(char *) src++;
    return (dest);
}
