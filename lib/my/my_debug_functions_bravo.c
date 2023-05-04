/*
** EPITECH PROJECT, 2023
** FullLib
** File description:
** my_debug_functions_bravo
*/

#include "includes.h"

void                dev_debug_print_uint(unsigned int nbr)
{
    if (nbr < 10) {
        my_putchar(nbr + 48);
        return;
    }
    dev_debug_print_uint(nbr / 10);
    my_putchar(nbr % 10 + 48);
}

void                debug_print_uint(void *val)
{
    unsigned int i = *(unsigned int *)val;
    dev_debug_print_uint(i);
}

void                debug_print_int(void *val)
{
    my_putnbr(*(int *)val);
}

void                dev_debug_print_ulong(unsigned long int nbr)
{
    if (nbr < 10) {
        my_putchar(nbr + 48);
        return;
    }
    dev_debug_print_ulong(nbr / 10);
    my_putchar(nbr % 10 + 48);
}

void                debug_print_ulong(void *val)
{
    unsigned long int i = *(unsigned long int *)val;
    dev_debug_print_ulong(i);
}
