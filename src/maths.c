/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** maths
*/

#include "world.h"

float distance_between_points(sfVector2f p1, sfVector2f p2)
{
    float nb =
sqrt(((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y)));

    return (nb);
}

float calcul_points(sfVector2f p1, sfVector2f p2, sfVector2f p3)
{
    float nb = (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);

    return (nb);
}
