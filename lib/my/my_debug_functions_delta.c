/*
** EPITECH PROJECT, 2023
** FullLib
** File description:
** my_debug_functions_delta
*/

#include "includes.h"

static void         dev_debug_print_long_long(long long int nbr)
{
    if (nbr < 0) {
        my_putchar('-');
        dev_debug_print_long_long(-nbr);
        return;
    }
    if (nbr < 10) {
        my_putchar(nbr + 48);
        return;
    }
    dev_debug_print_long_long(nbr / 10);
    my_putchar(nbr % 10 + 48);
}

void                debug_print_long_long(void *val)
{
    long long int i = *(long long int *)val;
    dev_debug_print_long_long(i);
}

void                dev_debug_print_float(float val)
{
    if (val < 0) {
        my_putchar('-');
        dev_debug_print_float(-val);
        return;
    }
    my_putnbr((int)val);
    my_putchar('.');
    val -= (float)(int)val;
    val *= 10;
    for (int i = 0; i < 6; i++) {
        my_putchar((int)val + 48);
        val -= (float)(int)val;
        val *= 10;
    }
}

void                debug_print_float(void *val)
{
    float f = *(float *)val;
    dev_debug_print_float(f);
}
