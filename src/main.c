/*
** EPITECH PROJECT, 2019
** Repo_starter
** File description:
** main
*/

#include "world.h"

int map[MAP_Y][MAP_X] = {
        {00, 00, 00, 00, 00, 00},
        {00, 00, 00, 00, 00, 00},
        {00, 00, 00, 05, 03, 00},
        {00, 00, 00, 00, 00, 00},
        {00, 00, 00, 00, 00, 00},
        {100, 00, 00, 00, 00, 00}
    };

sfVector2f project_iso_point(int x, int y, int z)
{
    sfVector2f my_2d_point = {0, 0};

    my_2d_point.x = cos(ANGLE_X) * x - cos(ANGLE_X) * y + 300;
    my_2d_point.y = sin(ANGLE_Y) * y + sin(ANGLE_Y) * x - z + 300;
    return (my_2d_point);
}

sfVector2f **create_2d_map(int (*my_3d_map)[MAP_X])
{
    sfVector2f **my_points;

    my_points = malloc(sizeof(sfVector2f *) * (MAP_Y));
    for (int i = 0; i < MAP_Y; i++) {
        my_points[i] = malloc(sizeof(sfVector2f) * MAP_X);
        for (int j = 0; j < MAP_X; j++)
            my_points[i][j] = project_iso_point(j * STEP_WINDOW, i * STEP_WINDOW, my_3d_map[i][j]);
    }
    return (my_points);
}

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2, princi_t *princi, sfColor color)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = color};
    sfVertex vertex2 = {.position = *point2, .color = color};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    sfRenderWindow_drawVertexArray(princi->window, vertex_array, NULL);
    return (vertex_array);
}

int draw_2d_map(princi_t *princi)
{
    sfVector2f **my_points = create_2d_map(map);
    sfColor color[6] = {sfWhite, sfBlue, sfRed, sfGreen, sfYellow, sfRed};

    for (int i = 0; i < MAP_Y; i++) {
        for (int j = 0; j < MAP_X; j++) {
            if (j + 1 < MAP_X)
                create_line(&my_points[i][j], &my_points[i][j + 1], princi, color[j]);
            if (i + 1 < MAP_Y)
                create_line(&my_points[i][j], &my_points[i + 1][j], princi, color[i]);
        }
    }
    return (0);
}

int check_event(princi_t *princi)
{
    while (sfRenderWindow_pollEvent(princi->window, &princi->event)) {
        if (princi->event.type == sfEvtClosed)
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    princi_t princi;

    av[ac - 1] = "";
    create_window(&princi);
    while (sfRenderWindow_isOpen(princi.window)) {
        if (check_event(&princi) == 1)
            break;
        draw_2d_map(&princi);
        sfRenderWindow_display(princi.window);
        sfRenderWindow_clear(princi.window, sfBlack);
    }
    sfRenderWindow_close(princi.window);
    sfRenderWindow_destroy(princi.window);
    return (0);
}