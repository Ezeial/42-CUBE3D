#include "cube3d.h"

static t_bool	ft_validate_char(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (!('0' <= line[i] && line[i] <= '9') && line[i] != ',' && line[i] != ' ' && line[i] != '\n'
			&& line[i] != 'F' && line[i] != 'C')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/*
**	Side is either floor or ceiling.
*/

static t_side	ft_is_side(char *line)
{
	if (ft_strcmp(line, "F"))
		return (F);
	if (ft_strcmp(line, "C"))
		return (C);
	return (NAS);
}

static t_bool   ft_parse_color_line(char *line, t_data *data, size_t index)
{
	t_side	side;
	size_t	idx;
	t_u1	color;

	if (ft_validate_char(line) == FALSE)
		return (FALSE);
	side = ft_is_side(line);
	if (side == NAS)
		return (FALSE);
	data->colors[index].side = side;
	line += ft_skip_whitespaces(line + 1) + 1;
	idx = 0;
	while (idx < 3)
	{
		if (ft_parse_u1(line, &color) == FALSE)
			return (FALSE);
		data->colors[index].rgb[idx] = color;
		line += ft_strfind(line, ',') + 1;
		idx++;
	}
	return (TRUE);
}

t_bool			ft_parse_colors(int fd, t_data *data, char *line)
{
	t_bool ret;

	if (!line)
		return (FALSE);
	ret = ft_parse_color_line(line, data, 0); 
	free(line);
	if (ret == FALSE)
		return (FALSE);
	line = get_next_line(fd);
	if (!line)
		return (FALSE);
	ret = ft_parse_color_line(line, data, 1); 
	free(line);
	if (ret == FALSE)
		return (FALSE);
	return (TRUE);
}