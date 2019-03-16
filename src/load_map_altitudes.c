/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Loads the points' altitude from the given, map
*/

#include <sys/types.h>
#include "world.h"
#include "my.h"
#include "my_string.h"

static char *read_next_line(FILE *stream)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t n_read;

    n_read = getline(&line, &len, stream);
    if (n_read == -1)
        return (NULL);
    line[n_read - 1] = (line[n_read - 1] == '\n') ? '\0' : line[n_read - 1];
    return (line);
}

static char **split_line(char *line, size_t expected_fields)
{
    char **array = my_str_towordarray(line, " ");

    if (my_arraylen(array) != expected_fields)
        return (NULL);
    for (int i = 0; array[i]; i++) {
        if (!my_str_isnum(array[i], 1))
            return (NULL);
    }
    return (array);
}

int **get_points(FILE *stream, map_t *map)
{
    int **points = malloc(sizeof(int *) * map->rows);
    char **array;
    char *line;

    for (int i = 0; i < map->rows; i++) {
        points[i] = malloc(sizeof(int) * map->columns);
        line = read_next_line(stream);
        if (line == NULL)
            return (NULL);
        array = split_line(line, (size_t) map->columns);
        if (array == NULL)
            return (NULL);
        for (int j = 0; j < map->columns; j++)
            points[i][j] = my_getnbr(array[j]);
    }
    return (points);
}

int get_size_of_map(FILE *stream, map_t *map)
{
    char **array;
    char *line = read_next_line(stream);

    if (line == NULL)
        return (-1);
    array = my_str_towordarray(line, " ");
    if (my_arraylen(array) != 2)
        return (-1);
    map->rows = my_getnbr(array[0]);
    map->columns = my_getnbr(array[1]);
    return (0);
}
