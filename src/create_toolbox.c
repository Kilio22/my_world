/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Creates a toolbox window
*/

#include "world.h"

void create_tool_text(toolbox_t *tool)
{
    sfFont *font = sfFont_createFromFile("assets/pixelmix.ttf");

    tool->text = malloc(sizeof(sfText *) * 6);
    for (int i = 0; i < 6; i++) {
        tool->text[i] = sfText_create();
        sfText_setString(tool->text[i], text[i]);
        sfText_setFont(tool->text[i], font);
        sfText_setCharacterSize(tool->text[i], 15);
        sfText_setFillColor(tool->text[i], sfBlue);
    }
}

void create_button(toolbox_t *toolbox)
{
    toolbox->sprites = malloc(sizeof(sfSprite *) * 6);
    toolbox->textures = malloc(sizeof(sfTexture *) * 6);
    toolbox->state = malloc(sizeof(int) * 6);
    for (int i = 0; i < 6; i++) {
        toolbox->textures[i] = sfTexture_createFromFile(icon_fp[i], NULL);
        toolbox->sprites[i] = sfSprite_create();
        sfSprite_setTexture(toolbox->sprites[i], toolbox->textures[i], sfTrue);
        sfSprite_setPosition(toolbox->sprites[i], icon_pos[i]);
        toolbox->state[i] = 0;
    }
}

toolbox_t *create_toolbox(void)
{
    toolbox_t *toolbox = malloc(sizeof(toolbox_t));
    sfVector2u tvec = {150, 900};

    create_button(toolbox);
    toolbox->clock = sfClock_create();
    toolbox->win = create_window(tvec, toolbox_pos, "Tool_box", 5);
    toolbox->state[0] = 2;
    sfSprite_setColor(toolbox->sprites[0], sfRed);
    create_tool_text(toolbox);
    return (toolbox);
}
