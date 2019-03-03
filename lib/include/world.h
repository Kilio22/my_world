/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Header file for the my_world project
*/

#ifndef WORLD_H_
#define WORLD_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IN_RADIANS(angle) (angle * M_PI / 180)
#define ANGLE_X 0.785398
#define ANGLE_Y 0.610865
#define INIT_MAP_X 6
#define INIT_MAP_Y 6
#define INIT_MAP_OFFSET 300
#define STEP_WINDOW 64

struct map_props_s {
    size_t columns;
    size_t rows;
    unsigned int step;
    sfVector2f offset;
};

typedef struct map_s {
    char *name;
    int **grid;
    sfVector2f **points;
    struct map_props_s props;
} map_t;

/* Read note in create_window.c */
sfRenderWindow *create_window(unsigned int width, unsigned int height,
                              unsigned int fps, char *name);

void destroy_map(map_t *map);
map_t *create_map(char *filepath);
sfVector2f **create_2d_map(map_t *map);
int loop_editor(sfRenderWindow *window, map_t *map);
int draw_2d_map(sfRenderWindow *window, map_t *map);
int draw_triangle(sfRenderWindow *window, map_t *map);
int analyse_events(sfRenderWindow *window, map_t *map);

#endif
