/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** no_printable.c
*/

#include <stdlib.h>
#include "my.h"

void convert(int number)
{
    int nb[3];
    int res = 0;
    int i = 0;

    for (; i < 3; i++)
        nb[i] = 0;
    for (i = 2; number > 0; i--) {
        res = number % 8;
        number = number / 8;
        nb[i] = res;
    }
    for (i = 0; i < 3; i += 1)
        my_put_nbr(nb[i]);
}

int non_printable(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putstr("\\");
            convert(str[i]);
        }
    }
    return (0);
}
