#include "cube3d.h"

void ft_strtrim_end(char *str)
{
    int idx;

    idx = ft_strlen(str);
    if (idx > 0)
        idx--;
    else
        return ;
    while (-1 < idx && (str[idx] == ' ' || str[idx] == '\n'))
        idx--;
    str[idx + 1] = 0;
}