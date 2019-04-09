/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Proto of minishell1
*/

#ifndef MYSH_H_
#define MYSH_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>

typedef struct tab
{
    char *str;
    char **array;
    char **arr_env;
    char **arr_path;
    pid_t pid;
    bool command_valid;
}tab_t;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_strcat(char *dest, char *src);
char **my_str_to_word_array(char *str);
int minishell1(tab_t *tab, size_t i);
int exec_access(tab_t *tab);
char *recup_path(tab_t *tab);
int my_charcmp(char a, char b);
int exec_env(tab_t *tab, size_t i);
void print_env(tab_t *tab);
void exec_builtins(tab_t *tab);

#endif
