/*
** EPITECH PROJECT, 2018
** printf.h
** File description:
** Header for printf function
*/

#pragma once

#include <stdarg.h>
#include <stdio.h>

/* Printf functions */
int my_printf(const char *format, ...);
int my_vprintf(const char *format, va_list ap);
int my_dprintf(int fd, const char *format, ...);
int my_vdprintf(int fd, const char *format, va_list ap);
int my_fprintf(FILE *stream, const char *format, ...);
int my_vfprintf(FILE *stream, const char *format, va_list ap);
int my_sprintf(char *str, const char *format, ...);
int my_vsprintf(char *str, const char *format, va_list ap);

/* Functions used in the printf functions */
char **my_str_to_printf_array(char const *str);
char *analyse_flags(char *str, char const *src);
char *analyse_precision(char *str, char const *src);
char *analyse_fieldwidth(char *str, char const *src, char const *flags);
char *analyse_zeros(char *str, char const *src, char const *flags);

typedef struct specifiers_s {
    char *op_symbol;
    char *(*pointer)(va_list);
} sp_t;

char *printf_put_nbr(va_list list);
char *printf_putstr(va_list list);
char *printf_putchar(va_list list);
char *printf_putpointer(va_list list);
char *printf_showstr(va_list list);
char *printf_putnbr_oct(va_list list);
char *printf_putnbr_dec(va_list list);
char *printf_putnbr_hexlower(va_list list);
char *printf_putnbr_hexupper(va_list list);
char *printf_putnbr_bin(va_list list);
char *printf_percentage(va_list list);

extern const sp_t SP_FUNCS[];
extern const char signed_conversions[4];
extern const char alternate_forms[4];
extern const char flag_chars[6];
extern const char length_modifiers[3];
extern const char conversion_specifiers[13];
extern const char integer_conversions[9];
extern const char whole_flags[30];
