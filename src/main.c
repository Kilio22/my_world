/*
** EPITECH PROJECT, 2019
** Repo_starter
** File description:
** main
*/

#include "world.h"
#include "my_stdio.h"
#include "my_printf.h"

void display_map(map_t *map)
{
    my_putstr("Map name : ");
    my_puts(map->name);
    my_printf("%d %d\n", map->rows, map->columns);
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->columns; j++) {
            my_printf("%d ", map->grid[i][j].altitude);
        }
        my_putchar('\n');
    }
}

static int load_editor(map_t *map)
{
    toolbox_t *toolbox = create_toolbox();
    interface_t *interface = create_interface();

    loop_editor(interface, map, toolbox);
    return (0);
}

int main(int argc, char *argv[])
{
    char *map_name = NULL;
    map_t *map;

    if (argc >= 2) {
        if (!my_str_ends_with(argv[1], ".world")) {
            my_puts("Bad file extention (can only load .world files)");
            return (84);
        } else
            map_name = argv[1];
    }
    map = create_map(map_name);
    if (map == NULL) {
        my_puts("Given file is invalid or inexistant.");
        return (84);
    }
    display_map(map);
    load_editor(map);
    destroy_map(map);
    return (0);
}
