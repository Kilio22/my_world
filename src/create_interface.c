/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Creates the interface of the main window
*/

#include "world.h"
#include "my_string.h"

void create_music(interface_t *face)
{
    face->music = sfMusic_createFromFile("assets/music.ogg");
    sfMusic_setLoop(face->music, sfTrue);
    sfMusic_setVolume(face->music, 50);
    sfMusic_play(face->music);
    face->buff_dig = sfSoundBuffer_createFromFile("assets/dig.ogg");
    face->sound_dig = sfSound_create();
    sfSound_setBuffer(face->sound_dig, face->buff_dig);
}

void create_textures_for_tiles(interface_t *face)
{
    sfTexture *texture;

    face->states = malloc(sizeof(sfRenderStates *) * 6);
    for (int i = 0; i < 6; i++) {
        texture = sfTexture_createFromFile(tile_textures[i], NULL);
        face->states[i] = malloc(sizeof(sfRenderStates));
        face->states[i]->shader = NULL;
        face->states[i]->transform = sfTransform_Identity;
        face->states[i]->texture = texture;
        face->states[i]->blendMode = sfBlendAlpha;
    }
}

interface_t *create_interface(char *map_name)
{
    interface_t *interface = malloc(sizeof(interface_t));
    sfVector2f vrec = {window_x, window_y};
    sfVector2i wrec = {0, 0};
    sfVector2u wvec = {window_x, window_y};
    char *win_name = my_strdup("Currently editing \"");

    win_name = my_strcat(win_name, my_strdup(map_name));
    win_name = my_strcat(win_name, my_strdup("\""));
    interface->window = create_window(wvec, wrec, win_name, 7);
    interface->viewmode = translation;
    interface->mode = square;
    interface->view = sfView_create();
    interface->highlight = highlight_square;
    interface->action = dig_up_square;
    sfView_setSize(interface->view, vrec);
    create_textures_for_tiles(interface);
    create_music(interface);
    return (interface);
}
