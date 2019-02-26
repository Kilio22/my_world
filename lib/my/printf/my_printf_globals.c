/*
** EPITECH PROJECT, 2018
** my_printf_globals.c
** File description:
** Global variables used in the my_printf function
*/

#include "my_printf.h"

const sp_t SP_FUNCS[] = {
    {"d", &printf_put_nbr},
    {"i", &printf_put_nbr},
    {"s", &printf_putstr},
    {"S", &printf_showstr},
    {"c", &printf_putchar},
    {"p", &printf_putpointer},
    {"u", &printf_putnbr_dec},
    {"o", &printf_putnbr_oct},
    {"x", &printf_putnbr_hexlower},
    {"X", &printf_putnbr_hexupper},
    {"b", &printf_putnbr_bin},
    {"%", &printf_percentage}
};

char const signed_conversions[4] = "dip\0";
char const alternate_forms[4] = "oxX\0";
char const flag_chars[6] = "#0+ -\0";
char const length_modifiers[3] = "lh\0";
char const conversion_specifiers[13] = "disScpuoxXb%\0";
char const integer_conversions[9] = "diouxXbp\0";
char const whole_flags[30] = "#+- 0123456789.hldiuoxXcsSpb%\0";