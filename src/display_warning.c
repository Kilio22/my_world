/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** display_warning
*/

#include "world.h"
#include "my_stdio.h"
#include "my_string.h"

int check_clock_warning(sfClock *clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 2) {
        sfClock_restart(clock);
        return (1);
    }
    return (0);
}

sfText *create_text_warning(void)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/pixelmix.ttf");
    char *str = my_strdup(
"      Be careful ! If you try to work on a really big map, \n");

    str = my_realloc_str(str,
"  your computer will have a hard time working at full speed !");
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setPosition(text, (sfVector2f){0, 16});
    sfText_setCharacterSize(text, 30);
    sfText_setFillColor(text, sfRed);
    return (text);
}

void analyse_event_warning(sfEvent event, sfRenderWindow *win, sfClock *clock)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(win);
    if (check_clock_warning(clock) == 0)
        return;
    if (event.type == sfEvtKeyPressed)
        sfRenderWindow_close(win);
}

void display_warning(void)
{
    sfVector2u win_size = {1300, 100};
    sfVector2i win_pos = {100, 540};
    sfEvent event;
    sfClock *clock = sfClock_create();
    sfText *text = create_text_warning();
    sfRenderWindow *win = create_window(win_size, win_pos, "WARNING", 7);

    while (sfRenderWindow_isOpen(win)) {
        while (sfRenderWindow_pollEvent(win, &event))
            analyse_event_warning(event, win, clock);
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
        display_warning();
        i++;
    }
}