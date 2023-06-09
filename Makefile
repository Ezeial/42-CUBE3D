#-----------------------------------------------#
#-----------------[ SRCS NAME ]-----------------#
#-----------------------------------------------#

MAIN			= 	srcs/main.c
MAIN_TEST		= 	srcs/main_test.c

SRCS			= 	$(MAIN) \
					srcs/gnl/get_next_line.c srcs/gnl/get_next_line_utils.c \
					srcs/utils/ft_strlen.c srcs/utils/ft_strcmp.c srcs/utils/ft_skip_whitespaces.c srcs/utils/ft_error.c srcs/utils/ft_strtrim_end.c srcs/utils/ft_bzero.c srcs/utils/ft_skip_newlines.c srcs/utils/ft_parse_u1.c srcs/utils/ft_strfind.c \
					srcs/mlx_api/new_xpm_texture.c srcs/mlx_api/new_image.c srcs/mlx_api/get_pixel_on_image.c srcs/mlx_api/put_image_to_buffer.c srcs/mlx_api/put_pixel_to_image.c \
					srcs/initialization/ft_init.c srcs/initialization/ft_create_window.c \
					srcs/parsing/ft_parse.c srcs/parsing/ft_is_map_name_valid.c srcs/parsing/ft_parse_map.c srcs/parsing/ft_parse_textures.c srcs/parsing/ft_parse_colors.c srcs/parsing/ft_parse_minimap.c srcs/parsing/ft_validate_character.c srcs/parsing/ft_is_map_closed.c srcs/parsing/ft_validate_datas.c \
					srcs/loop/ft_hook_loop.c srcs/loop/ft_loop.c \
					srcs/destruction/ft_destroy.c

#-----------------------------------------------#
#----------------[ COMPILATION ]----------------#
#-----------------------------------------------#

CC				=	gcc
RM				=	rm -rf
CFLAGS			=	-fsanitize=address  # -Wall -Wextra # -Werror -O3

HEADERS			=	includes/cube3d.h

NAME			=	cube3D

OBJS			=	$(SRCS:.c=.o)	

#-----------------------------------------------#
#-------------------[ TARGET ]------------------#
#-----------------------------------------------#

all:			$(NAME)

%.o:			%.c $(HEADERS)
				$(CC) $(CFLAGS) -I./includes -I./mlx -c $< -o $@

$(NAME):		$(OBJS)
				make -C mlx
				$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -lXext -lX11 -lm -lz -o $(NAME)

clean:
				make clean -C mlx
				$(RM) $(OBJS)

fclean:			clean
				make fclean -C mlx
				$(RM) $(NAME)

re:				fclean $(NAME)

test:			all clean

.PHONY:			all clean fclean re