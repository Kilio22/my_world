/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Pops and prompts text in a window
*/

#include <linux/limits.h>
#include "world.h"
#include "my_string.h"

int update_text(sfEvent event, char *prompt);

static int analyse_text_events(sfRenderWindow *win, sfEvent event, char *input)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(win);
    if (event.type == sfEvtTextEntered)
        return (update_text(event, input));
    return (0);
}

sfText *create_text(void)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(input_font_path);

    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, (sfVector2f){0.0, 0.0});
    return (text);
}

char *prompt_user_input(sfVector2u win_size, char *win_name)
{
    sfVector2i pos = {500, 500};
    sfRenderWindow *win = create_window(win_size, pos, win_name, 5);
    sfEvent event;
    int n_return = 0;
    sfText *text = create_text();
    char input[NAME_MAX] = {0};

    while (sfRenderWindow_isOpen(win)) {
        while (sfRenderWindow_pollEvent(win, &event))
            n_return = analyse_text_events(win, event, input);
        sfText_setString(text, input);
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_drawText(win, text, NULL);
        sfRenderWindow_display(win);
        if (n_return == 1)
            sfRenderWindow_close(win);
    }
    if (n_return == 0)
        return (NULL);
    return (my_strdup(input));
}
