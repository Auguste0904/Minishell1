/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** Compare two string
*/

#include "mysh.h"

int my_charcmp(char a, char b)
{
    return (a - b);
}

int my_strcmp(char const *s1, char const *s2)
{
    int a = 0;

    while (s1[a] == s2[a] && s1[a] != '\0' && s2[a] != '\0')
        a += 1;
    return (s1[a] - s2[a]);
}
