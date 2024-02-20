/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** my_revstr.c
*/

#include "my.h"

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    char loop;
    int len = 0;

    len = my_strlen(str) - 1;
    for (int i = 0; len > i; i++) {
        loop = str[i];
        str[i] = str[len];
        str[len] = loop;
        len -= 1;
    }
    return (str);
}
