/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** le pas de calais
*/

#include "world.h"

FILE *open_file(char *filepath)
{
    FILE *stream = fopen(filepath, "r");

    return (stream);
}
