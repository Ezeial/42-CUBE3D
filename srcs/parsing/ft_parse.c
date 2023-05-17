#include "cube3d.h"

t_parse_err ft_parse(int ac, char **av, t_map *map)
{
    int fd;

    if (ac != 2)
        return (WRONG_ARG_NUMBER);
    if (!ft_is_map_name_valid(av[1]))
        return (WRONG_MAP_NAME);
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return (OPEN_ERROR);
    if (!ft_parse_map(fd, map))
        return (MAP_ERROR);
    return (OK);
}