/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** zoom
*/

#include "world.h"

void check_zoom(toolbox_t *tool, sfRenderWindow *win1, map_t *map)
{
    sfVector2u vect = sfRenderWindow_getSize(win1);
    sfVector2i real_vect = {vect.x / 2, vect.y / 2};

    if (tool->state[4] == 1)
        manage_zoom_at(real_vect, map, 0.9, win1);
    if (tool->state[5] == 1)
        manage_zoom_at(real_vect, map, 1.1, win1);
}

void reset_view(sfRenderWindow *win, map_t *map)
{
    sfVector2u size = sfRenderWindow_getSize(win);

    map->offset = start_offset;
    sfView_destroy(map->view);
    map->view = sfView_create();
    update_points(map);
    sfView_setSize(map->view, (sfVector2f){size.x, size.y});
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
