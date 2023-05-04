/*
** EPITECH PROJECT, 2023
** FullLib
** File description:
** my_debug_functions_alpha
*/

#include "includes.h"

void                debug_print_uchar(void *val)
{
    unsigned char c = *(unsigned char *)val;
    if (c < 32 || c > 126) {
        my_putstr(MY_COLOR_RED);
        my_putchar('\\');
        my_putnbr_base((int)c, "0123456789abcdef");
        my_putstr(MY_COLOR_YELLOW);
    } else {
        my_putchar((char)c);
    }
}

void                debug_print_char(void *val)
{
    char c = *(char *)val;
    if (c < 32 || c > 126) {
        my_putstr(MY_COLOR_RED);
        my_putchar('\\');
        my_putnbr_base((int)c, "0123456789abcdef");
        my_putstr(MY_COLOR_YELLOW);
    } else {
        my_putchar(c);
    }
}

void                debug_print_usint(void *val)
{
    unsigned short s = *(unsigned short *)val;
    my_putnbr((int)s);
}

void                debug_print_sint(void *val)
{
    short s = *(short *)val;
    my_putnbr((int)s);
}
