/*
** EPITECH PROJECT, 2018
** my_strupcase.c
** File description:
** Puts lowercase letter in a string into uppercase
*/

#include "my.h"
#include "my_string.h"

char *my_strupcase(char *str)
{
    int length = my_strlen(str);

    for (int i = 0; i < length; i++) {
        if (my_char_islower(str[i]))
            str[i] -= 32;
    }
    return (str);
}