/*
** EPITECH PROJECT, 2019
** bootstrap
** File description:
** window
*/

#include <SFML/Graphics.h>

/* le prototype est ptet pas à la norme, il faudra demander à check la L2 */
sfRenderWindow *create_window(unsigned int width, unsigned int height,
                              unsigned int fps, char *name)
{
    sfVideoMode video_mode = {width, height, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(video_mode, name, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, fps);
    sfRenderWindow_setMouseCursorVisible(window, 0);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_display(window);
    return (window);
}
