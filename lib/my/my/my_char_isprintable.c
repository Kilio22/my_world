/*
** EPITECH PROJECT, 2018
** my_char_is_printable.c
** File description:
** Is the given char printable
*/

int my_char_isprintable(char const c)
{
    if (c >= 32 && c <= 126)
        return (1);
    else
        return (0);
}