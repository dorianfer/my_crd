/*
** ETNA PROJECT, 06/10/2020 by fernan_d
** my_getnbr
** File description:
**      [...]
*/

#include <stdio.h>
int my_getnbr(const char *str)
{
    int nbr = 0;
    int signe = 0;
    int nombre = 0;    
    while (str[nbr] < 48 || str[nbr] > 57) {
        if (str[nbr] == '-') {
            signe++;
        }
        nbr++;
    }
    while (str[nbr] > 47 && str[nbr] < 58) {
        nombre = nombre + str[nbr] - 48;
        
        if (str[nbr + 1] > 47 && str[nbr + 1] < 58) {
            nombre = nombre * 10;
        }
        nbr++;
    }
    if (signe % 2 == 1) {
        nombre = - nombre;
    }
    return (nombre);
}

