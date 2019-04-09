/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Concatenates two strings
*/

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;

    if (dest[0] == 0) {
        return (src);
    }
    for (; dest[i] != '\0'; i++);
    dest[i] = '/';
    for (; src[j] != '\0'; i++, j++)
        dest[i + 1] = src[j];
    dest[i + 1] = '\0';
    return (dest);
}