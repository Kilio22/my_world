/*
** EPITECH PROJECT, 2019
** bootstrap
** File description:
** world
*/

#ifndef OUI
#define OUI

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ANGLE_X 0.785398
#define ANGLE_Y 0.610865
#define MAP_X 6
#define MAP_Y 6
#define STEP_WINDOW 64

typedef struct princi_s {
    sfRenderWindow *window;
    sfEvent event;
    sfVector2f **my_points;
    int **map;
    int step_x;
    int step_y;
} princi_t;

void create_window(princi_t *princi);
int draw_triangle(princi_t *princi, sfVector2f **points);
int draw_2d_map(princi_t *princi, sfVector2f **points);
sfVector2f **create_2d_map(int **my_3d_map, princi_t *princi);
int check_event(princi_t *princi);

#endif