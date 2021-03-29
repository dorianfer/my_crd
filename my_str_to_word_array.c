/*
** ETNA PROJECT, 06/10/2020 by fernan_d
** my_str_to_word_array
** File description:
**      [...]
*/

#include <stdlib.h>
#include <stdio.h>
int nbr_mot(const char *str)
{
    int nbr = 0;
    int nombre = 0;
    int ligne = 0;
    while (str[nbr] != '\0') {
        if ((str[nbr] > 47 && str[nbr] < 58) || (str[nbr] > 64 && str[nbr] < 91) || (str[nbr] > 96 && str[nbr] < 123)) {
            ligne = 1;
        } else if (ligne == 1) {
            if ((str[nbr + 1] > 47 && str[nbr + 1] < 58) || (str[nbr + 1] > 64 && str[nbr + 1] < 91) || (str[nbr + 1] > 96 && str[nbr + 1] < 123)){
                ligne = 0;
                nombre = nombre + 1;
            }
        }
        nbr = nbr + 1;
    }
    return (nombre + 1);
}
void nbr_carac(const char *str, int *caract)
{
    int compte = 0;
    int nbr = 0;
    while (str[nbr] != '\0') {
        if ((str[nbr] > 47 && str[nbr] < 58) || (str[nbr] > 64 && str[nbr] < 91) || (str[nbr] > 96 && str[nbr] < 123)) {
            caract[compte] = 2;
            nbr = nbr + 1;
            while ((str[nbr] > 47 && str[nbr] < 58) || (str[nbr] > 64 && str[nbr] < 91) || (str[nbr] > 96 && str[nbr] < 123)) {
                caract[compte] = caract[compte] + 1;
                nbr = nbr + 1;
            }
            compte = compte + 1;
        } else {
            nbr = nbr + 1;
        }
    }
}
void malloc_tableau(char **word_array,int *caract,int nombre)
{
    int nbr = 0;
    for (; nbr != nombre; nbr++) {
        word_array[nbr] = malloc(sizeof(**word_array) * caract[nbr]);
    }
    word_array[nbr] = malloc(sizeof(**word_array) * caract[nbr]);
}
void terminer_tableau(const char *str,char **word_array)
{
    int compte = 0;
    int nbr = 0;
    int n = 0;
    while (str[nbr] != '\0') {
        if ((str[nbr] > 47 && str[nbr] < 58) || (str[nbr] > 64 && str[nbr] < 91) || (str[nbr] > 96 && str[nbr] < 123)) {
            word_array[n][compte] = str[nbr];
            nbr = nbr + 1;
            compte = compte + 1;
            while ((str[nbr] > 47 && str[nbr] < 58) || (str[nbr] > 64 && str[nbr] < 91) || (str[nbr] > 96 && str[nbr] < 123)) {
                word_array[n][compte] = str[nbr];
                nbr = nbr + 1;
                compte = compte + 1;
            }
            n = n + 1;
            compte = 0;
        } else {
            nbr = nbr + 1;
        }
    }
    word_array[n][compte] = '\0';
}

char **my_str_to_word_array(const char *str)
{
    int nombre;
    nombre = nbr_mot(str);
    int *caract = malloc(sizeof(int *) * nombre + 1);
    nbr_carac(str,caract);
    char **word_array = malloc(sizeof(*word_array) * nombre);
    malloc_tableau(word_array,caract,nombre);
    terminer_tableau(str,word_array);
    return (word_array);
}
