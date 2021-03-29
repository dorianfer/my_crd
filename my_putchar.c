/*
** ETNA PROJECT, 02/10/2020 by fernan_d
** my_putchar
** File description:
**      [...]
*/

#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}
