/*
** EPITECH PROJECT, 2023
** FullLib
** File description:
** my_debug_functions_echo
*/

#include "includes.h"

static void         dev_debug_print_special_char(char c)
{
    switch (c) {
        case 0: my_putchar('0'); return;
        case 7: my_putchar('a'); return;
        case 8: my_putchar('b'); return;
        case 9: my_putchar('t'); return;
        case 10: my_putchar('n'); return;
        case 11: my_putchar('v'); return;
        case 12: my_putchar('f'); return;
        case 13: my_putchar('r'); return;
        default: break;
    }
    if (c >= 0 && c <= 16) my_putchar('0');
    my_putnbr_base((int)c, "0123456789abcdef");
}

void                debug_print_string(void *val)
{
    char *str = *(char **)val;
    my_putchar('"');
    for (int i = 0; str[i]; i++) {
        if (str[i] < 32 || str[i] > 126) {
            my_putstr(MY_COLOR_RED);
            my_putchar('\\');
            dev_debug_print_special_char(str[i]);
            my_putstr(MY_COLOR_YELLOW);
        } else {
            my_putchar(str[i]);
        }
    }
    my_putchar('"');
}

void                debug_print_pointer(void *val)
{
    unsigned long long ptr = *(unsigned long long *)&val;
    my_putstr("0x");
    char *base = "0123456789abcdef";
    if (ptr > 9223372036854775807)
        return;
    unsigned long long basenum = my_strlen(base);
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
