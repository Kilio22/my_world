/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Contains the global constant variables
*/

#include "world.h"

const int start_x = 10;
const int start_y = 10;
const int start_step = 64;
/* sfGreen doesn't work */
const sfColor start_color = {0, 255, 0, 255};
const sfVector2f start_offset = {500.0, 200.0};
const char *input_font_path = "assets/pixelmix.ttf";
const char *cursor_path = "assets/main_cursor.png";
const sfColor toolbox_color = {189, 195, 199, 255};
const char *icone_fp[7] = {
    "assets/icone/dig_up.png",
    "assets/icone/dig_down.png",
    "assets/icone/tiles.png",
    "assets/icone/rotate.png",
    "assets/icone/zoom_in.png",
    "assets/icone/zoom_out.png",
    "assets/icone/corner.png"
    };
const sfVector2f icone_pos[6] = {
    {10, 10},
    {80, 10},
    {30, 80},
    {42, 140},
    {10, 220},
    {80, 220}
};
