/*
** EPITECH PROJECT, 2018
** my_char_islower.c
** File description:
** Is the given char lowercase
*/

int my_char_islower(char const c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    else
        return (0);
}