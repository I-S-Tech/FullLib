/*
** EPITECH PROJECT, 2023
** FullLib
** File description:
** my_debug_functions
*/

#include "includes.h"

void                my_putfloat(float nbr, int nb_round)
{
    my_putnbr((int)nbr);
    my_putchar('.');
    nbr -= (float)(int)nbr;
    nbr *= 10;
    for (int i = 0; i < nb_round; i++) {
        my_putchar((int)nbr + 48);
        nbr -= (float)(int)nbr;
        nbr *= 10;
    }
}

void                my_putdouble(double nbr, int nb_round)
{
    my_putnbr((int)nbr);
    my_putchar('.');
    nbr -= (double)(int)nbr;
    nbr *= 10;
    for (int i = 0; i < nb_round; i++) {
        my_putchar((int)nbr + 48);
        nbr -= (double)(int)nbr;
        nbr *= 10;
    }
}

void                my_putldouble(long double nbr, int nb_round)
{
    my_putnbr((int)nbr);
    my_putchar('.');
    nbr -= (long double)(int)nbr;
    nbr *= 10;
    for (int i = 0; i < nb_round; i++) {
        my_putchar((int)nbr + 48);
        nbr -= (long double)(int)nbr;
        nbr *= 10;
    }
}

void                my_putlnbr(long long int nbr)
{
    if (!nbr)
        return;
    if (nbr < 0) {
        my_putchar('-');
        my_putlnbr(-nbr);
        return;
    }
    if (nbr < 10) {
        my_putchar(nbr + 48);
        return;
    }
    my_putlnbr(nbr / 10);
    my_putchar(nbr % 10 + 48);
}
