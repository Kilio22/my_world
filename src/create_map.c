/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Creates a map (from a file or not), then returns it
*/

#include "world.h"

static grid_point_t **create_grid(int x, int y, int step, map_t *map)
{
    grid_point_t **grid = malloc(sizeof(grid_point_t *) * y);
    sfVector3f point;

    for (int i = 0; i < y; i++) {
        grid[i] = malloc(sizeof(grid_point_t) * x);
        for (int j = 0; j < x; j++) {
            point = (sfVector3f){j * step, i * step, 0};
            (grid[i][j]).altitude = 0;
            (grid[i][j]).point = project_iso_point(point, map);
        }
    }
    return (grid);
}

map_t *create_map(char *filepath)
{
    map_t *map = malloc(sizeof(map_t));

    map->name = filepath;
    map->columns = start_x;
    map->rows = start_y;
    map->step = start_step;
    map->offset = start_offset;
    map->angle_degrees[0] = start_angle_x;
    map->angle_degrees[1] = start_angle_y;
    map->angle[0] = IN_RADIANS(start_angle_x);
    map->angle[1] = IN_RADIANS(start_angle_y);
    map->grid = create_grid(start_x, start_y, start_step, map);
    return (map);
}
