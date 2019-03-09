/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Adds the given character to the end of the string
*/

#include <linux/limits.h>
#include "world.h"
#include "my_string.h"

static int delete_char(char *prompt)
{
    int len = my_strlen(prompt);

    if (len == 0)
        return (0);
    prompt[len - 1] = '\0';
    return (0);
}

static int check_return(char *prompt)
{
    int len = my_strlen(prompt);

    if (len == 0)
        return (0);
    else
        return (1);
    return (0);
}

static int add_char(char *prompt, char c)
{
    int len = my_strlen(prompt);

    if (len >= NAME_MAX - 1)
        return (0);
    prompt[len] = c;
    prompt[len + 1] = '\0';
    return (0);
}

int update_text(sfEvent event, char *prompt)
{
    if (event.text.unicode >= 127)
        return (-1);
    if (event.text.unicode == 8)
        return (delete_char(prompt));
    if (event.text.unicode == '\r')
        return (check_return(prompt));
    if (event.text.unicode < 32)
        return (-1);
    add_char(prompt, event.text.unicode);
    return (0);
}
