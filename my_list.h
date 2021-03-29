/*
** ETNA PROJECT, 07/10/2020 by fernan_d
** my_list.h
** File description:
**      [...]
*/

#ifndef __MY_LIST_H__
# define __MY_LIST_H__

typedef struct linked_list
{
    int data;
    int key;
    struct linked_list *back;
    struct linked_list *next;
} linked_list_t;

#endif
