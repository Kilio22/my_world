/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** test_my_access
*/

#include <criterion/criterion.h>
#include "world.h"

Test(my_access, access_file)
{
    cr_assert(my_access("test_my_access.c", 0));
    cr_assert(!my_access(".", 0));
}

Test(my_access, access_folder)
{
    cr_assert(my_access(".", 1));
    cr_assert(!my_access("test_my_access.c", 1));
}
