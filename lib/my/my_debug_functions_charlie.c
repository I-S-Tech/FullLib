/*
** EPITECH PROJECT, 2023
** FullLib
** File description:
** my_debug_functions_charlie
*/

#include "includes.h"

void                dev_debug_print_long(long int nbr)
{
    if (nbr < 0) {
        my_putchar('-');
        dev_debug_print_long(-nbr);
        return;
    }
    if (nbr < 10) {
        my_putchar(nbr + 48);
        return;
    }
    dev_debug_print_long(nbr / 10);
    my_putchar(nbr % 10 + 48);
}

void                debug_print_long(void *val)
{
    long int i = *(long int *)val;
    dev_debug_print_long(i);
}

void                dev_debug_ulong_long(unsigned long long int nbr)
{
    if (nbr < 10) {
        my_putchar(nbr + 48);
        return;
    }
    dev_debug_ulong_long(nbr / 10);
    my_putchar(nbr % 10 + 48);
}

void                debug_print_ulong_long(void *val)
{
    unsigned long long int i = *(unsigned long long int *)val;
    dev_debug_ulong_long(i);
}
