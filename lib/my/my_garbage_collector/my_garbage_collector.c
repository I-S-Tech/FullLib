/*
** EPITECH PROJECT, 2024
** myFTP
** File description:
** garbage_collector
*/

#include "../includes.h"

static garbage_list *garbage_collector_reference;

static garbage_list *gcl_create_new(void *ptr)
{
    garbage_list *new = (garbage_list *)malloc(sizeof(garbage_list));

    new->prev = NULL;
    new->ptr = ptr;
    new->next = NULL;
    return new;
}

static void gcl_add(garbage_list *new)
{
    garbage_list *current = garbage_collector_reference;

    if (!current)
        return;
    for (; current->next; current = current->next);
    current->next = new;
    new->prev = current;
}

void gc_cleanup(void)
{
    garbage_list *current = garbage_collector_reference;

    debug(true, "Clearing resources...\n");
    if (!garbage_collector_reference)
        return;
    for (; current->prev; current = current->prev);
    for (; current->next; current = current->next) {
        if (!current->prev)
            continue;
        free(current->prev->ptr);
        free(current->prev);
        current->prev = NULL;
    }
    if (current->prev) {
        free(current->prev->ptr);
        free(current->prev);
    }
    free(current->ptr);
    free(current);
    garbage_collector_reference = NULL;
}

void *gc_malloc(size_t size)
{
    void *obj = malloc(size);

    if (!garbage_collector_reference)
        garbage_collector_reference = gcl_create_new(obj);
    else
        gcl_add(gcl_create_new(obj));
    return obj;
}

void gc_free(void *ptr)
{
    garbage_list *current = garbage_collector_reference;

    if (!current)
        return;
    for (; current->prev; current = current->prev);
    for (; current; current = current->next) {
        if (current->ptr != ptr)
            continue;
        free(current->ptr);
        if (current == garbage_collector_reference)
            garbage_collector_reference = current->prev ?
                current->prev : current->next;
        if (current->prev)
            current->prev->next = current->next;
        if (current->next)
            current->next->prev = current->prev;
        free(current);
        return;
    }
}
