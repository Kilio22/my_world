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
    interface_t *interface;
    char *map_name = NULL;
    toolbox_t *toolbox;
    map_t *map;

    if (argc == 2)
        map_name = argv[1];
    map = create_map(map_name);
    if (map == NULL) {
        my_puts("Given file is corrupted or inexistant.");
        return (84);
    }
    toolbox = create_toolbox();
    interface = create_interface();
    loop_editor(interface, map, toolbox);
    destroy_map(map);
    return (0);
}
