/*
** EPITECH PROJECT, 2019
** my_str_to_word_tabay
** File description:
** Parcing a string and remove spaces chracter
*/

#include "mysh.h"

int find_chara(char *str, int i)
{
    if (str[i] == ' ' || str[i] == '\t' || str[i] == ':' || str[i] == '\0')
        return (0);
    else
        return (42);
}

int nb_words(char *str)
{
    int nb = 0;
    int i = 0;

    for (; str[i] != '\0'; i++)
        if (find_chara(str, i) == 42 &&
            find_chara(str, i + 1) == 0)
            nb = nb + 1;
    return (nb);
}

void malloc_tab(char *str, char **tab)
{
    int i = 0;
    int j = 0;
    int count = 0;

    for (count = 0; i < nb_words(str) && str[j] != '\0'; i++) {
        while (find_chara(str, j) == 0)
            j++;
        for (; find_chara(str, j) == 42; j++, count++);
        tab[i] = malloc(sizeof(char) * count + 1);
    }
}

void fill_tab(char *str, char **tab)
{
    int i = 0;
    int j = 0;
    int count = 0;

    for (; i < nb_words(str) && str[j] != '\0'; i++) {
        while (find_chara(str, j) == 0)
            j++;
        for (; find_chara(str, j) == 42; j++, count++)
            tab[i][count] = str[j];
        tab[i][count] = '\0';
        count = 0;
    }
    tab[i] = NULL;
}

char **my_str_to_word_array(char *str)
{
    char **tab = NULL;

    tab = malloc(sizeof(char *) * (nb_words(str) + 1));
    malloc_tab(str, tab);
    fill_tab(str, tab);
    return (tab);
}