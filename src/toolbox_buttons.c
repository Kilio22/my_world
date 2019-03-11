/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** toolbox_buttons
*/

#include "world.h"

void change_sprite(toolbox_t *toolbox, int i, map_t *map)
{
    if (i == 2 && toolbox->state[i] == 0) {
        toolbox->state[i] = 1;
        toolbox->textures[i] = sfTexture_createFromFile(icone_fp[6], NULL);
        sfSprite_setTexture(toolbox->sprites[i], toolbox->textures[i], sfTrue);
        sfSprite_setColor(toolbox->sprites[i], sfWhite);
        change_mode(map);
        return;
    }
    if (i == 2 && toolbox->state[i] == 2) {
        toolbox->state[i] = 0;
        toolbox->textures[i] = sfTexture_createFromFile(icone_fp[2], NULL);
        sfSprite_setTexture(toolbox->sprites[i], toolbox->textures[i], sfTrue);
        sfSprite_setColor(toolbox->sprites[i], sfWhite);
        change_mode(map);
    }
}

void check_buttons_state(toolbox_t *toolbox, int i, map_t *map)
{
    if (i == 2)
        return (change_sprite(toolbox, i, map));
    if (toolbox->state[i] == 0) {
        sfSprite_setColor(toolbox->sprites[i], sfYellow);
        toolbox->state[i] = 1;
    }
    if (toolbox->state[i] == 2) {
        sfSprite_setColor(toolbox->sprites[i], sfWhite);
        toolbox->state[i] = 0;
    }
    if (i == 0 && toolbox->state[1] == 2) {
        sfSprite_setColor(toolbox->sprites[1], sfWhite);
        toolbox->state[1] = 0;
    }
    if (i == 1 && toolbox->state[0] == 2) {
        sfSprite_setColor(toolbox->sprites[0], sfWhite);
        toolbox->state[0] = 0;
    }
}

void is_on_button(toolbox_t *toolbox, sfVector2f mouse, map_t *map)
{
    sfFloatRect button_pos;
    sfFloatRect mouse_pos = {mouse.x, mouse.y, 1, 1};

    for (int i = 0; i < 6; i++) {
        button_pos = sfSprite_getGlobalBounds(toolbox->sprites[i]);
        if (sfFloatRect_intersects(&button_pos, &mouse_pos, NULL)) {
            return (check_buttons_state(toolbox, i, map));
        }
    }
}