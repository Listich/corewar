/*
** EPITECH PROJECT, 2022
** B-CPE-101-TLS-1-1-myprintf-brenn.makouya
** File description:
** sign_manager.c
*/

#include "my.h"

void my_putchar(char c);

double sign_manager(char *format, double nbr)
{
    int signe = 0;
    int i = 0;

    for (i = 0; format[i] != '\0'; i++) {
        if (signe == 0 && format[i] == '+')
                signe = 1;
        if (format[i] == '-')
                signe *= -1;
    }
    if (nbr > 0 && signe == 1)
            my_putchar('+');
    return (nbr);
}
