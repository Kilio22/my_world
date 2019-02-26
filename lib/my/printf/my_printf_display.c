/*
** EPITECH PROJECT, 2018
** my_printf_display.c
** File description:
** Displays the "result" of the printf array
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#include "my_string.h"
#include "my_stdio.h"

char *printf_putnbr_pointer(long int nbr);
char *my_printf_showstr(char const *str);

char *printf_putstr(va_list list)
{
    char *str = my_strdup(va_arg(list, char *));

    return (str);
}

char *printf_putchar(va_list list)
{
    char character = va_arg(list, int);
    char *str = malloc(sizeof(char) * 2);

    str[0] = character;
    str[1] = '\0';
    return (str);
}

char *printf_putpointer(va_list list)
{
    long long lnbr = va_arg(list, long int);
    char *str;
    char *return_str;

    if (lnbr == 0)
        return_str = my_strdup("(nil)");
    else {
        str = printf_putnbr_pointer(lnbr);
        return_str = my_strcat(my_strdup("0x"), str);
    }
    return (return_str);
}

char *printf_showstr(va_list list)
{
    char *str = va_arg(list, char *);
    char *return_str = my_printf_showstr(str);

    return (return_str);
}

char *printf_percentage(va_list list)
{
    va_list ap;
    int oui = 0;
    char *str = my_strdup("%");

    va_copy(ap, list);
    oui = va_arg(ap, int);
    oui++;
    return (str);
}