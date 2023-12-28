/*
** EPITECH PROJECT, 2023
** my_malloc
** File description:
** Garbage collector - malloc
*/

#include "../includes.h"

m_list              _gc_start(void)
{
    return m_list_create(NULL);
}

void                _gc_end(m_list garbage_collector_storage_system)
{
    if (!garbage_collector_storage_system) return;
    m_list current = garbage_collector_storage_system;
    for (; current; current = current->next)
        if (current->data)
            m_list_remove(current, true);
    
    m_list_destroy(garbage_collector_storage_system, false);
}

void        *_gc_malloc(size_t size, m_list garbage_collector_storage_system)
{
    void *obj = malloc(size);
    m_list_append(garbage_collector_storage_system, m_list_create(obj));
    return obj;
}

void        _gc_free(void *ptr, m_list garbage_collector_storage_system)
{
    if (!ptr) return;
    m_list current = garbage_collector_storage_system;

    for (; current; current = current->next)
        if (current->data == ptr)
            m_list_remove(current, true);
}

#ifdef USE_DLSYM
#define _GNU_SOURCE

#include <dlfcn.h>

void       *m_malloc(size_t size, m_list garbage_collector_storage_system)
{
    void *(*_malloc)(size_t size);
    _malloc = dlsym(RTDL_NEXT, "malloc");
    void *obj = _malloc(size);
    m_list_append(garbage_collector_storage_system, m_list_create(obj));
    return obj;
}

void       *m_free(void *ptr, m_list garbage_collector_storage_system)
{
    if (!ptr) return;
    void (*_free)(void *ptr);
    _free = dlsym(RTDL_NEXT, "free");

    m_list current = garbage_collector_storage_system;

    for (; current; current = current->next)
        if (current->data == ptr)
            m_list_remove(current, false);
    _free(ptr);
}

#endif