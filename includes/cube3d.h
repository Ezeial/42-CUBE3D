#ifndef CUBE3D_H
# define CUBE3D_H

//  INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mlx.h>

#include "../srcs/gnl/get_next_line.h"

//	DEFINE

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_TITLE "cub3d"
#define TEXTURE_WIDTH 50
#define TEXTURE_HEIGHT 50
#define FLOODFILL_CHAR '.'

//  TYPEDEF

typedef unsigned char t_u1;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef enum e_err
{
	OK,
	INITIALIZATION_ERROR,
    WRONG_ARG_NUMBER,
	WRONG_MAP_NAME,
	OPEN_ERROR,
	MAP_ERROR,
	CREATE_WIN_ERROR
}	t_err;

typedef enum e_direction
{	
	NAD = 0,
	NO,
	SO,
	EA,
	WE
}	t_direction;

typedef enum e_side
{
	NAS = 0,
	C,
	F
}	t_side;

typedef struct s_image {
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_texture
{
	t_direction direction;
	t_image		image;
	int			width;
	int			height;
}	t_texture;

typedef struct s_color
{
	t_side	side;
	t_u1	rgb[3];
}	t_color;

typedef	struct s_map
{
	char		**map_data;
	size_t		width;
	size_t		height;
}	t_map;

typedef struct s_character
{
	size_t		start_x;
	size_t		start_y;
	t_direction	start_dir;
}	t_character;

typedef struct s_data
{
	t_map		map;
	t_character	character;
	t_texture	textures[4];
	t_color		colors[2];
	void		*mlx;
	void		*mlx_win;
	t_image		win_buff;
}	t_data;

//  PROTOTYPE

//		UTILS

int			ft_strlen(char *str);
t_bool		ft_strcmp(char *s1, char *s2);
size_t	    ft_skip_whitespaces(char *str);
int			ft_error(t_err errtype, t_data *data);
void 		ft_strtrim_end(char *str);
void    	ft_bzero(void *data, size_t n);
t_bool		ft_skip_newlines(int fd, char **current_line);
t_bool		ft_parse_u1(char *number, t_u1 *out);
size_t  	ft_strfind(char *str, char c);

//		MLX_API

t_image		new_image(void *mlx, size_t width, size_t height);
t_image 	new_xpm_texture(void *mlx, char *path_to_xml);
int			*get_pixel_on_image(t_image *image, int x, int y);
void		put_image_to_buffer(t_image *image, t_image *buffer, int x, int y);
void		put_pixel_to_image(t_image *image, int x, int y, int color);

//		INITIALIZATION

t_err		ft_init(t_data *data);
t_err   	ft_create_window(t_data *data);

//      PARSING

t_err		ft_parse(int ac, char **av, t_data *data);
t_bool		ft_is_map_name_valid(char *map_name);
t_bool		ft_parse_map(int fd, t_data *data);
t_bool		ft_parse_textures(int fd, t_data *data);
t_bool		ft_parse_colors(int fd, t_data *data, char *line);
t_bool		ft_parse_minimap(int fd, t_data *data, char *line);
t_bool		ft_validate_character(t_data *data);
t_bool  	ft_is_map_closed(t_data *data);
t_bool		ft_validate_datas(t_data *data);

//		LOOP

void		ft_hook_loop(t_data *data);
void		ft_loop(t_data *data);

//		DESTRUCTION

void    	ft_destroy(t_data *data);

#endif