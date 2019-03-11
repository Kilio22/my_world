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
#include <stdbool.h>
#include <math.h>

#define IN_RADIANS(angle) (angle * M_PI / 180)

#define ANGLE_X 0.785398
#define ANGLE_Y 0.610865

extern const int start_x;
extern const int start_y;
extern const int start_step;
extern const sfColor start_color;
extern const sfVector2f start_offset;
extern const char *input_font_path;
extern const char *cursor_path;
extern const sfColor toolbox_color;
extern const char *icone_fp[5];
extern const sfVector2f icone_pos[4];

typedef enum mode_e {
    corner,
    square,
    zoom,
    rotation
} my_mode_t;

typedef struct toolbox_s {
    sfRenderWindow *win;
    sfSprite **sprites;
    sfTexture **textures;
    int *state;
} toolbox_t;

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
    int mode_view;
    sfView *view;
    void (*highlight)(sfRenderWindow *, struct map_s *);
    void (*action)(sfRenderWindow *, struct map_s *);
    void (*erase)(sfRenderWindow *, struct map_s *);
    my_mode_t mode;
} map_t;

void destroy_map(map_t *map);
char *prompt_user_input(void);
void update_points(map_t *map);
int loop_editor(sfRenderWindow *window, map_t *map, toolbox_t *tool);
void analyse_events(sfRenderWindow *window, map_t *map, sfEvent event,
toolbox_t *tool);
sfVector2f project_iso_point(sfVector3f point, sfVector2f offset);
void manage_zoom_at(sfVector2i m, map_t *map, float zoom, sfRenderWindow *win);
void manage_zoom(sfRenderWindow *win, map_t *map, sfEvent event);
int is_on_tile(sfRenderWindow *win, map_t *map, grid_point_t **point, int j);
int is_closest_corner(sfRenderWindow *win, map_t *map, sfVector2f point);
float distance_between_points(sfVector2f p1, sfVector2f p2);
float calcul_points(sfVector2f p1, sfVector2f p2, sfVector2f p3);
void manage_mouse(map_t *map, sfRenderWindow *win);
int transfer_mouse_press(int tag);
void analyse_events_win2(sfEvent event, toolbox_t *tool, map_t *map);
void is_on_button(toolbox_t *toolbox, sfVector2f mouse, map_t *map);
void change_sprite(toolbox_t *toolbox, int i, map_t *map);
void change_mode(map_t *map);

/* EVENTS */
void reset_view(sfRenderWindow *win, map_t *map);
void resize_window(map_t *map, sfSizeEvent size);
void analyse_click(sfEvent event, sfMouseButton clicked);
void analyse_key_pressed(sfRenderWindow *win, map_t *map, sfKeyCode key, toolbox_t *tool);
void change_sprite(toolbox_t *toolbox, int i, map_t *map);

/* CREATE */
map_t *create_map(char *filepath);
sfVector2f **create_2d_map(map_t *map);
sfVertexArray *create_line(sfVector2f points[2], sfColor color);
sfVertexArray *create_holding_line(sfVector2f pos1, sfVector2f pos2);
sfRenderWindow *create_window(unsigned int width, unsigned int height,
                              sfVector2i pos, char *name);

/* DRAW */
int draw_tiles(sfRenderWindow *win, map_t *map);
void draw_lines(sfRenderWindow *win, map_t *map, int i, int j);
int draw_line_corner(sfRenderWindow *win, map_t *map, int i, int j);
void draw_square(sfRenderWindow *win, grid_point_t **point, int j, sfColor);

/* HIGHLIGHT */
void highlight_square(sfRenderWindow *win, map_t *map);
void highlight_corner(sfRenderWindow *win, map_t *map);

/* ACTIONS */
int *transfer_indexes(int *indexes);
void dig_up_square(sfRenderWindow *win, map_t *map);
void dig_up_corner(sfRenderWindow *win, map_t *map);
void dig_down_square(sfRenderWindow *win, map_t *map);
void dig_down_corner(sfRenderWindow *win, map_t *map);
void update_selected_point(sfRenderWindow *win, map_t *map);

#endif
