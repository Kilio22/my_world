/*
** EPITECH PROJECT, 2019
** bootstrap
** File description:
** window
*/

#include <SFML/Graphics.h>

sfRenderWindow *create_window(sfVector2u win_size,
                            sfVector2i pos, char *name, int mode)
{
    sfVideoMode video_mode = {win_size.x, win_size.y, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(video_mode, name, mode, NULL);
    sfRenderWindow_setPosition(window, pos);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_display(window);
    return (window);
}
