/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** test_randomize_seed
*/

#include <criterion/criterion.h>
#include "world.h"
#include <stdlib.h>

Test(randomize_seed, normal_tests)
{
    setup_random_seed();
    cr_assert(rand() != rand());
    cr_assert(rand() != rand());
    cr_assert(rand() != rand());
    cr_assert(rand() != rand());
    cr_assert(rand() != rand());
    cr_assert(rand() != rand());
    cr_assert(rand() != rand());
}
