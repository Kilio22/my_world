/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Creates a map (from a file or not), then returns it
*/

#include "world.h"

static grid_point_t **create_grid(int x, int y, int step, sfVector2f offset)
{
    grid_point_t **grid = malloc(sizeof(grid_point_t *) * y);
    sfVector3f point;

    for (int i = 0; i < y; i++) {
        grid[i] = malloc(sizeof(grid_point_t) * x);
        for (int j = 0; j < x; j++) {
            point = (sfVector3f){j * step, i * step, 0};
            (grid[i][j]).altitude = 0;
            (grid[i][j]).point = project_iso_point(point, offset);
        }
    }
    return (grid);
}

map_t *create_map(char *filepath)
{
    map_t *map = malloc(sizeof(map_t));
    sfVector2f view_vec = {1920, 1080};

    map->name = filepath;
    map->columns = start_x;
    map->rows = start_y;
    map->step = start_step;
    map->offset = start_offset;
    map->grid = create_grid(start_x, start_y, start_step, start_offset);
    map->view = sfView_create();
    sfView_setSize(map->view, view_vec);
    map->highlight = highlight_square;
    map->action = dig_up_square;
    map->erase = dig_down_square;
    map->mode = square;
    map->mode_view = 0;
    return (map);
}
