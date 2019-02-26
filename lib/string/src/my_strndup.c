/*
** EPITECH PROJECT, 2019
** my_strndup.c
** File description:
** Allocates then fills the memory with the first n bytes of the given string
*/

#include <stdlib.h>
#include "my_string.h"

char *my_strndup(const char *s, size_t n)
{
    register size_t len = my_strnlen(s, n);
    char *new = malloc(len);

    if (new == NULL)
        return (NULL);
    my_strncpy(new, s, n);
    return (new);
}
