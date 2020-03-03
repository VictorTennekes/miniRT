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
					color/color_add_light.c\
					color/color_mix.c\
					color/color_multi.c\
					color/color_mix_light.c\
					color/color_new.c\
					dist/obj_dist_pl.c\
					dist/obj_dist.c\
					dist/obj_dist_sp.c\
					error/error.c\
					free/free_data.c\
					free/free_list.c\
					intersect/inter_pl.c\
					intersect/inter_sp.c\
					intersect/intersect.c\
					key/hook_key.c\
					key/cam_move_xyz.c\
					mlx/hook_frame.c\
					mlx/init_mlx.c\
					mlx/init_mlx_img.c\
					mlx/pixel_put.c\
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
					render/light.c\
					render/cast_ray.c\
					render/ray_new.c\
					utilities/char_arrlen.c\
					utilities/check_line.c\
					utilities/color_to_int.c\
					utilities/free_machine.c\
					utilities/isdigit_str.c\
					utilities/parse_color.c\
					utilities/parse_coords.c\
					utilities/parse_double.c\
					utilities/ray_res_inf.c\
					utilities/ray_res_new.c\
					vec/normal/norm_cy.c\
					vec/normal/norm_pl.c\
					vec/normal/norm_sp.c\
					vec/normal/normal_matrix.c\
					vec/normal/normal.c\
					vec/normal/vec_normalize.c\
					vec/get_pixel.c\
					vec/quaternions.c\
					vec/vec_a_to_b.c\
					vec/vec_add.c\
					vec/vec_cross_prod.c\
					vec/vec_dist.c\
					vec/vec_dot_prod.c\
					vec/vec_len.c\
					vec/vec_multi.c\
					vec/vec_new.c\
					vec/vec_prod.c\
					vec/vec_rot.c\
					vec/vec_sub.c
CFILES			=	$(SRCS:%=src/%)
OFILES			=	$(CFILES:.c=.o)
CFLAGS			=	-Wall -Wextra -Werror -DNOLIST -g -Ofast
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
	@cp $(MLX_LOC)/libmlx.dylib .
	@echo "$(WHITE)/-----		Compiling libft		-----\\ $(RESET)"
	make bonus -j6 -C $(LIBFT_LOC)
	@echo "$(WHITE)/-----		Compiling liblist	-----\\ $(RESET)"
	make -j6 -C $(LIBLIST_LOC)
	@echo "$(WHITE)/-----		Compiling miniRT	-----\\ $(RESET)"
	$(CC) $(LIBS) $(FRAMEWORK) -o $(NAME) $(OFILES)

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean:
	@echo "$(WHITE)/-----		Cleaning mlx		-----\\ $(RESET)"
	make -j6 clean -C $(MLX_LOC)
	@rm libmlx.dylib
	@echo "$(WHITE)/-----		Cleaning libft		-----\\ $(RESET)"
	make -j6 clean -C $(LIBFT_LOC)
	@echo "$(WHITE)/-----		Cleaning liblist	-----\\ $(RESET)"
	make -j6 clean -C $(LIBLIST_LOC)
	@echo "$(WHITE)/-----		Cleaning miniRT		-----\\ $(RESET)"
	rm -f $(OFILES)

fclean: clean
	@echo "$(WHITE)/-----		Fcleaning libft		-----\\ $(RESET)"
	make -j6 fclean -C $(LIBFT_LOC)
	@echo "$(WHITE)/-----		Fcleaning liblist	-----\\ $(RESET)"
	make -j6 fclean -C $(LIBLIST_LOC)
	@echo "$(WHITE)/-----		Fcleaning miniRT	-----\\ $(RESET)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re