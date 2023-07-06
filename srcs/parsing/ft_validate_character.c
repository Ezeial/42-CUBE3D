#include "cube3d.h"

static  t_direction ft_is_start_dir(char c)
{
    if (c == 'N')
        return (NO);
    if (c == 'S')
        return (SO);
    if (c == 'E')
        return (EA);
    if (c == 'W')
        return (WE);
    return (NAD);
}

static  t_bool  ft_is_valid_character(char c)
{
    return (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '0' || c == '1' || c == ' ');
}

/*
**
**  This function ensure there is one and only one starting position for the character,
**  and every character in the map are valids.
**  if yes set the player starting direction + coordinates and return TRUE
**  otherwise return FALSE
**
*/

t_bool  ft_validate_character(t_data *data)
{
    size_t      x;
    size_t      y;
    t_direction start_dir;

    y = 0;
    while (y < data->map.height)
    {
        x = 0;
        while (x < data->map.width && data->map.map_data[y][x])
        {
            if (!ft_is_valid_character(data->map.map_data[y][x]))
                return (FALSE);
            if ((start_dir = ft_is_start_dir(data->map.map_data[y][x])) != NAD)
            {
                if (data->character.start_dir)
                    return (FALSE);
                data->character.start_dir = start_dir;
                data->character.start_x = x;
                data->character.start_y = y;
                data->map.map_data[y][x] = '0';
            }
            x++;
        }
        y++;
    }
    return (data->character.start_dir != NAD);
}