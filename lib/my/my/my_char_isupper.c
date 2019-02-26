/*
** EPITECH PROJECT, 2018
** my_char_isupper.c
** File description:
** Is the given char uppercase
*/

int my_char_isupper(char const c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    else
        return (0);
}