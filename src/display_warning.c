/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** display_warning
*/

#include "world.h"

sfText *create_text_warning(const char *str)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/pixelmix.ttf");

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setPosition(text, (sfVector2f){0, 16});
    sfText_setCharacterSize(text, 30);
    sfText_setFillColor(text, sfRed);
    return (text);
}

void analyse_event_warning(sfEvent event, sfRenderWindow *win)
{
    if (event.type == sfEvtClosed || event.type == sfEvtKeyPressed)
        sfRenderWindow_close(win);
}

void display_warning(const char *str)
{
    sfVector2u win_size = {1300, 100};
    sfVector2i win_pos = {100, 540};
    sfEvent event;
    sfText *text = create_text_warning(str);
    sfRenderWindow *win = create_window(win_size, win_pos, "WARNING", 7);

    while (sfRenderWindow_isOpen(win)) {
        while (sfRenderWindow_pollEvent(win, &event))
            analyse_event_warning(event, win);
        sfRenderWindow_drawText(win, text, NULL);
        sfRenderWindow_display(win);
        sfRenderWindow_clear(win, sfBlack);
    }
    sfRenderWindow_destroy(win);
    sfText_destroy(text);
}

void check_warning(map_t *map)
{
    static int i = 0;

    if (i == 1)
        return;
    if (map->columns * map->rows >= 400) {
        display_warning(warning_msg);
        i++;
    }
}