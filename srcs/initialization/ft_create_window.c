#include "cube3d.h"

t_err   ft_create_window(t_data *data)
{
    data->mlx_win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    if (!data->mlx_win)
        return (CREATE_WIN_ERROR);
    data->win_buff = new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!data->win_buff.img)
        return (CREATE_WIN_ERROR);
    return (OK);
}