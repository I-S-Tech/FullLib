/*
** EPITECH PROJECT, 2023
** lib - lists
** File description:
** Lists headers (linked lists)
*/

#ifndef INCLUDED_LIB_LISTS_H
    #define INCLUDED_LIB_LISTS_H

    #include "includes.h"

typedef struct _f_list {
    struct _f_list *prev;
    void *data;
    struct _f_list *next;
} _f_list;

typedef _f_list* f_list;

f_list              f_list_create(void *data);
f_list              f_list_append(f_list ref, f_list obj);
f_list              f_list_prepend(f_list ref, f_list obj);
f_list              f_list_set_before(f_list ref, f_list obj);
f_list              f_list_set_after(f_list ref, f_list obj);

void                f_list_remove(f_list obj, bool was_malloced);
void                f_list_destroy(f_list obj, bool was_malloced);

#endif
