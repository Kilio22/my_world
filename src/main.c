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

int display_help(void)
{
    my_puts("USAGE");
    my_puts("\t./my_world [*.world]");
    my_puts(
"\t[*.world]: OPTIONNAL, file with good parameters to be loaded as a map");
    my_puts("DESCRIPTION");
    my_puts("\tMy_world is a terraformer.");
    my_putstr(
"\tYou can load a map saved or created by yourself by giving it as parameter");
    my_puts(" (see the .legend file to create a valid map).");
    my_putstr("\tIf you don't put any parameter, a window will invite you to ");
    my_putstr("enter the name of your map. If you enter an existant map, ");
    my_puts("it will be loaded, on the contrary it will be created.");
    my_putstr("\tOnce the map loaded, you'll be able to modify it by using ");
    my_puts("tools in the toolbox. Click on the tools to use them!");
    my_puts("\tIf you close the map, the program will exit and save your map.");
    my_putstr("\tDuring the game, if you load a map by using the tool, the ");
    my_puts("map will be save only if you click on the save tool.");
    return (0);
}

int main(int argc, char *argv[])
{
    if (argc == 2 && my_strcmp("-h", argv[1]) == 0)
        return (display_help());
    return (launch_editor(argc, argv));
}
