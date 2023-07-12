#include "cube3d.h"

static int  ft_next_frame(t_data *data)
{
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->win_buff.img, 0, 0);
    return (0);
}

void    ft_hook_loop(t_data *data)
{
    mlx_loop_hook(data->mlx, ft_next_frame, data);
}       