/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** apply_buttons_effects
*/

#include "world.h"

void apply_buttons_eff_s(toolbox_t *tool, int i, interface_t *face, map_t *map)
{
    void (*adds[4])(map_t *) = {add_column, delete_column, add_row, delete_row};

    if (i == 6 && tool->state[i] == 1)
        reset_map_altitude(map);
    if (i >= 7 && i <= 10 && tool->state[i] == 1)
        adds[i - 7](map);
    if (i == 12 && tool->state[i] == 1)
        save_map(map);
    if (i == 13 && tool->state[i] == 1)
        load_new_map(face, map);
}

void apply_buttons_effect(toolbox_t *tool, int i, interface_t *face, map_t *map)
{
    if (i == 0 && face->mode == square)
        face->action = dig_up_square;
    if (i == 0 && face->mode == corner)
        face->action = dig_up_corner;
    if (i == 1 && face->mode == square)
        face->action = dig_down_square;
    if (i == 1 && face->mode == corner)
        face->action = dig_down_corner;
    if (tool->state[0] == 0 && tool->state[1] == 0 && face->mode == square)
        face->action = reset_square;
    if (tool->state[0] == 0 && tool->state[1] == 0 && face->mode == corner)
        face->action = reset_corner;
    apply_buttons_eff_s(tool, i, face, map);
}
