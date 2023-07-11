#include "cube3d.h"

t_image  new_image(void *mlx, size_t width, size_t height)
{
    t_image temp_image;

    temp_image.img = mlx_new_image(mlx, width, height);
    if (!temp_image.img)
        return (temp_image);
    temp_image.addr = mlx_get_data_addr(
			temp_image.img,
			&(temp_image.bits_per_pixel),
			&(temp_image.line_length),
			&(temp_image.endian)
			);
    temp_image.width = width;
    temp_image.height = height;
    return (temp_image);
}