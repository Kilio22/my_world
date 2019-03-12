/*
** EPITECH PROJECT, 2019
** Repo_starter
** File description:
** main
*/

#include "world.h"

int main(void)
{
    interface_t *interface = create_interface();
    map_t *map = create_map(NULL);
    toolbox_t *toolbox = create_toolbox();

    loop_editor(interface, map, toolbox);
    destroy_map(map);
    return (0);
}
