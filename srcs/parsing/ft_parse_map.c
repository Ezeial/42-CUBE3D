#include "cube3d.h"

t_bool  ft_parse_map(int fd, t_data *data)
{
    char	*current_line;

    if (!ft_parse_textures(fd, data))
    	return (FALSE);
    if (!ft_skip_newlines(fd, &current_line))
		return (FALSE);
	if (!ft_parse_colors(fd, data, current_line))
		return (FALSE);
    if (!ft_skip_newlines(fd, &current_line))
		return (FALSE);
	if (!ft_parse_minimap(fd, data, current_line))
		return (FALSE);	
	if (!ft_validate_datas(data))
		return (FALSE);
	return (TRUE);
}