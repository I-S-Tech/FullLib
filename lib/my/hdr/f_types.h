/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Some structures
*/

#ifndef INCLUDED_LIB_STRUCTS_H
    #define INCLUDED_LIB_STRUCTS_H

typedef enum variable_type {
    VARIABLE_TYPE_UNSIGNED_CHAR,
    VARIABLE_TYPE_SIGNED_CHAR,
    VARIABLE_TYPE_UNSIGNED_SHORT_INT,
    VARIABLE_TYPE_SIGNED_SHORT_INT,
    VARIABLE_TYPE_UNSIGNED_INT,
    VARIABLE_TYPE_SIGNED_INT,
    VARIABLE_TYPE_UNSIGNED_LONG_INT,
    VARIABLE_TYPE_SIGNED_LONG_INT,
    VARIABLE_TYPE_UNSIGNED_LONG_LONG_INT,
    VARIABLE_TYPE_SIGNED_LONG_LONG_INT,
    VARIABLE_TYPE_FLOAT,
    VARIABLE_TYPE_DOUBLE,
    VARIABLE_TYPE_LONG_DOUBLE,
    VARIABLE_TYPE_STRING,
    VARIABLE_TYPE_POINTER,
} variable_type;

typedef struct _f_box {
    char *name;
    void *value;
    variable_type type;
    unsigned long size;
} _f_box;

typedef _f_box* f_box;

typedef char byte;

#endif
