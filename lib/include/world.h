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
#define FILE_RIGHTS S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
#define NB_BUTTONS 11

extern const int start_x;
extern const int start_y;
extern const int start_step;
extern const int window_x;
extern const int window_y;
extern const int start_angle_x;
extern const int start_angle_y;
extern const sfVector2i toolbox_pos;
extern const sfColor start_color;
extern const sfVector2f start_offset;
extern const char *input_font_path;
extern const char *cursor_path;
extern const sfColor trans_white;
extern const sfColor toolbox_color;
extern const char *icon_fp[12];
extern const sfVector2f icon_pos[NB_BUTTONS];
extern const char *tile_textures[6];
extern const char *text[NB_BUTTONS];
extern const sfColor hover;
extern const char *warning_msg;

typedef enum {
    up,
    down
} my_dig_t;

typedef enum {
    square,
    corner
} my_mode_t;

typedef enum {
    translation,
    rotation
} my_viewmode_t;

typedef struct toolbox_s {
    sfRenderWindow *win;
    sfSprite **sprites;
    sfTexture **textures;
    sfText **text;
    int *state;
    sfClock *clock;
    sfSound *sound;
    sfSoundBuffer *buffer;
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
    int angle_degrees[2];
    double angle[2];
    grid_point_t **grid;
} map_t;

typedef struct interface_s {
    sfRenderStates **states;
    sfRenderWindow *window;
    my_viewmode_t viewmode;
    my_mode_t mode;
    sfView *view;
    void (*highlight)(struct interface_s *, struct map_s *);
    void (*action)(struct interface_s *, struct map_s *);
} interface_t;

int save_map(map_t *map);
void update_points(map_t *map);
int transfer_mouse_press(int tag);
void manage_mouse(interface_t *face, map_t *map);
void manage_zoom(interface_t *face, sfEvent event);
int my_str_ends_with(const char *str, const char *end);
sfVector2f project_iso_point(sfVector3f point, map_t *map);
float distance_between_points(sfVector2f p1, sfVector2f p2);
int is_on_tile(interface_t *face, grid_point_t **point, int j);
int loop_editor(interface_t *face, map_t *map, toolbox_t *tool);
void manage_zoom_at(sfVector2i m, interface_t *face, float zoom);
float calcul_points(sfVector2f p1, sfVector2f p2, sfVector2f p3);
char *prompt_user_input(sfVector2u win_size, char *win_name);
int is_closest_corner(interface_t *face, map_t *map, sfVector2f point);

/* TOOLBOX */
void display_toolbox(interface_t *face, toolbox_t *toolbox, map_t *map);
void update_button(toolbox_t *toolbox);
void analyse_events_win2(sfEvent event, toolbox_t *tool, interface_t *face,
map_t *map);
void is_on_button(toolbox_t *toolbox, sfVector2f mouse, interface_t *face,
map_t *map);
int is_on_button_bool(sfSprite *sprite, sfVector2f mouse);
void check_zoom(toolbox_t *tool, interface_t *face);

/* EVENTS */
void check_warning(map_t *map);
void change_mode(interface_t *face);
void display_warning(const char *str);
void manage_rotate(sfKeyCode key, map_t *map);
void reset_view(interface_t *face, map_t *map);
void manage_translation(sfKeyCode key, map_t *map);
void resize_window(interface_t *face, sfSizeEvent size);
void analyse_click(sfEvent event, sfMouseButton clicked);
void change_sprite(toolbox_t *toolbox, int i, interface_t *face);
void analyse_events(interface_t *face, map_t *map, sfEvent event,
                    toolbox_t *tool);
void analyse_key_pressed(interface_t *face, map_t *map, sfKeyCode key,
                        toolbox_t *tool);

/* CREATE */
toolbox_t *create_toolbox(void);
map_t *create_map(char *filepath);
sfVector2f **create_2d_map(map_t *map);
interface_t *create_interface(char *map_name);
sfVertexArray *create_line(sfVector2f points[2], sfColor color);
sfVertexArray *create_holding_line(sfVector2f pos1, sfVector2f pos2);
sfRenderWindow *create_window(sfVector2u win_size,
                            sfVector2i pos, char *name, int mode);

/* DESTROY */
void destroy_map(map_t *map);
void destroy_toolbox(toolbox_t *tool);

/* DRAW */
int draw_tiles(interface_t *face, map_t *map);
void draw_lines(interface_t *face, map_t *map, int i, int j);
int draw_line_corner(interface_t *face, map_t *map, int i, int j);
void draw_square(interface_t *face, grid_point_t **point, int j, sfColor clr);

/* HIGHLIGHT */
void highlight_square(interface_t *face, map_t *map);
void highlight_corner(interface_t *face, map_t *map);

/* ACTIONS */
int *transfer_indexes(int *indexes);
void dig_nothing(interface_t *face, map_t *map);
void dig_up_square(interface_t *face, map_t *map);
void dig_up_corner(interface_t *face, map_t *map);
void dig_down_square(interface_t *face, map_t *map);
void dig_down_corner(interface_t *face, map_t *map);
void update_selected_point(interface_t *face, map_t *map);
void reset_map_altitude(map_t *map);
void add_row(map_t *map);
void delete_row(map_t *map);
void delete_column(map_t *map);
void add_column(map_t *map);
void reset_corner(interface_t *face, map_t *map);
void reset_square(interface_t *face, map_t *map);

/* FILE SYSTEM */
FILE *open_file(char *filepath);
int my_access(const char *pathname, int mode);

/* LOAD MAP */
int reset_map(map_t *map);
int load_map(map_t *map, char *filepath);
int **get_points(FILE *stream, map_t *map);
int get_size_of_map(FILE *stream, map_t *map);

#endif
