/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** load_random_map
*/

#include "world.h"

static grid_point_t **create_random_grid(int x, int y, map_t *map)
{
    grid_point_t **grid = malloc(sizeof(grid_point_t *) * x);
    sfVector3f point;
    int n_rand;

    for (int i = 0; i < x; i++) {
        grid[i] = malloc(sizeof(grid_point_t) * y);
        for (int j = 0; j < y; j++) {
            n_rand = NEG_RAND(rand()) % 100;
            point = (sfVector3f){j * start_step, i * start_step, n_rand};
            (grid[i][j]).altitude = n_rand;
            (grid[i][j]).point = project_iso_point(point, map);
        }
    }
    return (grid);
}

void load_random_map(map_t *map, char *file_name)
{
    map->name = file_name;
    map->rows = start_x;
    map->columns = start_y;
    map->grid = create_random_grid(map->rows, map->columns, map);
}
