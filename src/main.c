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

static int launch_editor(int argc, char *argv[])
{
    char *map_name = NULL;
    map_t *map;

    if (argc >= 2 && my_strcmp(argv[1], "-r")) {
        if (!my_str_ends_with(argv[1], ".world")) {
            my_puts("Bad file extention (can only load .world files)");
            return (84);
        } else
            map_name = my_strdup(argv[1]);
    }
    map = create_map((argc == 2 && map_name == NULL) ? "-r" : map_name);
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

int display_help(void)
{
    my_puts("USAGE");
    my_puts("\t./my_world [*.world] | [-r]");
    my_puts(
"\t*.world: a file that can be loaded as a map (check .legend for more info).");
    my_putstr("\t-r: generates a random map. Giving an already existing file");
    my_puts(" name in the window popup will NOT make this flag effective.");
    my_puts("DESCRIPTION");
    my_puts("\tMy_world is a world editor, you can terraform your own world!");
    my_puts("\tYou can load a saved map by giving it as a parameter.");
    my_putstr("\tIf you don't give any field, you will have to enter a name ");
    my_putstr("for your new map in the window popup. ");
    my_putstr("Entering the path of an existing map will make it ");
    my_puts("be loaded instead.");
    my_puts("\tMind that you don't have to put the .world when giving a name.");
    my_putstr("\tOnce the map is loaded, you'll be able to modify it by using");
    my_puts(" the tools located in the toolbox. Try clicking on them!");
    my_puts("\tExiting the program at anytime will make it save your map.");
    my_putstr("\tWhile editing, loading a new map will not save the ");
    my_puts("current one (unless you manually save it of course).");
    return (0);
}

int main(int argc, char *argv[])
{
    if (argc == 2 && my_strcmp("-h", argv[1]) == 0)
        return (display_help());
    setup_random_seed();
    return (launch_editor(argc, argv));
}
