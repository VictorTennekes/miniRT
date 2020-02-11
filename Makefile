# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vtenneke <vtenneke@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/23 11:18:15 by vtenneke       #+#    #+#                 #
#    Updated: 2020/02/11 14:20:34 by victor        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	minirt
SRCS			=	main.c\
					calc/calc_square.c\
					calc/calc_fov.c\
					calc/calc_distance_points.c\
					calc/normalize_coords.c\
					dist/obj_dist.c\
					error/error.c\
					parse/parser.c\
					parse/parse_ambient.c\
					parse/parse_camera.c\
					parse/parse_cylinder.c\
					parse/parse_light.c\
					parse/parse_plane.c\
					parse/parse_resolution.c\
					parse/parse_sphere.c\
					parse/parse_square.c\
					parse/parse_triangle.c\
					render/cast_ray_object.c\
					render/cast_ray.c\
					utilities/char_arrlen.c\
					utilities/check_line.c\
					utilities/free_machine.c\
					utilities/isdigit_str.c\
					utilities/parse_color.c\
					utilities/parse_coords.c\
					utilities/parse_double.c\
					vec/get_pixel.c\
					vec/vec_a_to_b.c\
					vec/vec_add.c\
					vec/vec_len.c\
					vec/vec_new.c\
					vec/vec_normalize.c\
					vec/vec_sub.c
CFILES			=	$(SRCS:%=src/%)
OFILES			=	$(CFILES:.c=.o)
CFLAGS			=	-Wall -Wextra -Werror -DNOLIST -Wno-unused-parameter -g
INCLUDES		=	-I include\
					-I $(MLX_LOC)\
					-I $(LIBFT_LOC)/include\
					-I $(LIBLIST_LOC)
LIBS			=	-L $(MLX_LOC) -lmlx\
					-L $(LIBFT_LOC) -lft\
					-L $(LIBLIST_LOC) -llist
FRAMEWORK		=	-framework OpenGl\
					-framework AppKit
# LIB LOCATIONS
MLX_LOC			=	lib/mlx
LIBFT_LOC		=	lib/libft
LIBLIST_LOC		=	lib/liblist

# COLORS
WHITE   = \x1b[37;01m
CYAN    = \x1b[36;01m
PINK    = \x1b[35;01m
BLUE    = \x1b[34;01m
YELLOW  = \x1b[33;01m
GREEN   = \x1b[32;01m
RED     = \x1b[31;01m
BLACK   = \x1b[30;01m
RESET   = \x1b[0m

all: $(NAME)

$(NAME): $(OFILES)
	@echo "$(WHITE)/-----		Compiling mlx		-----\\ $(RESET)"
	make -C $(MLX_LOC)
	@echo "$(WHITE)/-----		Compiling libft		-----\\ $(RESET)"
	make bonus -C $(LIBFT_LOC)
	@echo "$(WHITE)/-----		Compiling liblist	-----\\ $(RESET)"
	make -C $(LIBLIST_LOC)
	@echo "$(WHITE)/-----		Compiling miniRT	-----\\ $(RESET)"
	$(CC) $(LIBS) $(FRAMEWORK) -o $(NAME) $(OFILES)

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean:
	@echo "$(WHITE)/-----		Cleaning mlx		-----\\ $(RESET)"
	make clean -C $(MLX_LOC)
	@echo "$(WHITE)/-----		Cleaning libft		-----\\ $(RESET)"
	make clean -C $(LIBFT_LOC)
	@echo "$(WHITE)/-----		Cleaning liblist	-----\\ $(RESET)"
	make clean -C $(LIBLIST_LOC)
	@echo "$(WHITE)/-----		Cleaning miniRT		-----\\ $(RESET)"
	rm -f $(OFILES)

fclean: clean
	@echo "$(WHITE)/-----		Fcleaning libft		-----\\ $(RESET)"
	make fclean -C $(LIBFT_LOC)
	@echo "$(WHITE)/-----		Fcleaning liblist	-----\\ $(RESET)"
	make fclean -C $(LIBLIST_LOC)
	@echo "$(WHITE)/-----		Fcleaning miniRT	-----\\ $(RESET)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re