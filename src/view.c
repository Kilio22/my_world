/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** zoom
*/

#include "world.h"

void reset_view(map_t *map)
{
    sfVector2f view_vec = {1920, 1080};

    map->offset = start_offset;
    sfView_destroy(map->view);
    map->view = sfView_create();
    update_points(map);
    sfView_setSize(map->view, view_vec);
}

void manage_zoom_at(sfVector2i m, map_t *map, float zoom, sfRenderWindow *win)
{
    sfVector2f vector = sfRenderWindow_mapPixelToCoords(win, m, map->view);
    sfView_zoom(map->view, zoom);
    sfRenderWindow_setView(win, map->view);
    sfVector2f vector2 = sfRenderWindow_mapPixelToCoords(win, m, map->view);
    sfVector2f offset;
    offset.x = vector.x - vector2.x;
    offset.y = vector.y - vector2.y;
    sfView_move(map->view, offset);
    sfRenderWindow_setView(win, map->view);
}

void manage_zoom(sfRenderWindow *win, map_t *map, sfEvent event)
{
    if (event.mouseWheel.delta == 1)
        manage_zoom_at(sfMouse_getPositionRenderWindow(win), map, 0.9, win);
    if (event.mouseWheel.delta == -1)
        manage_zoom_at(sfMouse_getPositionRenderWindow(win), map, 1.1, win);
}