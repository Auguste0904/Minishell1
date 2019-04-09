/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** Compter la taille de la string
*/

#include "mysh.h"

int my_strlen(char const *str)
{
    int a = 0;

    for (; str[a] != '\0'; a++);
    return (a);
}
