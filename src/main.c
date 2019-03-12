/*
** EPITECH PROJECT, 2019
** Repo_starter
** File description:
** main
*/

#include "world.h"

int main(void)
{
    toolbox_t *toolbox = create_toolbox();
    interface_t *interface = create_interface();
    map_t *map = create_map(NULL);

    loop_editor(interface, map, toolbox);
    destroy_map(map);
    return (0);
}
