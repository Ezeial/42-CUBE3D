#include "cube3d.h"

void    ft_loop(t_data *data)
{
    ft_hook_loop(data);
    mlx_loop(data->mlx);
}