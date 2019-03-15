/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Loads the given map
*/

#include "world.h"
#include "my_string.h"

static grid_point_t **create_grid(int x, int y, int **points, map_t *map)
{
    grid_point_t **grid = malloc(sizeof(grid_point_t *) * x);
    sfVector3f point;

    for (int i = 0; i < x; i++) {
        grid[i] = malloc(sizeof(grid_point_t) * y);
        for (int j = 0; j < y; j++) {
            point = (sfVector3f){j * start_step, i * start_step, points[i][j]};
            (grid[i][j]).altitude = points[i][j];
            (grid[i][j]).point = project_iso_point(point, map);
        }
        free(points[i]);
    }
    free(points);
    return (grid);
}

int load_map(map_t *map, char *filepath)
{
    FILE *stream = open_file(filepath);
    int **points;

    if (stream == NULL)
        return (-1);
    map->name = filepath;
    get_size_of_map(stream, map);
    if (map->rows <= 0 || map->columns <= 0)
        return (-1);
    points = get_points(stream, map);
    if (points == NULL)
        return (-1);
    map->grid = create_grid(map->rows, map->columns, points, map);
    return (0);
}
