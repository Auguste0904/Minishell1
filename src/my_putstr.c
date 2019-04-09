/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** Afficher une chaîne de caractère
*/

#include "mysh.h"

int my_putstr(char const *str)
{
    int a = 0;

    for (; str[a] != '\0'; a++)
        my_putchar(str[a]);
    return (0);
}
