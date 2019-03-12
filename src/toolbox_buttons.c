/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** toolbox_buttons
*/

#include "world.h"

void apply_buttons_effect(toolbox_t *tool, int i, interface_t *face)
{
    if (i == 0 && face->mode == square)
        face->action = dig_up_square;
    if (i == 0 && face->mode == corner)
        face->action = dig_up_corner;
    if (i == 1 && face->mode == square)
        face->action = dig_down_square;
    if (i == 1 && face->mode == corner)
        face->action = dig_down_corner;
    if (tool->state[0] == 0 && tool->state[1] == 0)
        face->action = dig_nothing;
}

void change_sprite(toolbox_t *toolbox, int i, interface_t *face)
{
    if (i == 2 && toolbox->state[i] == 0) {
        toolbox->state[i] = 1;
        toolbox->textures[i] = sfTexture_createFromFile(icon_fp[6], NULL);
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

void check_buttons_state(toolbox_t *toolbox, int i, interface_t *face)
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
    apply_buttons_effect(toolbox, i, face);
}

void is_on_button(toolbox_t *toolbox, sfVector2f mouse, interface_t *face)
{
    sfFloatRect button_pos;
    sfFloatRect mouse_pos = {mouse.x, mouse.y, 1, 1};

    for (int i = 0; i < 6; i++) {
        button_pos = sfSprite_getGlobalBounds(toolbox->sprites[i]);
        if (sfFloatRect_intersects(&button_pos, &mouse_pos, NULL)) {
            return (check_buttons_state(toolbox, i, face));
        }
    }
}
