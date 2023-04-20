/*
** EPITECH PROJECT, 2023
** lib
** File description:
** [Beta] Show debug infos from LVALUE passed.
** Currently supported "type" values :
** I, S, B, P
*/

#include "includes.h"

static void         my_put_pointer(unsigned long long ptr)
{
    my_putstr("0x");
    char *base = "0123456789abcdef";
    if (ptr > 9223372036854775807)
        return;
    int basenum = my_strlen(base);
    if (basenum == 0)
        return;
    unsigned long long rest = ptr;
    unsigned long long power = 1;
    while ((rest / power) > basenum)
        power *= basenum;
    while (power > 0) {
        my_putchar(base[rest / power]);
        rest %= power;
        power /= basenum;
    }
}

static void         custom_showstr(const char *str)
{
    my_putchar('"');
    for (int i = 0; str[i]; i++) {
        if (str[i] < 32 || str[i] > 126) {
            my_putstr(MY_COLOR_RED);
            my_putchar('\\');
            my_putnbr_base((int)str[i], "0123456789abcdef");
            my_putstr(MY_COLOR_YELLOW);
        } else {
            my_putchar(str[i]);
        }
    }
    my_putchar('"');
}

static void         show_value(variable_type type, void *value)
{
    my_putstr(MY_COLOR_YELLOW);
    if (type == VARIABLE_TYPE_UNSIGNED_CHAR || type ==
        VARIABLE_TYPE_SIGNED_CHAR) my_putchar(*(char *)value);
    if (type == VARIABLE_TYPE_UNSIGNED_SHORT_INT || type ==
        VARIABLE_TYPE_SIGNED_SHORT_INT || type == VARIABLE_TYPE_UNSIGNED_INT ||
        type == VARIABLE_TYPE_SIGNED_LONG_INT || type ==
        VARIABLE_TYPE_UNSIGNED_LONG_INT || type == VARIABLE_TYPE_SIGNED_INT ||
        type == VARIABLE_TYPE_UNSIGNED_LONG_LONG_INT || type ==
        VARIABLE_TYPE_SIGNED_LONG_LONG_INT) {
        my_putlnbr(*(long long int *)value);
    }
    if (type == VARIABLE_TYPE_FLOAT) my_putfloat(*(float *)value, 6);
    if (type == VARIABLE_TYPE_DOUBLE) my_putdouble(*(double *)value, 6);
    if (type == VARIABLE_TYPE_LONG_DOUBLE)
        my_putldouble(*(long double *)value, 6);
    if (type == VARIABLE_TYPE_STRING) custom_showstr(*(char **)value);
    if (type == VARIABLE_TYPE_POINTER)
        my_put_pointer(*(unsigned long long *)&value);
    my_putchar('\n');
    my_putstr(MY_COLOR_RESET);
}

void                dev_my_debug(m_box var, int line, char *file)
{
    my_putstr(MY_COLOR_GREY);
    my_putstr(file);
    my_putstr(":");
    my_putnbr(line);
    my_putstr(": ");
    my_putstr_color(var->name, MY_COLOR_GREEN);
    my_putstr_color(": ", MY_COLOR_GREY);
    show_value(var->type, var->value);
    my_delet_box(var);
}

void                dev_my_debug_custom(m_box var, int line,
    char *file, void (*func)(void *))
{
    my_putstr(MY_COLOR_GREY);
    my_putstr(file);
    my_putstr(":");
    my_putnbr(line);
    my_putstr(": ");
    my_putstr_color(var->name, MY_COLOR_GREEN);
    my_putstr_color(": ", MY_COLOR_GREY);
    func(var->value);
    my_delet_box(var);
}
