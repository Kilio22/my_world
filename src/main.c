/*
** EPITECH PROJECT, 2019
** Repo_starter
** File description:
** main
*/

#include "world.h"

toolbox_t *create_toolbox(void)
{
    toolbox_t *toolbox = malloc(sizeof(toolbox_t));
    sfVector2i pos2 = {1450, 0};

    toolbox->sprites = malloc(sizeof(sfSprite *) * 3);
    toolbox->textures = malloc(sizeof(sfTexture *) * 3);
    toolbox->state = malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; i++) {
        toolbox->textures[i] = sfTexture_createFromFile(icone_fp[i], NULL);
        toolbox->sprites[i] = sfSprite_create();
        sfSprite_setTexture(toolbox->sprites[i], toolbox->textures[i], sfTrue);
        sfSprite_setPosition(toolbox->sprites[i], icone_pos[i]);
        toolbox->state[i] = 0;
    }
    toolbox->win = create_window(150, 1080, pos2, "Tool_box");
    return (toolbox);
}

int main(void)
{
    sfVector2i pos = {0, 0};
    sfRenderWindow *window = create_window(1420, 1080, pos, "World editor");
    map_t *map = create_map(NULL);
    toolbox_t *toolbox = create_toolbox();

    loop_editor(window, map, toolbox);
    destroy_map(map);
    return (0);
}
