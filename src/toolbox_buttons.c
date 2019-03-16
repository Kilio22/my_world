/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** toolbox_buttons
*/

#include "world.h"

int is_on_button_bool(sfSprite *sprite, sfVector2f mouse)
{
    sfFloatRect button_pos;
    sfFloatRect mouse_pos = {mouse.x, mouse.y, 1, 1};

    button_pos = sfSprite_getGlobalBounds(sprite);
    if (sfFloatRect_intersects(&button_pos, &mouse_pos, NULL))
        return (1);
    return (0);
}

void change_sprite(toolbox_t *toolbox, int i, interface_t *face)
{
    if (i == 2 && toolbox->state[i] == 0) {
        toolbox->state[i] = 1;
        toolbox->textures[i] = sfTexture_createFromFile(icon_fp[14], NULL);
        sfSprite_setTexture(toolbox->sprites[i], toolbox->textures[i], sfTrue);
        sfSprite_setColor(toolbox->sprites[i], sfWhite);
        return (change_mode(face));
    }
    if (i == 2 && toolbox->state[i] == 2) {
        toolbox->state[i] = 0;
        toolbox->textures[i] = sfTexture_createFromFile(icon_fp[2], NULL);
        sfSprite_setTexture(toolbox->sprites[i], toolbox->textures[i], sfTrue);
        sfSprite_setColor(toolbox->sprites[i], sfWhite);
        change_mode(face);
    }
}

void check_buttons_state(toolbox_t *toolbox, int i, interface_t *face,
map_t *map)
{
    if (i == 2)
        return (change_sprite(toolbox, i, face));
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
    apply_buttons_effect(toolbox, i, face, map);
}

void is_on_button(toolbox_t *toolbox, sfVector2f mouse, interface_t *face,
map_t *map)
{
    sfFloatRect button_pos;
    sfFloatRect mouse_pos = {mouse.x, mouse.y, 1, 1};

    for (int i = 0; i < NB_BUTTONS; i++) {
        button_pos = sfSprite_getGlobalBounds(toolbox->sprites[i]);
        if (sfFloatRect_intersects(&button_pos, &mouse_pos, NULL)) {
            sfSound_play(toolbox->sound);
            return (check_buttons_state(toolbox, i, face, map));
        }
    }
}
