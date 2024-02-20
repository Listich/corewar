/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** my_printf.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

char s_maj(va_list list, const char *format, int i)
{
    switch (format[i]) {
    case 'S':
        non_printable(va_arg(list, char *));
        break;
    }
}

char bin_octa_hexa(va_list list, const char *format, int i)
{
    switch (format[i]) {
    case 'x':
        my_put_base(va_arg(list, int), "0123456789abcdef");
        break;
    case 'X':
        my_put_base(va_arg(list, int), "0123456789ABCDEF");
        break;
    case 'b':
        my_put_base(va_arg(list, int), "01");
        break;
    case 'o':
        my_put_base(va_arg(list, int), "01234567");
        break;
    case 'p':
        my_putstr("0x");
        my_put_base(va_arg(list, long int), "0123456789abcdef");
        break;
    }
}

char str_char_nb(va_list list, const char *format, int i)
{
    switch (format[i]) {
    case 's':
        my_putstr(va_arg(list, char *));
        break;
    case 'c':
        my_putchar(va_arg(list, int));
        break;
    case 'i':
    case 'd':
        my_put_nbr(va_arg(list, int));
        break;
    case 'u':
        my_put_unsiegned(va_arg(list, unsigned int), "0123456789");
        break;
    case '%':
        my_putchar('%');
        break;
    }
}

int my_printf(const char *format, ...)
{
    va_list list;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            str_char_nb(list, format, i);
            bin_octa_hexa(list, format, i);
        } else
            my_putchar(format[i]);
    }
    va_end(list);
    return (0);
}
