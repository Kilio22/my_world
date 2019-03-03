/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Creates a map (from a file or not), then returns it
*/

#include "world.h"

static int **create_blank_grid(size_t x, size_t y)
{
    int **map = malloc(sizeof(int *) * y);

    for (size_t i = 0; i < y; i++) {
        map[i] = malloc(sizeof(int) * x);
        for (size_t j = 0; j < x; j++)
            map[i][j] = 0;
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
    return (map);
}
