/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** load_new_map
*/

#include "world.h"
#include "my_stdio.h"
#include "my_string.h"

void change_map_name(interface_t *face, map_t *map)
{
    char *map_name = request_map_name();
    char *win_name = my_strdup("Currently editing \"");

    win_name = my_strcat(win_name, my_strdup(map_name));
    win_name = my_strcat(win_name, my_strdup("\""));
    map->name = map_name;
    sfRenderWindow_setTitle(face->window, win_name);
}

void load_new_map(interface_t *face, map_t *map)
{
    char *map_name = request_map_name();
    char *win_name = my_strdup("Currently editing \"");

    win_name = my_strcat(win_name, my_strdup(map_name));
    win_name = my_strcat(win_name, my_strdup("\""));
    if (set_map(map, map_name) == NULL) {
        map->name = NULL;
        my_puts("Given file is invalid or inexistant.");
        return;
    }
    sfRenderWindow_setTitle(face->window, win_name);
}
