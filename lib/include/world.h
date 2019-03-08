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

extern const int start_x;
extern const int start_y;
extern const int start_step;
extern const sfColor start_color;
extern const sfVector2f start_offset;

typedef struct grid_point_s {
    int altitude;
    sfVector2f point;
} grid_point_t;

typedef struct map_s {
    char *name;
    int columns;
    int rows;
    unsigned int step;
    sfVector2f offset;
    grid_point_t **grid;
} map_t;

/* Read note in create_window.c */
sfRenderWindow *create_window(unsigned int width, unsigned int height,
                              unsigned int fps, char *name);

void destroy_map(map_t *map);
void update_points(map_t *map);
map_t *create_map(char *filepath);
sfVector2f **create_2d_map(map_t *map);
int loop_editor(sfRenderWindow *window, map_t *map);
int draw_2d_map(sfRenderWindow *window, map_t *map);
int draw_triangle(sfRenderWindow *window, map_t *map);
int analyse_events(sfRenderWindow *window, map_t *map);
sfVector2f project_iso_point(sfVector3f point, sfVector2f offset);

#endif
