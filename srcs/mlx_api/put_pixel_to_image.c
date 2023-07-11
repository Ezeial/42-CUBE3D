#include "cube3d.h"

void	put_pixel_to_image(t_image *image, int x, int y, int color)
{
	if ((x < 0 || image->width < x) || (y < 0 || image->height < y)
		|| (unsigned int)color == 0xff000000)
		return ;
	*get_pixel_on_image(image, x, y) = color;
}