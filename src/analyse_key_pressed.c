/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** keyboard
*/

#include "world.h"

void change_mode(interface_t *face)
{
    if (face->mode == square) {
        face->mode = corner;
        face->highlight = highlight_corner;
        face->action = dig_up_corner;
    } else {
        face->mode = square;
        face->highlight = highlight_square;
        face->action = dig_up_square;
    }
}

static void analyse_arrows(interface_t *face, sfKeyCode key, map_t *map)
{
    if (face->viewmode == translation)
        manage_translation(key, map);
    else if (face->viewmode == rotation)
        manage_rotate(key, map);
}

void analyse_key_pressed(interface_t *face, map_t *map, sfKeyCode key,
                         toolbox_t *tool)
{
    if (key == sfKeySpace)
        reset_view(face, map);
    if (key >= sfKeyLeft && key <= sfKeyDown)
        analyse_arrows(face, key, map);
    if (key == sfKeyS)
        change_sprite(tool, 2, face);
    if (key == sfKeyR)
        face->viewmode = (face->viewmode == rotation) ? translation : rotation;
    if (key == sfKeyT && !sfRenderWindow_isOpen(tool->win))
        tool->win = create_window(150, 1080, toolbox_pos, "Tool_box");
}
