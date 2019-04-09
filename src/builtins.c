/*
** EPITECH PROJECT, 2019
** builtins
** File description:
** Bultins
*/

#include "mysh.h"

void exit_command(tab_t *tab)
{
    if (my_strcmp(tab->str, "exit") == 0) {
        my_putstr("exit\n");
        exit(42);
    }
}

void env_command(tab_t *tab)
{
    if (tab->command_valid == false && my_strcmp(tab->str, "env") == 0) {
        tab->command_valid = true;
        print_env(tab);
    }
}

void exec_builtins(tab_t *tab)
{
    exit_command(tab);
    env_command(tab);
}