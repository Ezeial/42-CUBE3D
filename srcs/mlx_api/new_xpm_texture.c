#include "cube3d.h"

t_image new_xpm_texture(void *mlx, char *path_to_xml)
{
    t_image temp_image;

    temp_image.img = mlx_xpm_file_to_image(mlx, path_to_xml, &(temp_image.width), &(temp_image.height));
    if (!temp_image.img)
        return (temp_image);
    temp_image.addr = mlx_get_data_addr(
		temp_image.img,
		&(temp_image.bits_per_pixel),
		&(temp_image.line_length),
		&(temp_image.endian)
	);
    return (temp_image);
}