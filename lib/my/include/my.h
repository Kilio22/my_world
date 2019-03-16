/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** Header for libmy.a
*/

#pragma once

#include <stdio.h>

/* my_char_is */
int my_char_isnum(char const c);
int my_char_islower(char const c);
int my_char_isupper(char const c);
int my_char_isalphanum(char const c);
int my_char_isprintable(char const c);
int my_char_isin(char const c, char const *src);

/* my_str_is */
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_str_isnum(char const *str, int negs);

/* my_put */
int my_put_nbr(int nb);
int my_showstr(char const *str);

/* my_str */
char *my_revstr(char *str);
char *my_strlowcase(char *str);
char *my_strstr(char *str, char const *to_find);
char *my_str_addchar(char const *str, char const c, int index);
/* almost same but lesser useful */
int my_str_to_int(const char *str);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);

/* array stuff */
void my_free_fields(char **array);

/* int stuff */
int my_getnbr(char const *str);
