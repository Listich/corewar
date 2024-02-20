/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** my_strlen.c
*/

#include "my.h"

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }
    return (count);
}
