/*
** ETNA PROJECT, 09/10/2020 by fernan_d
** my_crd.c
** File description:
**      [...]
*/

#define _GNU_SOURCE
#include <stdio.h>
#include "my_list.h"
#include "my_readline.c"
#include "my_str_to_word_array.c"
#include <stdlib.h>
#include <unistd.h>
#include "my_getnbr.c"
#include "my_putnbr.c"

linked_list_t *my_push_data(int value, linked_list_t *list, int nbr)
// Cette fonction permet d'ajouter à la structure la "KEY" et sa "VALUE".
{
    linked_list_t *node;
    node = malloc(sizeof(*node));
    if (node == NULL) {
        return (0);
    }
    if (list == NULL) {
        node->back = NULL;
        node->next = NULL;
        node->key = value;
        node->data = nbr;
    } else {
        node->back = NULL;
        list->back = node;
        node->next = list;
        node->key = value;
        node->data = nbr;
    }
    return (node);
}

linked_list_t *my_crd(char *str,linked_list_t *list)
// Cette fonction permet de trier les différents cas comme la commande d'insertion,
// la commande de suppression et la commande lookup.
{
    int nbr = 0;
    int nombre = 0;
    char **clara = 0;
    clara = my_str_to_word_array(str);
    nombre = my_getnbr(clara[0]);
    if (clara[1][0] == '\0') { // S'il y a que la "KEY" d'afficher alors ont vérifié si la "KEY" existe ou non.
        while (list != NULL) {
            if (list->key == nombre) {
                my_putnbr(list->data);
                my_putchar('\n');
                return (list);
            }
            list = list->next;
        }
        if (list == NULL) {
            my_putnbr(-1);
            my_putchar('\n');
            return (list);
        }
    } else if (clara[1][0] == 'D'){ //S'il y a un "D" après la "KEY" alors soit on supprime la "KEY"
        // et on affiche sa valeur ou s'il n'existe pas alors on affiche un -1.
        if (list == NULL) {
          my_putnbr(-1);
          my_putchar('\n');
          return (list);
        }
        while (list != NULL) {
            if (nombre == list -> key) {
                my_putnbr(list->data);
                my_putchar('\n');
                if (list->next != NULL) {
                    (list->next)->back=list->back;
                }
                if (list->back != NULL) {
                    (list->back)->next=list->next;
                }
                free(list);
                return (list);
            }
            list = list->next;
            my_putnbr(-1);
            my_putchar('\n');
            return (list);
        }
    } else { //S'il y a une "value" alors soit si la "KEY" existe
        // alors on modifie la "VALUE" de la "KEY" voulu
        //ou s'il n'existe pas ont créé dans la liste chainée la "KEY" et la "VALUE".
        nbr = my_getnbr(clara[1]);
        while (list != NULL) {
            if (nombre == list -> key) {
                list->data = nbr;
                my_putnbr(list -> key);
                my_putchar('\n');
                return (list);
            }
            list = list->next;
        }
        list = my_push_data(nombre,list,nbr);
        my_putnbr(list->key);
        my_putchar('\n');
    }
    return (list);
}

int main()
// Cette fonction permet d'exécuter la fonction "my_crd"
// le nombre de fois qu'il y a de ligne dans le command Lst .
{
    linked_list_t *tmp;
    char *ret;
    tmp = NULL;
    ret = my_readline();
    tmp = my_crd(ret,tmp);
    while (ret != NULL) {
        ret = my_readline();
        if (ret == NULL) {
            break;
        }
        tmp = my_crd(ret,tmp);
    }
    return (0);
}
