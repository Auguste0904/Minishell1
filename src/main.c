/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "mysh.h"

void print_env(tab_t *tab)
{
    int count = 0;

    for (; tab->arr_env[count] != NULL; count++) {
        my_putstr(tab->arr_env[count]);
        my_putchar('\n');
    }
}

int stock_env(tab_t *tab, char **env)
{
    int count = 0;
    int i = 0;

    for (; env[count] != NULL; count++);
    if ((tab->arr_env = malloc(sizeof(char *) * (count + 1))) == NULL)
        return (84);
    for (; i < count; i++) {
        if ((tab->arr_env[i] =
            malloc(sizeof(char) * (my_strlen(env[i]) + 1))) == NULL)
            return (84);
    }
    for (i = 0; i < count; i++)
        tab->arr_env[i] = env[i];
    return (0);
}

int main(int ac, char **av, char **env)
{
    tab_t *tab = malloc(sizeof(tab_t));
    size_t i = 0;

    if (ac > 1)
        return (84);
    if (ac == 1) {
        stock_env(tab, env);
        minishell1(tab, i);
    }
    return (0);
}
