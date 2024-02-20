/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** my_put_long.c
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c);
int my_put_nbr(int nb);

int my_put_long(long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * (-1));
    } else if (nb <= 9) {
        my_putchar(nb + 48);
    } else {
        my_put_nbr(nb / 10);
        nb = (nb % 10 + 48);
        my_putchar(nb);
    }
    return (0);
}
