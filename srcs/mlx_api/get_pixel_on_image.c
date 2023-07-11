#include "cube3d.h"

int	*get_pixel_on_image(t_image *image, int x, int y)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x
			* (image->bits_per_pixel / 8));
	return ((int *)dst);
}