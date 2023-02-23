/*
** EPITECH PROJECT, 2023
** lib
** File description:
** [Beta] Show debug infos from LVALUE passed.
** Currently supported "type" values :
** I, S, B, P
*/

#include "includes.h"

static void         my_put_long_nbr_base(unsigned long long nbr,
    const char *base)
{
    if (nbr > 9223372036854775807)
        return;
    int basenum = my_strlen(base);
    if (basenum == 0)
        return;
    unsigned long long rest = nbr;
    unsigned long long power = 1;
    while ((rest / power) > basenum)
        power *= basenum;
    while (power > 0) {
        my_putchar(base[rest / power]);
        rest %= power;
        power /= basenum;
    }
}

static void         curstom_showstr(const char *str)
{
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
}

static void         show_value_1(char type, void *value)
{
    my_putstr(MY_COLOR_YELLOW);
    switch (type) {
        case 'I':
            my_putnbr(*(int *)value); break;
        case 'S':
            curstom_showstr(*(char **)value); break;
        case 'B':
            my_putstr((*(bool *)value) ? "True" : "False"); break;
        case 'P':
            my_putstr("0x");
            my_put_long_nbr_base(*(unsigned long long *)&value,
                "0123456789abcdef");
            break;
        default:
            my_putstr("Could not read value : type not found");
            break;
    }
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
