#include "cube3d.h"

static void ft_destroy_textures(t_data *data)
{
    size_t  i;

    i = 0;
    while (i < 4)
    {
        if (data->textures[i].texture_img)
        {
            mlx_destroy_image(data->mlx, data->textures[i].texture_img);
            data->textures[i].texture_img = NULL;
        }
        i++;
    }
}

static void ft_destroy_minimap(t_data *data)
{
	size_t y;

    if (!data->map.map_data)
        return ;
	y = 0;
	while (y < data->map.height)
	{
		free(data->map.map_data[y]);
        data->map.map_data[y] = NULL;
		y++;
	}
	free(data->map.map_data);
    data->map.map_data = NULL;
}

static void ft_destroy_mlx(t_data *data)
{
    if (data->mlx)
    {
        mlx_destroy_display(data->mlx);
        free(data->mlx);
        data->mlx = NULL;
    }
}

void    ft_destroy(t_data *data)
{
    ft_destroy_textures(data);
    ft_destroy_minimap(data);
    ft_destroy_mlx(data);
}