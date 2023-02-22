/*
** EPITECH PROJECT, 2023
** lib
** File description:
** swap two ints
*/

#include "includes.h"

void                my_swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}