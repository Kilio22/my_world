/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** Function the reproduces the behaviour of the printf syscall
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "my_printf.h"
#include "my_string.h"
#include "my_stdio.h"

static int my_printf_verifystr(char const *str)
{
    int i = 0;

    while (my_char_isin(str[i], flag_chars))
        i++;
    while (my_char_isnum(str[i]))
        i++;
    if (str[i] == '.') {
        i++;
        while (my_char_isnum(str[i]))
            i++;
    }
    while (my_char_isin(str[i], length_modifiers))
        i++;
    if (my_char_isin(str[i], conversion_specifiers))
        return (1);
    return (0);
}

static char *my_init_printfstr(va_list list, char const *str)
{
    int len = my_strlen(str);
    char *return_str = my_strdup(str);

    for (int i = 0; i < 12; i++) {
        if (my_strcmp(&str[len - 1], (SP_FUNCS[i]).op_symbol) == 0) {
            free(return_str);
            return_str = (SP_FUNCS[i]).pointer(list);
            return (return_str);
        }
    }
    return (return_str);
}

static int my_printf_display(char **array, va_list list, char *str)
{
    int i;
    char **end_array = malloc(sizeof(char *) * (my_arraylen(array) + 1));

    for (i = 0; array[i] != 0; i++) {
        if (array[i][0] == '%' && my_printf_verifystr(&array[i][1]) == 1) {
            end_array[i] = my_init_printfstr(list, &array[i][1]);
            end_array[i] = analyse_flags(end_array[i], array[i]);
        }
        else
            end_array[i] = my_strdup(array[i]);
    }
    end_array[i] = 0;
    for (i = 0; end_array[i] != 0; i++)
        str = my_strcpycat(str, end_array[i]);
    my_free_fields(array);
    my_free_fields(end_array);
    return (my_strlen(str));
}

static char *cleanup_str(char *str)
{
    int len = my_strlen(str);
    char *return_str;

    if (str[len - 1] == '%') {
        return_str = my_strndup(str, len - 1);
        free(str);
        return (return_str);
    }
    return (str);
}

int my_vsprintf(char *str, const char *format, va_list ap)
{
    char *str1 = cleanup_str(my_strdup(format));
    char **array = my_str_to_printf_array(str1);
    int len = 0;

    len = my_printf_display(array, ap, str);
    free(str1);
    return (len);
}