/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** destroy_toolbox
*/

#include "world.h"

void destroy_toolbox(toolbox_t *tool)
{
    for (int i = 0; i < NB_BUTTONS; i++) {
        sfSprite_destroy(tool->sprites[i]);
        sfTexture_destroy(tool->textures[i]);
        sfText_destroy(tool->text[i]);
    }
    sfClock_destroy(tool->clock);
    sfSoundBuffer_destroy(tool->buffer);
    sfSound_destroy(tool->sound);
    free(tool);
}