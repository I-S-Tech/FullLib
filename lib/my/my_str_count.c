/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Count occurencies of certain things on a string
*/

#include "includes.h"

int                 my_str_count(const char *str, char c)
{
    int total = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            total++;
    return total;
}