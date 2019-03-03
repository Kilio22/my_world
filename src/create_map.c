/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Creates a map (from a file or not), then returns it
*/

#include "world.h"

sfColor **create_color_tab(int rows, int columns)
{
    sfColor **colors = malloc(sizeof(sfColor *) * rows);

    for (int i = 0; i < rows; i++) {
        colors[i] = malloc(sizeof(sfColor) * columns);
        for (int j = 0; j < columns; j++)
            colors[i][j] = sfRed;
    }
    return (colors);
}

static int **create_blank_grid(int x, int y)
{
    int **map = malloc(sizeof(int *) * y);

    for (int i = 0; i < y; i++) {
        map[i] = malloc(sizeof(int) * x);
        for (int j = 0; j < x; j++)
            map[i][j] = 00;
    }
    return (map);
}

map_t *create_map(char *filepath)
{
    map_t *map = malloc(sizeof(map_t));

    map->name = filepath;
    map->grid = create_blank_grid(INIT_MAP_X, INIT_MAP_Y);
    map->props.columns = INIT_MAP_X;
    map->props.rows = INIT_MAP_Y;
    map->props.step = STEP_WINDOW;
    map->props.offset = (sfVector2f){INIT_MAP_OFFSET, INIT_MAP_OFFSET};
    map->points = create_2d_map(map);
    map->colors = create_color_tab(map->props.rows, map->props.columns);
    return (map);
}
