/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Digs up when called
*/

#include "world.h"

static int icr_corner_altitude(map_t *map, int i, int j)
{
    map->grid[i][j].altitude += 1;
    update_points(map);
    return (1);
}

void dig_up_corner(interface_t *face, map_t *map)
{
    int *index = transfer_indexes(NULL);

    if (index == NULL) {
        update_selected_point(face, map);
        index = transfer_indexes(NULL);
    }
    sfSound_play(face->sound_dig);
    icr_corner_altitude(map, index[0], index[1]);
}

static int icr_square_alitude(interface_t *face, map_t *map, int i, int j)
{
    if (!is_on_tile(face, &map->grid[i], j))
        return (0);
    sfSound_play(face->sound_dig);
    map->grid[i][j].altitude += 1;
    map->grid[i][j + 1].altitude += 1;
    map->grid[i + 1][j].altitude += 1;
    map->grid[i + 1][j + 1].altitude += 1;
    update_points(map);
    return (1);
}

void dig_up_square(interface_t *face, map_t *map)
{
    int n_return = 0;

    for (int i = map->rows - 2; i >= 0; i--) {
        for (int j = map->columns - 2; j >= 0 && n_return == 0; j--)
            n_return = icr_square_alitude(face, map, i, j);
        if (n_return == 1)
            break;
    }
}
