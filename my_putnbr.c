/*
** ETNA PROJECT, 28/09/2020 by fernan_d
** my_putnbr
** File description:
**      [...]
*/

#include <unistd.h>
#include "my_putchar.c"

void my_putnbr(int n)
{
    unsigned int nbr;
    nbr = n;
    if (n < 0) {
        nbr = -nbr;
        my_putchar('-');
    }
    if (nbr >= 10) {
        my_putnbr(nbr / 10);
        my_putnbr(nbr % 10);
    } else {
        my_putchar(nbr + '0');
    }
}
