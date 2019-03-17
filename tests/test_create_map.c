/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** test_create_map
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include "world.h"
#include "my_string.h"

Test(create_map, requires_input)
{
    map_t *map = create_map(my_strdup("map_name"));

    cr_assert_str_eq("map_name", map->name);
    cr_assert(map->offset.x == start_offset.x);
    cr_assert(map->offset.y == start_offset.y);
    destroy_map(map);
}
