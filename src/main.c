/*
** EPITECH PROJECT, 2019
** Repo_starter
** File description:
** main
*/

#include "world.h"

void create_map(princi_t *princi)
{
    princi->map = malloc(sizeof(int *) * MAP_Y);
    for (int i = 0; i < MAP_Y; i++) {
        princi->map[i] = malloc(sizeof(int) * MAP_X);
        for (int j = 0; j < MAP_X; j++)
            princi->map[i][j] = 00;
    }
}

int main(void)
{
    princi_t princi;

    create_window(&princi);
    create_map(&princi);
    princi.map[3][3] = 30;
    princi.step_x = 300;
    princi.step_y = 300;
    princi.my_points = create_2d_map(princi.map, &princi);
    while (sfRenderWindow_isOpen(princi.window)) {
        if (check_event(&princi) == 1)
            break;
        draw_triangle(&princi, princi.my_points);
        draw_2d_map(&princi, princi.my_points);
        sfRenderWindow_display(princi.window);
        sfRenderWindow_clear(princi.window, sfBlack);
    }
    sfRenderWindow_close(princi.window);
    sfRenderWindow_destroy(princi.window);
    return (0);
}