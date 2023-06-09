#include "cube3d.h"

static t_direction  ft_is_direction_valid(char *line)
{
    if (ft_strcmp(line, "NO"))
        return (NO);
    if (ft_strcmp(line, "SO"))
        return (SO);
    if (ft_strcmp(line, "EA"))
        return (EA);
    if (ft_strcmp(line, "WE"))
        return (WE);
    return (NAS);
}

t_bool  ft_parse_texture_line(char *line, t_data *data, size_t index)
{
    size_t      str_index;
    t_direction direction;

    str_index = 0;
    direction = ft_is_direction_valid(line);
    if (direction == NAD)
		return (FALSE);
	str_index += 2 + ft_skip_whitespaces(line + 2);
    ft_strtrim_end(line + str_index);
    data->textures[index].direction = direction;
    data->textures[index].image = new_xpm_texture(data->mlx, (line + str_index));
    if (!(data->textures[index].image.img))
        return (FALSE); 
}

t_bool  ft_parse_textures(int fd, t_data *data)
{
    char        *line;
    size_t      index;
    t_bool      ret;

    index = 0;
    while (index < 4)
    {
        line = get_next_line(fd);
        if (!line)
            return (FALSE);
        ret = ft_parse_texture_line(line, data, index);
        free(line);
        if (ret == FALSE)
            return (FALSE);
        index++;
    }
    return (TRUE);
}