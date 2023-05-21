/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Memory interactions
*/

#include "includes.h"

void                my_memset(byte *buff, byte c, int size)
{
    for (int i = 0; i < size; i++)
        buff[i] = c;
}

char               *my_add_size(byte *buffer, int size, bool was_malloced)
{
    byte *new_buffer = malloc(my_strlen(buffer) + size + 1);
    my_memset(new_buffer, 0, my_strlen(buffer) + size + 1);
    my_strcpy(new_buffer, buffer);
    if (was_malloced)
        free(buffer);
    return new_buffer;
}
