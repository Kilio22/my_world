/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** keyboard
*/

#include "world.h"

static void change_mode(map_t *map)
{
    if (map->mode == square) {
        map->mode = corner;
        map->highlight = highlight_corner;
        map->action = dig_up_corner;
        map->erase = dig_down_corner;
    } else {
        map->mode = square;
        map->highlight = highlight_square;
        map->action = dig_up_square;
        map->erase = dig_down_square;
    }
}

static void manage_arrows(sfKeyCode key, map_t *map)
{
    if (key == sfKeyLeft)
        map->offset.x += 15;
    if (key == sfKeyRight)
        map->offset.x -= 15;
    if (key == sfKeyDown)
        map->offset.y -= 15;
    if (key == sfKeyUp)
        map->offset.y += 15;
    update_points(map);
}

void analyse_key_pressed(sfKeyCode key, map_t *map)
{
    if (key == sfKeySpace)
        reset_view(map);
    if (key >= sfKeyLeft && key <= sfKeyDown)
        manage_arrows(key, map);
    if (key == sfKeyS)
        change_mode(map);
}
