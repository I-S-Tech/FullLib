/*
** EPITECH PROJECT, 2024
** FullLib
** File description:
** garbage_collector
*/

#ifndef INCLUDED_GARBAGE_COLLECTOR_H
    #define INCLUDED_GARBAGE_COLLECTOR_H

typedef struct _garbage_list {
    struct _garbage_list *prev;
    void *ptr;
    struct _garbage_list *next;
} _garbage_list;

typedef _garbage_list* garbage_list;

void f_cleanup(void);

void *f_malloc(size_t size);
void f_free(void *ptr);

#endif
