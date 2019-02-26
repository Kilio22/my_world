/*
** EPITECH PROJECT, 2018
** my_char_isalphanum.c
** File description:
** Is the given char either a number or a letter
*/

#include "my.h"

int my_char_isalphanum(char const c)
{
    if (my_char_islower(c) || my_char_isupper(c) || my_char_isnum(c))
        return (1);
    else
        return (0);
}