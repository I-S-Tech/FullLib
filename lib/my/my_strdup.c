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
    for (int i = 0; str[i]; i++)
        dup[i] = str[i];
    dup[my_strlen(str)] = '\0';
    return dup;
}