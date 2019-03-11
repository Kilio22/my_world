/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Finds what point is to be dug
*/

#include "world.h"

int *transfer_indexes(int *indexes)
{
    static int *db = NULL;

    if (indexes == NULL)
        return (db);
    if (indexes == (void *) 1)
        db = NULL;
    else
        db = indexes;
    return (NULL);
}

static int set_indexes(sfRenderWindow *win, map_t *map, int i, int j)
{
    static int indexes[2];

    if (!is_closest_corner(win, map, map->grid[i][j].point))
        return (0);
    indexes[0] = i;
    indexes[1] = j;
    transfer_indexes(indexes);
    return (1);
}

void update_selected_point(sfRenderWindow *win, map_t *map)
{
    int n_return = 0;

    for (int i = map->rows - 1; i >= 0; i--) {
        for (int j = map->columns - 1; j >= 0 && n_return == 0; j--)
            n_return = set_indexes(win, map, i, j);
        if (n_return == 1)
            break;
    }
}
