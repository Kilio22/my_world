/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** rename_map
*/

#include "world.h"
#include "my_string.h"

char *request_map_name(void)
{
    char *name = prompt_user_input((sfVector2u){700, 50}, "Enter the map name");

    if (name == NULL)
        name = my_strdup("default");
    if (!my_str_ends_with(name, ".world"))
        name = my_strcat(name, my_strdup(".world"));
    return (name);
}
