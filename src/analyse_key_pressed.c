/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** keyboard
*/

#include "world.h"

void transformation_mode(interface_t *face, toolbox_t *tool)
{
    face->viewmode = (face->viewmode == rotation) ? translation : rotation;
    if (face->viewmode == translation) {
        sfSprite_setColor(tool->sprites[3], sfWhite);
        tool->state[3] = 0;
    }
    if (face->viewmode == rotation) {
        sfSprite_setColor(tool->sprites[3], sfRed);
        tool->state[3] = 2;
    }
}

void change_mode(interface_t *face)
{
    if (face->mode == square) {
        face->mode = corner;
        face->highlight = highlight_corner;
        if (face->action == reset_square) {
            face->action = reset_corner;
            return;
        }
        face->action =
(face->action == dig_down_square ? dig_down_corner : dig_up_corner);
    } else {
        face->mode = square;
        face->highlight = highlight_square;
        if (face->action == reset_corner) {
            face->action = reset_square;
            return;
        }
        face->action =
(face->action == dig_down_corner ? dig_down_square : dig_up_square);
    }
}

static void analyse_arrows(interface_t *face, sfKeyCode key, map_t *map,
toolbox_t *tool)
{
    if (face->viewmode == translation && tool->state[3] == 0)
        manage_translation(key, map);
    else if (face->viewmode == rotation && tool->state[3] == 2)
        manage_rotate(key, map);
}

void analyse_key_pressed(interface_t *face, map_t *map, sfKeyCode key,
                        toolbox_t *tool)
{
    sfVector2u vect = {150, 900};

    if (key == sfKeyEscape) {
        sfRenderWindow_close(face->window);
        sfRenderWindow_close(tool->win);
    }
    if (key == sfKeySpace)
        reset_view(face, map);
    if (key >= sfKeyLeft && key <= sfKeyDown)
        analyse_arrows(face, key, map, tool);
    if (key == sfKeyE)
        change_sprite(tool, 2, face);
    if (key == sfKeyR)
        transformation_mode(face, tool);
    if (key == sfKeyT && !sfRenderWindow_isOpen(tool->win))
        tool->win = create_window(vect, toolbox_pos, "Tool_box", 5);
    if (key == sfKeyA)
        reset_map_altitude(map);
    if (key == sfKeyU)
        delete_column(map);
}
