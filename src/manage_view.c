/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** zoom
*/

#include "world.h"

int check_clock_status(toolbox_t *tool)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(tool->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        sfClock_restart(tool->clock);
        return (1);
    }
    return (0);
}

void check_zoom(toolbox_t *tool, interface_t *face)
{
    sfVector2u vect = sfRenderWindow_getSize(face->window);
    sfVector2i real_vect = {vect.x / 2, vect.y / 2};

    if (check_clock_status(tool) == 0)
        return;
    if (tool->state[4] == 1)
        manage_zoom_at(real_vect, face, 0.9);
    if (tool->state[5] == 1)
        manage_zoom_at(real_vect, face, 1.1);
}

void reset_view(interface_t *face, map_t *map)
{
    sfVector2u size = sfRenderWindow_getSize(face->window);

    map->offset = start_offset;
    sfView_destroy(face->view);
    face->view = sfView_create();
    update_points(map);
    sfView_setSize(face->view, (sfVector2f){size.x, size.y});
}

void manage_zoom_at(sfVector2i m, interface_t *face, float zoom)
{
    sfVector2f vector = sfRenderWindow_mapPixelToCoords(face->window, m,
face->view);
    sfVector2f vector2;
    sfVector2f offset;

    sfView_zoom(face->view, zoom);
    sfRenderWindow_setView(face->window, face->view);
    vector2 = sfRenderWindow_mapPixelToCoords(face->window, m, face->view);
    offset.x = vector.x - vector2.x;
    offset.y = vector.y - vector2.y;
    sfView_move(face->view, offset);
    sfRenderWindow_setView(face->window, face->view);
}

void manage_zoom(interface_t *face, sfEvent event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(face->window);

    if (event.mouseWheel.delta == 1)
        manage_zoom_at(mouse_pos, face, 0.9);
    if (event.mouseWheel.delta == -1)
        manage_zoom_at(mouse_pos, face, 1.1);
}
