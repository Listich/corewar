/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** my_putchar.c
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
