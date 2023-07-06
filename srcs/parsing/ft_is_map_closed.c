#include "cube3d.h"

static void    ft_flood_fill(t_map *map, int x, int y)
{
    if (x < 0 || map->width <= x || y < 0 || map->height <= y)
        return ;
    if (0 < y && y + 1 < map->height)
        if (ft_strlen(map->map_data[y - 1]) <= x || ft_strlen(map->map_data[y + 1]) <= x)
            return ;
    if (map->map_data[y][x] == '0')
        map->map_data[y][x] = FLOODFILL_CHAR;
    else
        return ;
    ft_flood_fill(map, x - 1, y);
    ft_flood_fill(map, x + 1, y);
    ft_flood_fill(map, x, y - 1);
    ft_flood_fill(map, x, y + 1);
}

static  t_bool  ft_check_neighboor(t_map *map, int x, int y)
{
    if (x < 1 || !map->map_data[y][x + 1] || y < 1 || map->height <= y + 1)
        return (FALSE);
    if (map->map_data[y][x - 1] != FLOODFILL_CHAR && map->map_data[y][x - 1] != '1')
        return (FALSE);
    if (map->map_data[y][x + 1] != FLOODFILL_CHAR && map->map_data[y][x + 1] != '1')
        return (FALSE);
    if (ft_strlen(map->map_data[y - 1]) <= x || ft_strlen(map->map_data[y + 1]) <= x)
        return (FALSE);
    if (map->map_data[y - 1][x] != FLOODFILL_CHAR && map->map_data[y - 1][x] != '1')
        return (FALSE);
    if (map->map_data[y + 1][x] != FLOODFILL_CHAR && map->map_data[y + 1][x] != '1')
        return (FALSE);
    return (TRUE);
}

t_bool  ft_is_map_closed(t_data *data)
{
    int y;
    int x;

    ft_flood_fill(&(data->map), data->character.start_x, data->character.start_y);
    y = 0;
    while (y < data->map.height)
    {
        x = 0;
        while (x < data->map.width && data->map.map_data[y][x])
        {
            if (data->map.map_data[y][x] == FLOODFILL_CHAR)
                if (!ft_check_neighboor(&(data->map), x, y))
                    return (FALSE);
            x++;
        }
        y++;
    }
    return (TRUE);
}