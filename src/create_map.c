/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Creates a map (from a file or not), then returns it
*/

#include "world.h"

static grid_point_t **create_grid(int x, int y, map_t *map)
{
    grid_point_t **grid = malloc(sizeof(grid_point_t *) * x);
    sfVector3f point;

    for (int i = 0; i < x; i++) {
        grid[i] = malloc(sizeof(grid_point_t) * y);
        for (int j = 0; j < y; j++) {
            point = (sfVector3f){j * start_step, i * start_step, 0};
            (grid[i][j]).altitude = 0;
            (grid[i][j]).point = project_iso_point(point, map);
        }
    }
    return (grid);
}

static void load_base_config(map_t *map)
{
    map->step = start_step;
    map->offset = start_offset;
    map->angle_degrees[0] = start_angle_x;
    map->angle_degrees[1] = start_angle_y;
    map->angle[0] = IN_RADIANS(start_angle_x);
    map->angle[1] = IN_RADIANS(start_angle_y);
}

static void load_blank_map(map_t *map)
{
    map->name = prompt_user_input();
    map->rows = start_x;
    map->columns = start_y;
    map->grid = create_grid(map->rows, map->columns, map);
}

map_t *create_map(char *filepath)
{
    map_t *map = malloc(sizeof(map_t));

    if (filepath == NULL) {
        load_blank_map(map);
    } else {
        if (load_map(map, filepath) == -1)
            return (NULL);
    }
    load_base_config(map);
    return (map);
}
