/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** my.h
*/

#include <stdarg.h>

#ifndef MY_H_
    #define MY_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <curses.h>
    #include <time.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    void my_putchar(char c);
    int my_put_nbr(int nb);
    int my_putstr(char const *);
    char *my_put_unsiegned(unsigned int, const char *);
    char *my_put_base(int, const char *);
    int my_strlen(char const *);
    char *my_revstr(char *str);
    int my_put_nbr_long(long int);
    int non_printable(char *);
    double sign_manager(char *format, double nbr);
    int my_printf(const char *format, ...);
    char str_char_nb(va_list list, const char *format, int i);
    char bin_octa_hexa(va_list list, const char *format, int i);
    char s_maj(va_list list, const char *format, int i);
    int also_add(char *result, const char *base, int len_base, int nb);
    int my_put_long(long int nb);
    int my_ls(const char *path);
    int flag_a(void);
    int linenbr(char *map);
    int colonnbr(char *map);
    void handle_movement(int c, char **map);
    int find_y(char **map);
    int find_x(char **map);
    int move_up(int c, char **map);
    int down(int c, char **map);
    int left(int c, char **map);
    int right(int c, char **map);
    void my_h(void);




#endif /*MY_H_*/
