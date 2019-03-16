/*
** EPITECH PROJECT, 2019
** Repo_starter
** File description:
** main
*/

#include "world.h"
#include "my_stdio.h"
#include "my_string.h"
#include "my_printf.h"

void display_map(map_t *map)
{
    my_putstr("Map name : ");
    my_puts(map->name);
    my_printf("%d %d\n", map->rows, map->columns);
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->columns; j++)
            my_printf("%d ", map->grid[i][j].altitude);
        my_putchar('\n');
    }
}

static int save_map_on_end(map_t *map)
{
    int n_return = save_map(map);

    if (n_return < 0) {
        my_puts("There was an error when saving your file.");
        return (-1);
    }
    my_putstr("Successfuly saved ");
    my_putstr(map->name);
    my_puts(" !");
    return (0);
}

static int load_editor(map_t *map)
{
    toolbox_t *toolbox = create_toolbox();
    interface_t *interface = create_interface(map->name);

    if (toolbox == NULL || interface == NULL)
        return (-1);
    loop_editor(interface, map, toolbox);
    destroy_toolbox(toolbox);
    sfMusic_destroy(interface->music);
    sfSoundBuffer_destroy(interface->buff_dig);
    sfSound_destroy(interface->sound_dig);
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
            map_name = my_strdup(argv[1]);
    }
    map = create_map(map_name);
    if (map == NULL) {
        my_puts("Given file is invalid or inexistant.");
        return (84);
    }
    load_editor(map);
    if (save_map_on_end(map) == -1)
        return (84);
    destroy_map(map);
    return (0);
}
