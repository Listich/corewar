/*
** EPITECH PROJECT, 2022
** B-CPE-101-TLS-1-1-myprintf-brenn.makouya
** File description:
** my_put_unsiegned.c
*/

#include <stdlib.h>
#include "my.h"

char *my_put_unsiegned(unsigned int nb, char const *base)
{
    int len_base = my_strlen(base);
    int ret = 0;
    char *result = malloc(sizeof(char) * (len_base + 2));

    if (result == NULL)
        return (NULL);
    if (nb == 0) {
        return (0);
    } else {
        for (int i = 0; nb != 0; i++) {
            result[i] = base[nb % len_base];
            nb = nb / len_base;
        }
        result = my_revstr(result);
        my_putstr(result);
    }
    free(result);
    return (0);
}
