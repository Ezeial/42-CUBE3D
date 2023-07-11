#include "cube3d.h"

void	put_image_to_buffer(t_image *image, t_image *buffer, int x, int y)
{
	int	x_idx;
	int	y_idx;

	y_idx = 0;
	while (y_idx < image->height && y + y_idx < buffer->height)
	{
		x_idx = 0;
		while (x_idx < image->width && x + x_idx < buffer->width)
		{
			put_pixel_to_image(buffer, x + x_idx, y + y_idx,
				*get_pixel_on_image(image, x_idx, y_idx));
			x_idx++;
		}
		y_idx++;
	}
}