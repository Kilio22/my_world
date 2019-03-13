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
        face->action =
(face->action == dig_down_square ? dig_down_corner : dig_up_corner);
    } else {
        face->mode = square;
        face->highlight = highlight_square;
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
    if (key == sfKeySpace)
        reset_view(face, map);
    if (key >= sfKeyLeft && key <= sfKeyDown)
        analyse_arrows(face, key, map, tool);
    if (key == sfKeyS)
        change_sprite(tool, 2, face);
    if (key == sfKeyR)
        transformation_mode(face, tool);
    if (key == sfKeyT && !sfRenderWindow_isOpen(tool->win))
        tool->win = create_window(150, 1080, toolbox_pos, "Tool_box");
}
