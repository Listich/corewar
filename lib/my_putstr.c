/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** my_putstr.c
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c);

int my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++) {
        my_putchar(str[i]);
    }
    return (0);
}
