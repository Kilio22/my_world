/*
** EPITECH PROJECT, 2018
** my_str_isalpha.c
** File description:
** Returns 1 if the whole given string is only letters
*/

#include "my.h"
#include "my_string.h"

int my_str_isalpha(char const *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (!(my_char_islower(str[i]) || my_char_isupper(str[i])))
            return (0);
    }
    return (1);
}