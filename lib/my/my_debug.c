/*
** EPITECH PROJECT, 2023
** lib
** File description:
** [Beta] Show debug infos from LVALUE passed.
** Currently supported "type" values :
** I, S
*/

#include "includes.h"

static void         show_value(char type, void *value)
{
    my_putstr(MY_COLOR_YELLOW);
    switch (type) {
        case 'I':
            my_putnbr(*(int *)value); break;
        case 'S':
            my_putstr(*(char **)value); break;
        default:
            my_putstr("Could not read value : type not found");
            break;
    }
    my_putchar('\n');
    my_putstr(MY_COLOR_RESET);
}

void                _my_debug(char type, m_box var, int line, char *file)
{
    my_putstr(MY_COLOR_GREY);
    my_putstr(file);
    my_putstr(":");
    my_putnbr(line);
    my_putstr(": ");
    my_putstr_color(var->name, MY_COLOR_GREEN);
    my_putstr_color(": ", MY_COLOR_GREY);
    show_value(type, var->value);
    my_delet_box(var);
}