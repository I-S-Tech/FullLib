/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Duplicate string
*/

#include "includes.h"

char               *my_strdup(const char *str)
{
    char *dup = malloc(my_strlen(str) + 1);
    my_strcpy(dup, str);
    return dup;
}
