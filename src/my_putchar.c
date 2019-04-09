/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** Afficher un caractère
*/

#include "mysh.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
