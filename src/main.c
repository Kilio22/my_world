/*
** EPITECH PROJECT, 2019
** Repo_starter
** File description:
** main
*/

#include "world.h"
#include "my_stdio.h"

int main(int argc, char *argv[])
{
    interface_t *interface = create_interface();
    toolbox_t *toolbox = create_toolbox();
    char *map_name = NULL;
    map_t *map;

    if (argc == 2)
        map_name = argv[1];
    map = create_map(map_name);
    if (map == NULL) {
        my_puts("Given file is corrupted or inexistant.");
        return (84);
    }
    loop_editor(interface, map, toolbox);
    destroy_map(map);
    return (0);
}
