/*
** EPITECH PROJECT, 2019
** bootstrap
** File description:
** window
*/

#include "world.h"

void create_window(princi_t *princi)
{
    sfVideoMode     video_mode;

    video_mode.width = 1920;
    video_mode.height = 1080;
    video_mode.bitsPerPixel = 32;

    princi->window = sfRenderWindow_create(video_mode,
    "My_world", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(princi->window, 60);
    // sfRenderWindow_setMouseCursorVisible(princi->window, 0);
}
