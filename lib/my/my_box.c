/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Simple box structure (name-value)
*/

#include "includes.h"

m_box               my_create_box(char *name, void *value, char *type)
{
    m_box current = malloc(sizeof(_m_box));
    current->name = my_strdup(name);
    current->value = value;
    current->type = my_strdup(type);

    return current;
}

void                my_delet_box(m_box box)
{
    free(box->name);
    free(box->type);
    free(box);
}
