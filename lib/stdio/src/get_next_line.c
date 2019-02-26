/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** Takes a file descriptor, and returns the first found line of it.
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_stdio.h"
#include "my_string.h"

static char *alloc(char *str, char *cat, int s, int n)
{
    char *return_str;
    int str_len = 0;
    int cat_len = 0;
    int i;

    while (str[str_len] != '\0' && ((s != -1 && str_len < s) || s == -1))
        str_len++;
    while (cat[cat_len] != '\0' && ((n != -1 && cat_len < n) || n == -1))
        cat_len++;
    return_str = malloc(sizeof(char) * (str_len + cat_len + 1));
    if (return_str == NULL)
        return (NULL);
    for (i = 0; i < str_len; i++)
        return_str[i] = str[i];
    for (int j = 0; j < cat_len; i++)
        return_str[i] = cat[j++];
    return_str[i] = '\0';
    return (return_str);
}

static char *do_recursive(int fd, char *str, char **db)
{
    char buf[READ_SIZE + 1] = {0};
    int read_val;

    read_val = read(fd, buf, READ_SIZE);
    if (read_val == -1 || str == NULL)
        return (NULL);
    buf[read_val] = '\0';
    for (int i = 0; i < READ_SIZE || buf[i] != '\0'; i++) {
        if (buf[i] == '\n') {
            *db = alloc(&buf[i + 1], "", -1, -1);
            str = alloc(str, buf, -1, i);
            return (str);
        }
    }
    if (*db == NULL && read_val == 0 && str[0] == '\0')
        return (NULL);
    if (read_val != READ_SIZE)
        return (alloc(str, buf, -1, read_val));
    return (do_recursive(fd, alloc(str, buf, -1, -1), db));
}

char *get_next_line(int fd)
{
    static char *db = NULL;
    char *str;

    if (db != NULL) {
        str = alloc(db, "", -1, -1);
        free(db);
    }
    else
        str = alloc("", "", -1, -1);
    db = NULL;
    if (str == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            db = alloc(&str[i + 1], "", -1, -1);
            str = alloc(str, "", i, -1);
            return (str);
        }
    }
    return (do_recursive(fd, str, &db));
}
