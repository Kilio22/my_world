/*
** EPITECH PROJECT, 2019
** Repo_starter
** File description:
** main
*/

#include "world.h"

int main(void)
{
    sfRenderWindow *window = create_window(1920, 1080, 60, "World editer");
    map_t *map = create_map(NULL);

    loop_editor(window, map);
    destroy_map(map);
    return (0);
}
