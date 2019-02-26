/*
** EPITECH PROJECT, 2018
** my_char_isnum.c
** File description:
** Is the given char a number
*/

int my_char_isnum(char const c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}