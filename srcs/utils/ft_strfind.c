#include "cube3d.h"

size_t  ft_strfind(char *str, char c)
{
    size_t i;

    i = 0;
    while (str[i] && str[i] != c)
        i++;
    return (i);
}