# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vtenneke <vtenneke@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/23 11:18:15 by vtenneke      #+#    #+#                  #
#    Updated: 2020/02/11 14:20:34 by victor        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	minirt

all: $(NAME)

SRCS			=	main.c\
					color/color_add_light.c\
					color/color_mix.c\
					color/color_multi.c\
					color/color_mix_light.c\
					color/color_new.c\
					dist/obj_dist_cy.c\
					dist/obj_dist_ds.c\
					dist/obj_dist_pl.c\
					dist/obj_dist_sp.c\
					dist/obj_dist_tr.c\
					dist/obj_dist.c\
					error/error.c\
					free/free_data.c\
					free/free_list.c\
					intersect/inter_cy.c\
					intersect/inter_ds.c\
					intersect/inter_pl.c\
					intersect/inter_sp.c\
					intersect/inter_tr.c\
					intersect/intersect.c\
					key/hook_key.c\
					key/cam_interact.c\
					key/switch_cam.c\
					mlx/exit_mlx.c\
					mlx/hook_frame.c\
					mlx/init_mlx.c\
					mlx/init_mlx_img.c\
					mlx/pixel_put.c\
					parse/parser.c\
					parse/parse_ambient.c\
					parse/parse_camera.c\
					parse/parse_cylinder.c\
					parse/parse_disk.c\
					parse/parse_light.c\
					parse/parse_plane.c\
					parse/parse_pyramid.c\
					parse/parse_resolution.c\
					parse/parse_sphere.c\
					parse/parse_square.c\
					parse/parse_triangle.c\
					render/cast_ray_object.c\
					render/light.c\
					render/cast_ray.c\
					render/ray_new.c\
					render/save_bmp.c\
					utilities/char_arrlen.c\
					utilities/check_edge_tr.c\
					utilities/children_cylinder.c\
					utilities/children_pyramid.c\
					utilities/color_to_int.c\
					utilities/double_compare.c\
					utilities/free_machine.c\
					utilities/init_sq_children.c\
					utilities/init_sq_corners.c\
					utilities/isdigit_str.c\
					utilities/parse_color.c\
					utilities/parse_coords.c\
					utilities/parse_double.c\
					utilities/ray_res_inf.c\
					utilities/ray_res_new.c\
					utilities/swap_double.c\
					vec/matrix/matrix_multi.c\
					vec/matrix/matrix_new.c\
					vec/matrix/matrix_prod.c\
					vec/matrix/normal_matrix.c\
					vec/normal/adjust_normal.c\
					vec/normal/norm_cy.c\
					vec/normal/norm_ds.c\
					vec/normal/norm_pl.c\
					vec/normal/norm_sp.c\
					vec/normal/norm_tr.c\
					vec/normal/normal.c\
					vec/quaternions/cam_rot.c\
					vec/quaternions/quat_conj.c\
					vec/quaternions/quat_local_rot.c\
					vec/quaternions/quat_multi.c\
					vec/quaternions/quat_new.c\
					vec/quaternions/quat_norm.c\
					vec/quaternions/quat_to_matrix.c\
					vec/get_pixel.c\
					vec/multi_vec_matrix.c\
					vec/vec_a_to_b.c\
					vec/vec_add.c\
					vec/vec_cross_prod.c\
					vec/vec_dist.c\
					vec/vec_div_scalar.c\
					vec/vec_dot_prod.c\
					vec/vec_len.c\
					vec/vec_multi.c\
					vec/vec_new.c\
					vec/vec_normalize.c\
					vec/vec_prod.c\
					vec/vec_sqr.c\
					vec/vec_sub.c
BONUS_SRCS		=	mlx/render_thread.c\
					mlx/thread_new.c
CFILES			=	$(SRCS:%=src/%)
BONUS_CFILES	=	$(BONUS_SRCS:%=src/%)
OFILES			=	$(CFILES:.c=.o)
BONUS_OFILES	=	$(BONUS_CFILES:.c=.o)
FLAGS			=	-Wall -Wextra -Werror -DNOLIST -g -Og
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

TARGETS = $(OFILES)


ifeq ($(BONUS),1)

# GREYSCALE
ifdef GREY
FLAGS += -DGREY=true
endif

# MULTITHREADING
FLAGS += -DTHREADS=$(shell sysctl -n hw.ncpu) -DBONUS
TARGETS += $(BONUS_OFILES)
endif


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

$(NAME): $(TARGETS)
	@echo "$(WHITE)/-----		Compiling mlx		-----\\ $(RESET)"
	make -C $(MLX_LOC)
	cp $(MLX_LOC)/libmlx.dylib .
	@echo "$(WHITE)/-----		Compiling libft		-----\\ $(RESET)"
	make bonus -j6 -C $(LIBFT_LOC)
	@echo "$(WHITE)/-----		Compiling liblist	-----\\ $(RESET)"
	make -j6 -C $(LIBLIST_LOC)
	@echo "$(WHITE)/-----		Compiling miniRT	-----\\ $(RESET)"
	$(CC) $(LIBS) $(FRAMEWORK) -o $@ $^

%.o: %.c
	$(CC) -c $(FLAGS) $(INCLUDES) -o $@ $<
	
clean:
	@echo "$(WHITE)/-----		Cleaning mlx		-----\\ $(RESET)"
	make -j6 clean -C $(MLX_LOC)
	@-rm libmlx.dylib
	@echo "$(WHITE)/-----		Cleaning libft		-----\\ $(RESET)"
	make -j6 clean -C $(LIBFT_LOC)
	@echo "$(WHITE)/-----		Cleaning liblist	-----\\ $(RESET)"
	make -j6 clean -C $(LIBLIST_LOC)
	@echo "$(WHITE)/-----		Cleaning miniRT		-----\\ $(RESET)"
	rm -f scene.bmp
	rm -f $(TARGETS)

fclean: clean
	@echo "$(WHITE)/-----		Fcleaning libft		-----\\ $(RESET)"
	make -j6 fclean -C $(LIBFT_LOC)
	@echo "$(WHITE)/-----		Fcleaning liblist	-----\\ $(RESET)"
	make -j6 fclean -C $(LIBLIST_LOC)
	@echo "$(WHITE)/-----		Fcleaning miniRT	-----\\ $(RESET)"
	rm -f $(NAME)
	rm -f bonus

sanic:
	make bonusre
bonus:
	rm -f $(NAME)
	@echo "$(WHITE)/-----		Linking bonus		-----\\ $(RESET)"
	@BONUS=1 make $(NAME)
	@touch bonus

bonusre: fclean bonus

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
