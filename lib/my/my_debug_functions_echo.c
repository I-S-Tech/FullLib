/*
** EPITECH PROJECT, 2023
** FullLib
** File description:
** my_debug_functions_echo
*/

#include "includes.h"

void                dev_debug_print_double(double val)
{
    if (val < 0) {
        my_putchar('-');
        dev_debug_print_double(-val);
        return;
    }
    my_putnbr((int)val);
    my_putchar('.');
    val -= (double)(int)val;
    val *= 10;
    for (int i = 0; i < 6; i++) {
        my_putchar((int)val + 48);
        val -= (double)(int)val;
        val *= 10;
    }
}

void                debug_print_double(void *val)
{
    double d = *(double *)val;
    dev_debug_print_double(d);
}

void                dev_debug_print_long_double(long double val)
{
    if (val < 0) {
        my_putchar('-');
        dev_debug_print_long_double(-val);
        return;
    }
    my_putnbr((int)val);
    my_putchar('.');
    val -= (long double)(int)val;
    val *= 10;
    for (int i = 0; i < 6; i++) {
        my_putchar((int)val + 48);
        val -= (long double)(int)val;
        val *= 10;
    }
}

void                debug_print_long_double(void *val)
{
    float d = *(long double *)val;
    dev_debug_print_long_double(d);
}
