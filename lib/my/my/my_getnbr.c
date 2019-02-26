/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** Gets an int out of a given string
*/

#include "my.h"
#include "my_string.h"

int my_getnbr(char const *str)
{
    int i;
    long long result = 0;
    int is_result_negative = 0;
    int length = my_strlen(str);

    for (i = 0; str[i] < '0' || str[i] > '9'; i++) {
        if ((str[i] - '-') == 0)
            is_result_negative++;
        if (str[i] != '-' && str[i] != '+')
            return (0);
    }
    for (; i < length && (str[i] >= '0' && str[i] <= '9'); i++) {
        result = result * 10 + (str[i] - '0');
        if (result < -2147483648 || result > 2147483647)
            return (0);
    }
    if (is_result_negative % 2 == 1)
        result *= -1;
    return (result);
}
