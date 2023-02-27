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

static void         show_value_1(char *type, void *value)
{
    my_putstr(MY_COLOR_YELLOW);
    if (my_strcmp(type, "int") == 0)
        my_putnbr(*(int *)value);
    if (my_strcmp(type, "str") == 0)
        custom_showstr(*(char **)value);
    if (my_strcmp(type, "bool") == 0)
        my_putstr((*(bool *)value) ? "True" : "False");
    if (my_strcmp(type, "pointer") == 0)
        my_put_pointer(*(unsigned long long *)&value);
    if (my_strcmp(type, "char") == 0)
        my_putchar(*(char *)value);
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
    show_value_1(var->type, var->value);
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
