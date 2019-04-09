/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** Code of minishell1
*/

#include "mysh.h"

int command_miss_path(tab_t *tab)
{
    exec_builtins(tab);
    recup_path(tab);
    exec_access(tab);
}

int minishell1(tab_t *tab, size_t i)
{
    int a = 0;

    while (1) {
        my_putstr("$> ");
        if ((a = getline(&tab->str, &i, stdin)) == -1) {
            my_putstr("exit\n");
            return (42);
        }
        while (my_strcmp(tab->str, "\n") == 0) {
            my_putstr("$> ");
            if ((a = getline(&tab->str, &i, stdin)) == -1) {
                my_putstr("exit\n");
                return (42);
            }
        }
        tab->arr_path = my_str_to_word_array(tab->str);
        tab->str[a - 1] = '\0';
        if (command_miss_path(tab) == 42)
            return (42);
    }
    return (0);
}
