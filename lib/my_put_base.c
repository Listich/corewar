/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_put_base.c
*/

#include <stdlib.h>
#include "my.h"

int also_add(char *result, const char *base, int len_base, int nb)
{
    int ret = 0;

    for (int i = 0; nb != 0; i += 1) {
        result[i] = base[nb % len_base];
        nb = nb / len_base;
    }
    result = my_revstr(result);
    my_putstr(result);
    return (0);
}

char *my_put_base(int nb, const char *base)
{
    int len_base = my_strlen(base);
    char *result = malloc(sizeof(char) * (len_base + 2));

    if (result == NULL)
        exit (84);
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb == 0) {
        return (0);
    } else {
        also_add(result, base, len_base, nb);
    }
    free(result);
    return (0);
}
