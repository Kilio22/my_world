/*
** EPITECH PROJECT, 2019
** test_pattern.c
** File description:
** Just a pattern, copy pasta this
*/

#include <criterion/criterion.h>
#include "world.h"

Test(my_str_ends_with, big_yikes)
{
    cr_assert(my_str_ends_with("default.world", ".world"));
    cr_assert(my_str_ends_with("yay.world", ".world"));
    cr_assert(my_str_ends_with(" .world", ".world"));
    cr_assert(my_str_ends_with(".world", ".world"));
    cr_assert(my_str_ends_with("big_yikes.world.world", ".world"));
    cr_assert(!my_str_ends_with("defaultworld", ".world"));
    cr_assert(!my_str_ends_with("default.worl", ".world"));
    cr_assert(!my_str_ends_with("default.wold", ".world"));
    cr_assert(!my_str_ends_with("world", ".world"));
    cr_assert(!my_str_ends_with("world", ""));
}
