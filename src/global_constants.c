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
const int window_x = 1530;
const int window_y = 1080;
const int start_angle_x = 45;
const int start_angle_y = 35;
const sfVector2i toolbox_pos = {1540, 100};
const sfColor start_color = {0, 255, 0, 255};
const sfColor trans_white = {255, 255, 255, 130};
const sfColor hover = {255, 255, 204, 255};
const sfVector2f start_offset = {500.0, 200.0};
const char *input_font_path = "assets/pixelmix.ttf";
const char *cursor_path = "assets/main_cursor.png";
const sfColor toolbox_color = {189, 195, 199, 255};
const char *icon_fp[12] = {
    "assets/icone/dig_up.png",
    "assets/icone/dig_down.png",
    "assets/icone/tiles.png",
    "assets/icone/rotate.png",
    "assets/icone/zoom_in.png",
    "assets/icone/zoom_out.png",
    "assets/icone/reset.png",
    "assets/icone/incr1.png",
    "assets/icone/incr2.png",
    "assets/icone/incr3.png",
    "assets/icone/incr4.png",
    "assets/icone/corner.png"
};
const sfVector2f icon_pos[11] = {
    {10, 10},
    {80, 10},
    {30, 80},
    {42, 140},
    {10, 220},
    {80, 220},
    {30, 290},
    {10, 370},
    {80, 370},
    {10, 440},
    {80, 440}
};
const char *tile_textures[6] = {
    "assets/sprites/grass.png",
    "assets/sprites/dirt2.png",
    "assets/sprites/dirt.png",
    "assets/sprites/sand.png",
    "assets/sprites/stone.png",
    "assets/sprites/stone2.png"
};
const char *text[11] = {
    "Dig Up",
    "Dig Down",
    "Tile/Corner",
    "Rotate Mode",
    "Zoom in",
    "Zoom out",
    "Reset map",
    "+1 column",
    "-1 column",
    "+1 row",
    "-1 row"
};
const char *warning_msg =
"      Be careful ! If you try to work on a really big map, \n\
  your computer will have a hard time working at full speed !";
