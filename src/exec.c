/*
** EPITECH PROJECT, 2019
** ls
** File description:
** ls
*/

#include "mysh.h"

char *recup_path(tab_t *tab)
{
    int count = 0;

    tab->array = my_str_to_word_array(tab->str);
    if (tab->array[0] == NULL)
        return (NULL);
    for (; tab->arr_env[count] != NULL; count++)
        if (my_charcmp(tab->arr_env[count][0], 'P') == 0 &&
            my_charcmp(tab->arr_env[count][1], 'A') == 0 &&
            my_charcmp(tab->arr_env[count][2], 'T') == 0 &&
            my_charcmp(tab->arr_env[count][3], 'H') == 0 &&
            my_charcmp(tab->arr_env[count][4], '=') == 0) {
            tab->arr_path = my_str_to_word_array(&tab->arr_env[count][5]);
            for (int i = 0; tab->arr_path[i]; i++) {
                my_strcat(tab->arr_path[i], tab->array[0]);
            }
            return (tab->arr_env[count]);
        }
}

int exec_path(tab_t *tab, int i)
{
    int wstatus = 0;

    tab->pid = fork();
    recup_path(tab);
    if (tab->pid == 0) {
        if (execve(tab->arr_path[i], my_str_to_word_array(tab->str),
            tab->arr_env) == -1) {
            perror("execve");
            exit (84);
        }
    }
    else
        waitpid(tab->pid, &wstatus, WUNTRACED | WCONTINUED);
    return (2);
}

int exec_access(tab_t *tab)
{
    tab->command_valid = false;

    for (int i = 0; tab->arr_path[i] != NULL; i++)
        if (access(tab->arr_path[i], X_OK) == 0 &&
            my_strcmp(tab->str, "env") != 0) {
            tab->command_valid = true;
            exec_path(tab, i);
            return (0);
        }
    if (tab->command_valid == false && my_strcmp(tab->str, "env") != 0) {
        my_putstr(tab->str);
        my_putstr(": Command not found.\n");
    }
    return (0);
}
