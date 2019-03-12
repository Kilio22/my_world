/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Creates a toolbox window
*/

#include "world.h"

toolbox_t *create_toolbox(void)
{
    toolbox_t *toolbox = malloc(sizeof(toolbox_t));

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
    toolbox->win = create_window(150, 1080, toolbox_pos, "Tool_box");
    return (toolbox);
}
