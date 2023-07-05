#include "cube3d.h"

static t_bool  ft_realloc_mmap(t_data *data)
{
    char **realloced_map;
    size_t  i;

    realloced_map = malloc(sizeof(char *) * data->map.height * 2);
    if (!realloced_map)
        return (FALSE);
    i = 0;
    while (i < data->map.height)
    {
        realloced_map[i] = data->map.map_data[i];
        i++;
    }
    free(data->map.map_data);
    data->map.map_data = realloced_map;
    data->map.height *= 2;
    return (TRUE);
}

t_bool  ft_parse_minimap(int fd, t_data *data, char *line)
{
    size_t i;

    data->map.height = 10;
    data->map.map_data = malloc(sizeof(char *) * data->map.height);
    if (!data->map.map_data)
        return (FALSE);
    i = 0;
    while (line)
    {
        if (!(i < data->map.height))
            if (ft_realloc_mmap(data) == FALSE)
                return (FALSE);
        ft_strtrim_end(line);
        if (ft_strlen(line) > data->map.width)
            data->map.width = ft_strlen(line);
        data->map.map_data[i] = line;
        i++;
        line = get_next_line(fd);
    }
    data->map.height = i;
    return (TRUE);
}