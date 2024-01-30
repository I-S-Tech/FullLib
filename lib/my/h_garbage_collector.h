/*
** EPITECH PROJECT, 2023
** lib - garbage_collector
** File description:
** Garbage collector header
*/

#ifndef INCLUDED_LIB_GARBAGE_COLLECTOR_H
    #define INCLUDED_LIB_GARBAGE_COLLECTOR_H

// SIMPLE implementation of a garbage collector

    #include "includes.h"

// Uncomment to change the default malloc and  free functions
// If you dont, complex objects wont be freed. But it require the dlsym function
// #define USE_DLSYM


// Please do NOT use the garbage_collector_storage_system variable created with gc_start
// Never
// Also, do not use gc_start twice in the same function (like doing 2 "sessions" in the same function, it wont work well)

    #define gc_start() m_list garbage_collector_storage_system = _gc_start()
    #define gc_end() _gc_end(garbage_collector_storage_system)
    #define gc_malloc(size) _gc_malloc(size, garbage_collector_storage_system)
    #define gc_free(ptr) _gc_free(ptr, garbage_collector_storage_system)

static m_list garbage_collector_storage_system;

m_list              _gc_start(void);
void                _gc_end(m_list garbage_collector_storage_system);
void               *_gc_malloc(size_t size, m_list garbage_collector_storage_system);
void                _gc_free(void *ptr, m_list garbage_collector_storage_system);

#ifdef USE_DLSYM

void               *m_malloc(size_t size, m_list garbage_collector_storage_system);
void                m_free(void *ptr, m_list garbage_collector_storage_system);

#define malloc(size) m_malloc(size, garbage_collector_storage_system)
#define free(ptr) m_free(ptr, garbage_collector_storage_system)

#endif

#endif
